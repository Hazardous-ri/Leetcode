class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        vector<int> freq(k, 0);

    
        freq[0] = 1;

        int prefix = 0;
        int count = 0;

        for (int num : nums) {
            prefix += num;
            int rem = (prefix % k + k) % k;
            count += freq[rem]; 
            freq[rem]++;
        }

        return count;
    }
};