class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();

        sort(s.begin(), s.begin() + n / 2);

        if (n % 2 == 0)
            sort(s.begin() + n / 2, s.end(), greater<char>());
        else
            sort(s.begin() + n / 2 + 1, s.end(), greater<char>());

        return s;
    }
};