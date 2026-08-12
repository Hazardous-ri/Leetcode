class Solution {
public:
    string frequencySort(string s) {
        
        
        vector<pair<char, int>> freq(256);

        
        for (char ch : s) {
            freq[ch].first = ch;
            freq[ch].second++;
        }

        
        sort(freq.begin(), freq.end(), [](pair<char, int>& a, pair<char, int>& b) {
            return a.second > b.second;
        });

        string ans = "";

     
        for (int i = 0; i < 256; i++) {
            char ch = freq[i].first;
            int count = freq[i].second;

            for (int j = 0; j < count; j++) {
                ans += ch;
            }
        }

        return ans;
    }
};