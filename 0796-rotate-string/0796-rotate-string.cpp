class Solution {
public:
    bool rotateString(string s, string goal) {

        if (s.length() != goal.length()) {
            return false;
        }

        for (int count = 0; count < s.size(); count++) {

            if (s == goal) {
                return true;
            }

            char first = s[0];

            for (int i = 0; i < s.size() - 1; i++) {
                s[i] = s[i + 1];
            }

            s[s.size() - 1] = first;
        }

        return false;
    }
};