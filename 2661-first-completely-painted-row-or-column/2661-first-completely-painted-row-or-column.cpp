class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // position[value] = {row, col}
        unordered_map<int, pair<int,int>> position;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                position[mat[i][j]] = {i, j};
            }
        }

        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);

        for(int i = 0; i < arr.size(); i++) {

            int value = arr[i];

            int r = position[value].first;
            int c = position[value].second;

            rowCount[r]++;
            colCount[c]++;

            // Complete row or column
            if(rowCount[r] == n || colCount[c] == m) {
                return i;
            }
        }

        return -1;
    }
};