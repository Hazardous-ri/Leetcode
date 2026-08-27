class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        int freq[26] = {};

        for (char c : s) {
            freq[c - 'a']++;
        }

        int candidatePos = -1;
        int candidateChar = -1;
        int savedFreq[26];

        for (int i = 0; i < n; i++) {

            int current = target[i] - 'a';

            for (int c = current + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    candidatePos = i;
                    candidateChar = c;

                    for (int j = 0; j < 26; j++) {
                        savedFreq[j] = freq[j];
                    }

                    break;
                }
            }

            if (freq[current] > 0) {
                freq[current]--;
            } else {
                break;
            }
        }

        if (candidatePos == -1) {
            return "";
        }

        string ans = target.substr(0, candidatePos);

        ans += char('a' + candidateChar);

        savedFreq[candidateChar]--;

        for (int c = 0; c < 26; c++) {
            while (savedFreq[c] > 0) {
                ans += char('a' + c);
                savedFreq[c]--;
            }
        }

        return ans;
    }
};