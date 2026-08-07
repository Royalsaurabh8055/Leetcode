class Solution {
public:
    vector<string> cellsInRange(string s) {

        vector<string> ans;

        char startCol = s[0];
        char endCol = s[3];

        char startRow = s[1];
        char endRow = s[4];

        for (char col = startCol; col <= endCol; col++) {

            for (char row = startRow; row <= endRow; row++) {

                string cell = "";
                cell += col;
                cell += row;

                ans.push_back(cell);
            }
        }

        return ans;
    }
};