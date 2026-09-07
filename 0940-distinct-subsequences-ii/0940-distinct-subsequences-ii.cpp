class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1000000007;

        int n = s.length();

        vector<long long> dp(n + 1, 0);
        vector<int> last(26, -1);

        dp[0] = 1;

        for(int i = 1; i <= n; i++) {
            int x = s[i-1] - 'a';

            dp[i] = 2 * dp[i-1];

            if(last[x] != -1) {
                dp[i] -= dp[last[x] - 1];
            }

            dp[i] %= MOD;

            if(dp[i] < 0) {
                dp[i] += MOD;
            }

            last[x] = i;
        }

        return (dp[n] - 1 + MOD) % MOD;
    }
};