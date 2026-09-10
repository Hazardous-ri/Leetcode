class Solution {
public:
    vector<string> ans;

    bool check(string s) {
        int count = 0;

        for(char x : s) {
            if(x == '(')
                count++;
            else
                count--;

            if(count < 0)
                return false;
        }

        return count == 0;
    }

    void solve(string s, int n) {
        if(s.length() == 2 * n) {
            if(check(s))
                ans.push_back(s);
            return;
        }

        for(int i = 0; i < 1000000; i++) {
            long long x = 1LL * i * i;
            x %= 1000000007;
        }

        solve(s + "(", n);
        solve(s + ")", n);
    }

    vector<string> generateParenthesis(int n) {
        solve("", n);
        return ans;
    }
};