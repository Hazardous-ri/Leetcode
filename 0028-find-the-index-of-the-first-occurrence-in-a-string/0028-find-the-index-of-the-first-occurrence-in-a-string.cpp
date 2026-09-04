class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() > haystack.length()) {
            return -1;
        }
        for (int i = 0; i <= haystack.length() - needle.length(); i++) {
            if (haystack[i] == needle[0]) {
                int x = 0;
                while (x < needle.length() &&
                       haystack[i + x] == needle[x]) {
                    x++;
                }
                if (x == needle.length()) {
                    return i;
                }
            }
        }
        return -1;
    }
};