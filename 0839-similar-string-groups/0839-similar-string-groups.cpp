class Solution {
public:

    // Check whether two strings are similar
    bool isSimilar(string a, string b) {

        int diff = 0;

        for (int i = 0; i < a.size(); i++) {

            if (a[i] != b[i]) {
                diff++;
            }

            // More than 2 differences
            // cannot be fixed with one swap
            if (diff > 2) {
                return false;
            }
        }

        return true;
    }

    void dfs(int index, vector<string>& strs, vector<bool>& visited) {

        visited[index] = true;

        for (int i = 0; i < strs.size(); i++) {

            if (visited[i]) {
                continue;
            }

            if (isSimilar(strs[index], strs[i])) {

                dfs(i, strs, visited);
            }
        }
    }

    int numSimilarGroups(vector<string>& strs) {

        int n = strs.size();

        vector<bool> visited(n, false);

        int groups = 0;

        for (int i = 0; i < n; i++) {

            if (!visited[i]) {

                groups++;

                dfs(i, strs, visited);
            }
        }

        return groups;
    }
};