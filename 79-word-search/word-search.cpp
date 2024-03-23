class Solution {
public:
    bool search(vector<vector<char>>& board, const string& word, int index, int row, int col){
        if(index == word.size()) return true;

        int rows = board.size();
        int cols = board[0].size();

        if(row<0 || col<0 || row >= rows || col >= cols || board[row][col] != word[index]) return false;

        char temp = board[row][col];
        board[row][col] = '.';

        bool found = search(board, word, index+1, row+1,col) || 
                     search(board, word, index+1, row-1,col) ||
                     search(board, word, index+1, row,col+1) ||
                     search(board, word, index+1, row,col-1);

        board[row][col] = temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty() || word.empty()) return false;

        int rows = board.size();
        int cols = board[0].size();

        for(int i=0 ; i<rows ; ++i){
            for (int j=0 ; j<cols ; ++j){
                if(search(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
};