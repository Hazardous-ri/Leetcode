class Solution {
public:
    int longestPalindrome(string s) {

        unordered_map<char, int> freq;

        
        for(char c : s) {
            freq[c]++;
        }

        int ans = 0;
        bool hasOdd = false;

       
        for(auto it : freq) {

            if(it.second % 2 == 0) {
                ans += it.second;
            }
            else {
                ans += it.second - 1;
                hasOdd = true;
            }
        }

        
        if(hasOdd) {
            ans++;
        }

        return ans;
    }
};