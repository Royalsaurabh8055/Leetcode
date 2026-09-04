class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<bool> visited(n, false);

        int provinces = 0;

        for (int i = 0; i < n; i++) {

            // If city is not visited,
            // it means we found a new province
            if (!visited[i]) {

                provinces++;

                queue<int> q;

                q.push(i);
                visited[i] = true;

                while (!q.empty()) {

                    int city = q.front();
                    q.pop();

                    // Check all cities connected to current city
                    for (int j = 0; j < n; j++) {

                        if (isConnected[city][j] == 1 &&
                            !visited[j]) {

                            visited[j] = true;
                            q.push(j);
                        }
                    }
                }
            }
        }

        return provinces;
    }
};