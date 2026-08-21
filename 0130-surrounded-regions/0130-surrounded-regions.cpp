class Solution {
public:

    void dfs(vector<vector<char>>& board, int r, int c) {

        int m = board.size();
        int n = board[0].size();

        // Out of bounds or not an O
        if (r < 0 || r >= m || c < 0 || c >= n ||
            board[r][c] != 'O')
            return;

        // Mark safe O
        board[r][c] = '#';

        dfs(board, r - 1, c); // up
        dfs(board, r + 1, c); // down
        dfs(board, r, c - 1); // left
        dfs(board, r, c + 1); // right
    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        // 1. DFS from boundary O's

        for (int i = 0; i < m; i++) {
            dfs(board, i, 0);       // left boundary
            dfs(board, i, n - 1);   // right boundary
        }

        for (int j = 0; j < n; j++) {
            dfs(board, 0, j);       // top boundary
            dfs(board, m - 1, j);   // bottom boundary
        }

        // 2. Convert surrounded O -> X
        //    Convert safe # -> O

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'O')
                    board[i][j] = 'X';

                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};