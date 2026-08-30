class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }

            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        int first = min(minIndex, maxIndex);
        int second = max(minIndex, maxIndex);

        int front = second + 1;
        int back = n - first;
        int both = (first + 1) + (n - second);

        return min({front, back, both});
    }
};