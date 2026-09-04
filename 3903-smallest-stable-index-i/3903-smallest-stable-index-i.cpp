class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
         int n = nums.size();
         int maxi = 0 ;
         
         for (int i = 0 ; i< n ; i ++){
               maxi = max(maxi , nums[i]) ;
               int mini = nums[i];
              for(int  j =  i+1 ; j < n ; j ++){
                  if(nums[j]<mini){
                    mini = min (mini,nums[j]);
                  }
              } if ( (maxi - mini )<= k ){
                return i ;
              }
              


         }
         return -1 ;
    }
};