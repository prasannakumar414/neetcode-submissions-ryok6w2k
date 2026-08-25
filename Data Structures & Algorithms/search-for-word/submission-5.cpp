class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int s = board.size();
        int y = board[0].size();
        for(int r = 0 ;r<s;r++) {
            for (int c = 0;c<y;c++) {
                map<pair<int,int>, bool> visited;
                if(helperExist(board, word, 0, r, c, visited)){
                    return true;
                }
            }
        }
        return false;
    }

    bool helperExist(vector<vector<char>>& board, string targetWord, int targetIndex, int currRow, int currCol,map<pair<int,int>,bool> visited) {
        if (targetIndex == targetWord.length()) {
            return true;
        }
        if (currRow < 0 || currRow >= board.size()) {
            return false;
        }
        if (currCol < 0 || currCol >= board[0].size()) {
            return false;
        }
        if(visited[{currRow, currCol}]) {
            return false;
        }
        visited[{currRow, currCol}] = true;
        if (board[currRow][currCol] == targetWord[targetIndex]) {
            return helperExist(board, targetWord, targetIndex + 1, currRow - 1, currCol, visited) ||
            helperExist(board, targetWord, targetIndex + 1, currRow + 1, currCol, visited) ||
            helperExist(board, targetWord, targetIndex + 1, currRow, currCol - 1, visited) ||
            helperExist(board, targetWord, targetIndex + 1, currRow, currCol + 1, visited);
        }
        return false;
    }
};
