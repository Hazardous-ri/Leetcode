class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size(), ans = 0, start = 0;

        for (int i = 0; i < n; i++) {
            for (int d = 0; d < 2; d++) {
                int l = i, r = i + d;
                while (l >= 0 && r < n && s[l] == s[r]) {
                    if (l >= start && r - l + 1 >= k) {
                        ans++;
                        start = r + 1;
                        break;            // must break the WHILE
                    }
                    l--;
                    r++;
                }
            }
        }
        return ans;
    }
};