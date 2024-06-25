class Solution {
public:

    bool search(vector<vector<char>>& board, string & word, int n, int m, int row, int col, int index){
        if(index == word.size())return true;
        
        if(row<0 || col<0 || row>=n || col>=m || board[row][col] != word[index])return false;

        char temp = board[row][col];
        board[row][col] = '.';
        bool result = search(board, word, n, m, row+1, col, index+1) ||
                      search(board, word, n, m, row-1, col, index+1) ||
                      search(board, word, n, m, row, col+1, index+1) ||
                      search(board, word, n, m, row, col-1, index+1);
        
        board[row][col] = temp;
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(search(board, word, n, m, i, j, 0))return true;
            }
        }

        return false;
    }
};