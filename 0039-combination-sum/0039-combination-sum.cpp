
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;

    void solve(vector<int>& candidates, int target, int index) {

        // Base case: target achieved
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        // Base case: no candidates left
        if (index == candidates.size()) {
            return;
        }

        // Choice 1: Take the current candidate
        if (candidates[index] <= target) {
            current.push_back(candidates[index]);

            solve(candidates, target - candidates[index], index);

            // Backtrack: remove the last chosen number
            current.pop_back();
        }

        // Choice 2: Skip the current candidate
        solve(candidates, target, index + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        solve(candidates, target, 0);

        return ans;
    }
};
