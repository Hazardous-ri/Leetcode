class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size())
            return false;

        vector<int> a(26, 0), b(26, 0);

        for (char c : s1)
            a[c - 'a']++;

        int k = s1.size();

        
        for (int i = 0; i < k; i++)
            b[s2[i] - 'a']++;

        if (a == b)
            return true;

        
        for (int right = k; right < s2.size(); right++) {

            b[s2[right] - 'a']++;      
            b[s2[right - k] - 'a']--;   

            if (a == b)
                return true;
        }

        return false;
    }
};