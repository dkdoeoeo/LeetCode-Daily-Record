
class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        unordered_map<string, int> strToID;
        int idCounter = 0;
        
        unordered_set<int> lengths; 

        for (const string& s : original) {
            if (strToID.find(s) == strToID.end()) strToID[s] = idCounter++;
            lengths.insert(s.length());
        }
        for (const string& s : changed) {
            if (strToID.find(s) == strToID.end()) strToID[s] = idCounter++;
        }

        int n = idCounter;
        long long INF = 1e14;
        vector<vector<long long>> dist(n, vector<long long>(n, INF));

        for (int i = 0; i < n; i++) dist[i][i] = 0;

        for (size_t i = 0; i < original.size(); i++) {
            int u = strToID[original[i]];
            int v = strToID[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                if (dist[i][k] == INF) continue;
                for (int j = 0; j < n; j++) {
                    if (dist[k][j] == INF) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int len = source.length();
        vector<long long> dp(len + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < len; i++) {
            if (dp[i] == INF) continue;

            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            for (int l : lengths) {
                if (i + l > len) continue;

                string subS = source.substr(i, l);
                string subT = target.substr(i, l);

                if (strToID.count(subS) && strToID.count(subT)) {
                    int u = strToID[subS];
                    int v = strToID[subT];

                    if (dist[u][v] != INF) {
                        dp[i + l] = min(dp[i + l], dp[i] + dist[u][v]);
                    }
                }
            }
        }

        return dp[len] == INF ? -1 : dp[len];
    }
};