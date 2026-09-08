class Solution {
public:
    vector<string> answer;
    string letters[10] = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    void solve(string digits, int index, string ans) {
        if(index == digits.length()) {
            answer.push_back(ans);
            return;
        }

        int x = digits[index] - '0';

        for(int i=0; i<letters[x].length(); i++) {
            ans.push_back(letters[x][i]);
            solve(digits, index + 1, ans);
            ans.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        solve(digits, 0, "");
        return answer;
    }
};