class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = 1;

        while (true) {
            int multiple = k * n;
            bool found = false;
            for (int x : nums) {
                if (x == multiple) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return multiple;
            }

            n++;
        }
    }
};