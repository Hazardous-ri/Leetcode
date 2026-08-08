class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {

            int current = left + (right - left) / 2;

            if (nums[current] > nums[current + 1]) {
                
                right = current;
            }
            else {
               
                left = current + 1;
            }
        }

        return left;
    }
};