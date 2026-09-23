class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {

        int n = matrix.size();

        // Check rows
        for(int i = 0; i < n; i++) {

            vector<int> freq(n + 1, 0);

            for(int j = 0; j < n; j++) {
                freq[matrix[i][j]]++;

                if(freq[matrix[i][j]] > 1)
                    return false;
            }
        }

        // Check columns
        for(int j = 0; j < n; j++) {

            vector<int> freq(n + 1, 0);

            for(int i = 0; i < n; i++) {
                freq[matrix[i][j]]++;

                if(freq[matrix[i][j]] > 1)
                    return false;
            }
        }

        return true;
    }
};