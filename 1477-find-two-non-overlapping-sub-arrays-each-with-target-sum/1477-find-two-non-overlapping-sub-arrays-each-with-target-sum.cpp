class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> best(n, INT_MAX);

        int left = 0;
        long long sum = 0;
        int ans = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // Carry forward previous best
            if (right > 0)
                best[right] = best[right - 1];

            // Current window has target sum
            if (sum == target) {
                int len = right - left + 1;

                // Check for a previous non-overlapping subarray
                if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, len + best[left - 1]);
                }

                // Update best
                best[right] = min(best[right], len);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};