class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int n = nums.size();

        int totalXor = 0;

        for (int num : nums) {
            totalXor ^= num;
        }

        
        
        if (totalXor != 0) {
            return n;
        }

        
        for (int num : nums) {
            if (num != 0) {
                return n - 1;
            }
        }

        
        return 0;
    }
};