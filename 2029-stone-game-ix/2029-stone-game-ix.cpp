class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {


        int cnt[3] = {0};

        for (int x : stones) {
            cnt[x % 3]++;
        }

        int count0 = cnt[0];
        int count1 = cnt[1];
        int count2 = cnt[2];

       
        if (count1 == 0 && count2 == 0) {
            return false;
        }


        if (count1 == 0 || count2 == 0) {

            int bigger = max(count1, count2);

            if (count0 % 2 == 1) {
                return bigger > 2;
            } 
            else {
                return false;
            }
        }
        if (abs(count1 - count2) > 2) {
            return true;
        }

        return count0 % 2 == 0;
    }
};