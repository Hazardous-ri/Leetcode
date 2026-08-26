class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        vector<int> answer;

        int num = 1;
        int i = 0;

        while (answer.size() < k) {

            if (i < arr.size() && arr[i] == num) {
                i++;
            }
            else {
                answer.push_back(num);
            }

            num++;
        }

        return answer[k - 1];
    }
};