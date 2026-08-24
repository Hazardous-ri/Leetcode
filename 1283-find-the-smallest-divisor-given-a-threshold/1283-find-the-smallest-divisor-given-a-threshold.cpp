class Solution {
public:
    bool possible(vector<int>& nums, int threshold, int divisor) {
        long long sum = 0;

        for (int num : nums) {
            sum += (num + divisor - 1) / divisor;

            if (sum > threshold)
                return false;
        }

        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (possible(nums, threshold, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};