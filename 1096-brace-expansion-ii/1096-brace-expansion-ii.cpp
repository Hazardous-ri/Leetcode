class Solution {
public:

    // Cartesian product / concatenation
    set<string> multiply(set<string>& a, set<string>& b) {

        set<string> result;

        for (string x : a) {
            for (string y : b) {
                result.insert(x + y);
            }
        }

        return result;
    }

    // Handles concatenation
    set<string> parseTerm(string& s, int& i) {

        set<string> result;
        result.insert("");

        while (i < s.size() && s[i] != '}' && s[i] != ',') {

            set<string> curr;

            if (s[i] == '{') {

                i++;  // skip {

                curr = parseExpression(s, i);

                i++;  // skip }

            }
            else {

                curr.insert(string(1, s[i]));
                i++;
            }

            result = multiply(result, curr);
        }

        return result;
    }

    // Handles UNION
    set<string> parseExpression(string& s, int& i) {

        set<string> result;

        while (i < s.size() && s[i] != '}') {

            // Parse one concatenated part
            set<string> curr = parseTerm(s, i);

            // UNION
            result.insert(curr.begin(), curr.end());

            if (i < s.size() && s[i] == ',') {
                i++;  // skip comma
            }
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> result = parseExpression(expression, i);

        return vector<string>(result.begin(), result.end());
    }
};