class Solution {
public:
    bool dfs(vector<vector<char>>& board, int currX, int currY, int dirX[4], int dirY[4], int currIdx, string word){
        if(currIdx == word.size()){
            return true;
        }

        bool isPossible = false, currPossibility;
        char currChar = board[currX][currY];
        int newX, newY;

        //visit curr cell
        board[currX][currY] = '$';

        for(int i = 0; i < 4; i++){
            newX = currX + dirX[i];
            newY = currY + dirY[i];

            if(newX < 0 || newX >= board.size() || newY < 0 || newY >= board[0].size() || board[newX][newY] == '$' || board[newX][newY] != word[currIdx]){
                continue;
            }

            currPossibility = dfs(board, newX, newY, dirX, dirY, currIdx + 1, word);
            isPossible |= currPossibility;
        }

        //backtrack
        board[currX][currY] = currChar;

        return isPossible;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int dirX[4] = {0, 0, 1, -1};
        int dirY[4] = {1, -1, 0, 0};
        int row, col;
        row = board.size();
        col = board[0].size();

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, i, j, dirX, dirY, 1, word)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};