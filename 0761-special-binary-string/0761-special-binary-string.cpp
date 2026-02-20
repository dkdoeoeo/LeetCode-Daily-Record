
class Solution {
public:
    string makeLargestSpecial(string s) {
        int count = 0;
        int start = 0; 
        vector<string> substrings;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                count++;
            } else {
                count--;
            }
            
            if (count == 0) {
                string inner = s.substr(start + 1, i - start - 1);
                
                string processed = "1" + makeLargestSpecial(inner) + "0";
                substrings.push_back(processed);
                
                start = i + 1;
            }
        }

        sort(substrings.begin(), substrings.end(), greater<string>());
        string result = "";
        for (int i = 0; i < substrings.size(); i++) {
            result += substrings[i];
        }

        return result;
    }
};