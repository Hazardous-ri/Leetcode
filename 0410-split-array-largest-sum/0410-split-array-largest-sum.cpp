class Solution {
public:

    int countPartitions(vector<int>& nums, int maxSum) {
        int partitions = 1;
        int currentSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (currentSum + nums[i] <= maxSum) {
                currentSum += nums[i];
            } else {
                partitions++;
                currentSum = nums[i];
            }
        }

        return partitions;
    }

    int splitArray(vector<int>& nums, int k) {

        int low = 0;
        int high = 0;

        for (int i = 0; i < nums.size(); i++) {
            low = max(low, nums[i]);
            high += nums[i];
        }

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int partitions = countPartitions(nums, mid);

            if (partitions > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};