long long minimumCost(char* source, char* target, char* original, int originalSize, char* changed, int changedSize, int* cost, int costSize) {
    long long INF = 1e15; 
    
    long long dist[26][26];
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for (int i = 0; i < originalSize; i++) {
        int u = original[i] - 'a';
        int v = changed[i] - 'a';
        if (cost[i] < dist[u][v]) {
            dist[u][v] = cost[i];
        }
    }

    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    long long totalCost = 0;
    int len = strlen(source);
    
    for (int i = 0; i < len; i++) {
        int u = source[i] - 'a';
        int v = target[i] - 'a';
        
        if (u == v) continue;
        
        if (dist[u][v] == INF) {
            return -1;
        }
        
        totalCost += dist[u][v];
    }

    return totalCost;
}