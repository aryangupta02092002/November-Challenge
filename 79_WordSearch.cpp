#include<iostream>
#include<vector>
using namespace std;

class Sol {
public:
    vector<vector<int>> findGrid(char c, vector<vector<char>>& board) {
        vector<vector<int>> startGrids;
        vector<int> gridCoords = {-1, -1};
        int numRows = board.size();
        int numCols = board[0].size();
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (board[i][j] == c) {
                    gridCoords[0] = i;
                    gridCoords[1] = j;
                    startGrids.push_back(gridCoords);
                }
            }
        }
        return startGrids;
    }
    bool helper(vector<vector<char>>& board, int r, int c, string word) {
        int numRows = board.size();
        int numCols = board[0].size();
        if (word == "") {
            return true;
        }
        if (board[r][c] == word[0]) {
            char temp = board[r][c];
            board[r][c] = '#';
            // check its adjacent grids
            if (r + 1 < numRows) {
                if(helper(board, r + 1, c, word.substr(1))) {
                    return true;
                }
            }
            if (r - 1 >= 0) {
                if (helper(board, r - 1, c, word.substr(1))) {
                    return true;
                }
            }
            if (c + 1 < numCols) {
                if (helper(board, r, c + 1, word.substr(1))) {
                    return true;
                }
            }
            if (c - 1 >= 0) {
                if (helper(board, r, c - 1, word.substr(1))) {
                    return true;
                }
            }
            board[r][c] = temp;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int numRows = board.size();
        int numCols = board[0].size();
        if (numRows == 1 && numCols == 1) {
            return (word.length() == 1 && board[0][0] == word[0]);
        }
        // find starting character
        vector<vector<int>> startGrids = findGrid(word[0], board);
        for (vector<int> grid : startGrids) {
            int row = grid[0];
            int col = grid[1];
            if (helper(board, row, col, word)) {
                return true;
            }
        }
        return false;
    }
};

int main(){
    string word;
    cout<<"Enter the word: "<<endl;
    getline(cin, word);
    int row, col;
    cout<<"Enter row and column: "<<endl;
    cin>>row>>col;
    vector<vector<char>> board(row, vector<char>(col));

    for(int i=0; i<row; i++){
        vector<char> tmp;
        for (int j=0; j<col; j++){
            char ch;    cin>>ch;
            tmp.push_back(ch);
        }
        board.push_back(tmp);
    }

    Sol s;
    bool ans = s.exist(board, word);
    cout<<ans;
}