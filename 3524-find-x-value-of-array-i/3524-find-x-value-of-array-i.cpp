class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for(int i = 0; i < n; i++) {
            vector<long long> next(k, 0);

            int x = nums[i] % k;

            // Subarray containing only nums[i]
            next[x]++;

            // Extend previous subarrays
            for(int r = 0; r < k; r++) {
                int newR = (r * x) % k;
                next[newR] += dp[r];
            }

            dp = next;

            // Add all subarrays ending at i
            for(int r = 0; r < k; r++) {
                ans[r] += dp[r];
            }
        }

        return ans;
    }
};