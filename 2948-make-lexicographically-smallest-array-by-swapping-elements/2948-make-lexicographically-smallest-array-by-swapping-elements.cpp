class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        vector<pair<int, int>> arr;

        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        int start = 0;

        while (start < nums.size()) {

            int end = start;

            while (end + 1 < nums.size() &&
                   arr[end + 1].first - arr[end].first <= limit) {
                end++;
            }

            vector<int> values;
            vector<int> indices;

            for (int i = start; i <= end; i++) {
                values.push_back(arr[i].first);
                indices.push_back(arr[i].second);
            }

            sort(indices.begin(), indices.end());

            for (int i = 0; i < values.size(); i++) {
                nums[indices[i]] = values[i];
            }

            start = end + 1;
        }

        return nums;
    }
};