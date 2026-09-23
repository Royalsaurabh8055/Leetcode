class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<unordered_set<char>> row(9);
        vector<unordered_set<char>> col(9);
        vector<unordered_set<char>> box(9);

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {

                if(board[i][j] == '.')
                    continue;

                char ch = board[i][j];

                // Find which 3x3 box this cell belongs to
                int boxIndex = (i / 3) * 3 + (j / 3);

                // Already present?
                if(row[i].count(ch) ||
                   col[j].count(ch) ||
                   box[boxIndex].count(ch)) {
                    return false;
                }

                // Store it
                row[i].insert(ch);
                col[j].insert(ch);
                box[boxIndex].insert(ch);
            }
        }

        return true;
    }
};