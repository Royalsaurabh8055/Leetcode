class Solution {
public:
    int uniqueLetterString(string s) {

        int n = s.size();

        // Store positions of every character
        vector<vector<int>> pos(26);

        for (int i = 0; i < n; i++) {
            pos[s[i] - 'A'].push_back(i);
        }

        int ans = 0;

        // Process every character
        for (int i = 0; i < 26; i++) {

            // Add boundary positions
            pos[i].insert(pos[i].begin(), -1);
            pos[i].push_back(n);

            // Look at every occurrence
            for (int j = 1; j < pos[i].size() - 1; j++) {

                int left = pos[i][j - 1];
                int curr = pos[i][j];
                int right = pos[i][j + 1];

                // Number of choices for left boundary
                int leftChoices = curr - left;

                // Number of choices for right boundary
                int rightChoices = right - curr;

                ans += leftChoices * rightChoices;
            }
        }

        return ans;
    }
};