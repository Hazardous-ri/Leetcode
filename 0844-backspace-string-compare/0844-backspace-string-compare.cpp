class Solution {
public:
    bool backspaceCompare(string s, string t) {

        string ansS = "";
        string ansT = "";

        
        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '#') {

                
                if (!ansS.empty()) {
                    ansS.pop_back();
                }

            } else {      
                ansS.push_back(s[i]);
            }
        }
        for (int i = 0; i < t.length(); i++) {

            if (t[i] == '#') {
                if (!ansT.empty()) {
                    ansT.pop_back();
                }

            } else {
                ansT.push_back(t[i]);
            }
        }

        
        if( ansS == ansT) return true;
        return false;
    }
};