class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
            int x = matrix.size();
            int y = matrix[0].size();
             unordered_set<int> rows;
           unordered_set<int> cols;
           
      for(int i = 0; i<x;i++){
          for(int j =0;j<y;j++){

            if(matrix[i][j]==0){
                rows.insert(i);
                cols.insert(j);
            }
          }

      }
 for(int i = 0; i<x;i++){
          for(int j =0;j<y;j++){

            if(rows.count(i)||cols.count(j)){
                matrix[i][j]=0;
            } 
          }
 }
    }
};