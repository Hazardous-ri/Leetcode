class Solution {
public:
    bool checkDivisibility(int n) {

        int t = n;
        int y = 0;
        int sum = 0;
        int product = 1;

        while (n > 0) {

            y = n % 10;

            sum = sum + y;
            product = product * y;

            n = n / 10;
        }

        if (t % (sum+product)==0) {
            return true;
        }
        else {
            return false;
        }
    }
};