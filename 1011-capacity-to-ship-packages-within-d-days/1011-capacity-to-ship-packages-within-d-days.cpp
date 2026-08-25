class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0;
        int high = 0;

        for (int w : weights) {
            low = max(low, w);
            high += w;
        }

        while (low < high) {
            int mid = low + (high - low) / 2;

            int currentSum = 0;
            int requiredDays = 1;

            for (int w : weights) {
                if (currentSum + w > mid) {
                    requiredDays++;
                    currentSum = 0;
                }

                currentSum += w;
            }

            if (requiredDays <= days) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};