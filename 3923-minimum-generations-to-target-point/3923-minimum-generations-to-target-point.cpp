class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        
        // Target already exists
        for (auto &p : points) {
            if (p == target)
                return 0;
        }

        // Only one point -> cannot create another point
        if (points.size() < 2)
            return -1;

        set<vector<int>> all;
        
        for (auto &p : points)
            all.insert(p);

        int generation = 0;

        while (true) {
            set<vector<int>> next;

            vector<vector<int>> current(all.begin(), all.end());

            for (int i = 0; i < current.size(); i++) {
                for (int j = i + 1; j < current.size(); j++) {

                    vector<int> p(3);

                    p[0] = (current[i][0] + current[j][0]) / 2;
                    p[1] = (current[i][1] + current[j][1]) / 2;
                    p[2] = (current[i][2] + current[j][2]) / 2;

                    // Target generated
                    if (p == target)
                        return generation + 1;

                    // Only keep genuinely new points
                    if (!all.count(p))
                        next.insert(p);
                }
            }

            // No new points -> impossible
            if (next.empty())
                return -1;

            for (auto &p : next)
                all.insert(p);

            generation++;
        }
    }
};