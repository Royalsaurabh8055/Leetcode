class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;

        for (auto& b : buildings) {
            // Start event: height is negative
            events.push_back({b[0], -b[2]});

            // End event: height is positive
            events.push_back({b[1], b[2]});
        }

        sort(events.begin(), events.end());

        multiset<int> heights;
        heights.insert(0);

        vector<vector<int>> ans;
        int prevMax = 0;

        for (auto& event : events) {
            int x = event.first;
            int h = event.second;

            if (h < 0) {
                // Building starts
                heights.insert(-h);
            } else {
                // Building ends
                heights.erase(heights.find(h));
            }

            int currMax = *heights.rbegin();

            if (currMax != prevMax) {
                ans.push_back({x, currMax});
                prevMax = currMax;
            }
        }

        return ans;
    }
};