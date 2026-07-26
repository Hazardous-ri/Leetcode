class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         int product1 = 0;
         int product2 = 0 ;
         int ans = 0 ;
         int n = nums.size();
      product1 = nums[n-3]*nums[n-2]*nums[n-1];
      product2 = nums[0]*nums[1]*nums[n-1];
       ans = max(product1 , product2);
       
   return ans; }
};