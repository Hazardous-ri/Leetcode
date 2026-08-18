class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if (k == n)
            return *max_element(nums.begin(), nums.end());

        if (k == 1) {
            unordered_map<int,int> freq;

            for (int x : nums)
                freq[x]++;

            int ans = -1;

            for (auto it : freq) {
                if (it.second == 1)
                    ans = max(ans, it.first);
            }

            return ans;
        }

        int first = nums[0], last = nums[n - 1];
        int firstCount = 0, lastCount = 0;

        for (int start = 0; start <= n - k; start++) {
            bool foundFirst = false, foundLast = false;

            for (int j = start; j < start + k; j++) {
                if (nums[j] == first) foundFirst = true;
                if (nums[j] == last) foundLast = true;
            }

            if (foundFirst) firstCount++;
            if (foundLast) lastCount++;
        }

        int ans = -1;

        if (firstCount == 1)
            ans = first;

        if (lastCount == 1)
            ans = max(ans, last);

        return ans;
    }
};