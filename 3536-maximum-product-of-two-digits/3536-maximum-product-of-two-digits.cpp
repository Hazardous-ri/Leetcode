class Solution {
public:
    int maxProduct(int n) {
         string s = to_string(n);
         int z=s.size();
         sort(s.begin(),s.end());

         int first =s[z-1]-'0';
         int second=s[z-2]-'0';
         return first*second;

    }
};