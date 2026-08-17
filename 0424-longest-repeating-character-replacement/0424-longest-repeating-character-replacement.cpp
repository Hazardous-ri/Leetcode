class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.length();

        vector<int> freq(26, 0);

        int left = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            freq[s[right] - 'A']++;

            
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            
            int windowLength = right - left + 1;
            int changes = windowLength - maxFreq;

            
            while (changes > k) {

                freq[s[left] - 'A']--;

                left++;

                windowLength = right - left + 1;
                changes = windowLength - maxFreq;
            }

            
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};