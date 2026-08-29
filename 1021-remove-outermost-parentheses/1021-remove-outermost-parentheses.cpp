class Solution {
public:
    string removeOuterParentheses(string s) {
        
        stack<char> st;
        string ans;
        int start = 0;

        for (int i = 0; i < s.size(); i++) {
            
            if (s[i] == '(') {
                st.push(s[i]);
            }
            else {
                st.pop();
            }

            if (st.empty()) {
                
                for (int j = start + 1; j < i; j++) {
                    ans += s[j];
                }
                
                start = i + 1;
            }
        }

        return ans;
    }
};