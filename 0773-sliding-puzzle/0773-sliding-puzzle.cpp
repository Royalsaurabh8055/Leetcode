class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {

        string start = "";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                start += char(board[i][j] + '0');
            }
        }

        string target = "123450";

        // Possible positions where zero can move
        vector<vector<int>> adj = {
            {1, 3},
            {0, 2, 4},
            {1, 5},
            {0, 4},
            {1, 3, 5},
            {2, 4}
        };

        queue<string> q;
        unordered_set<string> visited;

        q.push(start);
        visited.insert(start);

        int steps = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {
                string curr = q.front();
                q.pop();

                if (curr == target)
                    return steps;

                int zero = curr.find('0');

                for (int next : adj[zero]) {

                    string temp = curr;
                    swap(temp[zero], temp[next]);

                    if (!visited.count(temp)) {
                        visited.insert(temp);
                        q.push(temp);
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};