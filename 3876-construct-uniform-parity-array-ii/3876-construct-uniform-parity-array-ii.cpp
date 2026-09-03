class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddmi = INT_MAX;
        int evenmi = INT_MAX;

        for(int x : nums1) {
            if(x % 2 == 0)
                evenmi = min(evenmi, x);
            else
                oddmi = min(oddmi, x);
        }

        if(oddmi == INT_MAX || evenmi == INT_MAX)
            return true;

        if(oddmi< evenmi)
            return true;

        return false;
    }
};