class Solution {
public:

    vector<vector<int>> dp;

    bool solve(int i, int j, string &s, string &p) {

        // If pattern is finished,
        // string must also be finished
        if (j == p.size()) {
            return i == s.size();
        }

        // If we already calculated this state
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Check whether current characters match
        bool firstMatch = (i < s.size() &&
                           (s[i] == p[j] || p[j] == '.'));

        // If next character in pattern is '*'
        if (j + 1 < p.size() && p[j + 1] == '*') {

            // Choice 1:
            // Ignore x*
            bool skip = solve(i, j + 2, s, p);

            // Choice 2:
            // Use x* to match one character
            bool take = firstMatch && solve(i + 1, j, s, p);

            return dp[i][j] = (skip || take);
        }

        // No '*'
        // Current characters must match
        // and then move both pointers
        return dp[i][j] = firstMatch &&
                          solve(i + 1, j + 1, s, p);
    }

    bool isMatch(string s, string p) {

        dp.assign(
            s.size() + 1,
            vector<int>(p.size() + 1, -1)
        );

        return solve(0, 0, s, p);
    }
};