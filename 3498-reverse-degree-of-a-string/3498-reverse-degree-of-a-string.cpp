class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;

        for(int i = 0; i < s.length(); i++) {
            int x = s[i] - 'a' + 1;
            int rev = 27 - x;
            ans += rev * (i + 1);
        }

        return ans;
    }
};