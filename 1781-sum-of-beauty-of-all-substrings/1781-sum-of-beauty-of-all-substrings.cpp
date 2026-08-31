class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;

            for (int j = i; j < n; j++) {
                freq[s[j]]++;

                int maxi = 0;
                int mini = INT_MAX;

                for (auto x : freq) {
                    maxi = max(maxi, x.second);
                    mini = min(mini, x.second);
                }

                ans += maxi - mini;
            }
        }

        return ans;
    }
};