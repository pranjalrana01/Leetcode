class Solution {
public:
    // vector<int>generateRow(int row){
    //     long long ans = 1;
    //     vector<int>ansRow;
    //     ansRow.push_back(1);
    //     for(int col=1 ; col < row ; col++){
    //         ans = ans * (row-col);
    //         ans = ans/(col);
    //         ansRow.push_back(ans);
    //     }
    //     return ansRow;
    // }
    // vector<vector<int>> generate(int numRows) {
    //     vector<vector<int>>ans;
    //     for(int i=1 ; i<=numRows ; i++){
    //         ans.push_back(generateRow(i));
    //     }
    //     return ans;
    //   }


        //solution 2

        vector<vector<int>> generate(int numRows){
            vector<vector<int>>r(numRows);

            for(int i=0 ; i<numRows ; i++){
                r[i].resize(i+1);
                r[i][0] = r[i][i] = 1;

                for(int j=1 ; j<i ; j++){
                    r[i][j] = r[i-1][j-1] + r[i-1][j];
                }
            }
                return r;
            }
};