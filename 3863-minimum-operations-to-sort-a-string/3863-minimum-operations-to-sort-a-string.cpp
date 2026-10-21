class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string t = s;
        sort(t.begin(), t.end());

        if (s == t) return 0;
        if (n == 2) return -1;

        char mn = t[0], mx = t[n - 1];

        // Sort everything except the first (or last) char, which is already in place.
        if (s[0] == mn || s[n - 1] == mx) return 1;

        // Min is somewhere before the last index, or max is somewhere after index 0.
        if (s.find(mn) < (size_t)(n - 1) || s.rfind(mx) > 0) return 2;

        // Min only at the end and max only at the start (e.g. "cba").
        return 3;
    }
};