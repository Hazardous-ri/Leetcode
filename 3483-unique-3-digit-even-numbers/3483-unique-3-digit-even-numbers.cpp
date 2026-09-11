class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> results;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue; 
                    int hundreds = digits[i];
                    int tens = digits[j];
                    int ones = digits[k];
                    if (hundreds == 0) continue;  
                    if (ones % 2 != 0) continue;      
                    int num = hundreds * 100 + tens * 10 + ones;
                    results.insert(num);
                }
            }
        }
        
        return results.size();
    }
};