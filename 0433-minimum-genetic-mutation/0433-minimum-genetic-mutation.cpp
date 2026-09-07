class Solution {
public:
    int minMutation(string startGene, string endGene,
                    vector<string>& bank) {

        queue<pair<string, int>> q;

        q.push({startGene, 0});

        unordered_set<string> visited;
        visited.insert(startGene);

        while (!q.empty()) {

            string current = q.front().first;
            int steps = q.front().second;

            q.pop();

            // Reached target
            if (current == endGene) {
                return steps;
            }

            // Check every gene in bank
            for (string next : bank) {

                // Already visited
                if (visited.find(next) != visited.end()) {
                    continue;
                }

                // Count different characters
                int diff = 0;

                for (int i = 0; i < 8; i++) {

                    if (current[i] != next[i]) {
                        diff++;
                    }
                }

                // One mutation means exactly 1 difference
                if (diff == 1) {

                    visited.insert(next);

                    q.push({next, steps + 1});
                }
            }
        }

        return -1;
    }
};