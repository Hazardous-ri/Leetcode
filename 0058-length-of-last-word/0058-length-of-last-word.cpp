class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int z = n - 1;
        while (z >= 0 && s[z] == ' ') {
            z--;
        }
        int cnt = 0;
        while (z >= 0 && s[z] != ' ') {
            cnt++;
            z--;
        }
        return cnt;
    }
};