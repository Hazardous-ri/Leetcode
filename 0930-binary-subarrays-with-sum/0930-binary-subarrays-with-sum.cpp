class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

       
        unordered_map<int, int> freq;

        freq[0] = 1;

        int prefix = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {

           
            prefix += nums[i];

            
            int needed = prefix - goal;

           
            if (freq.find(needed) != freq.end()) {
                count += freq[needed];
            }

            freq[prefix]++;
        }

        return count;
    }
};