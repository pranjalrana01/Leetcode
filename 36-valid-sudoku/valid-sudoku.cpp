class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int num = 9;
        int row[num][num] = {false};
        int col[num][num] = {false};
        int subgrid[num][num] = {false};

        for(int r=0; r<num; ++r){
            for(int c=0; c<num; ++c){
                if(board[r][c] == '.')continue;
                int index = board[r][c] - '0'-1;

                int gridNum = (r/3) * 3 + (c/3);

                if(row[r][index] || col[c][index] || subgrid[gridNum][index]){
                    return false;
                }

                row[r][index] = true;
                col[c][index] = true;
                subgrid[gridNum][index] = true;            
            }
        }

        return true;
    }
};