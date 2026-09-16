class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {

        long long area = 0;

        int minX = INT_MAX;
        int minY = INT_MAX;
        int maxX = INT_MIN;
        int maxY = INT_MIN;

        set<pair<int,int>> corners;

        for(auto r : rectangles) {

            int x1 = r[0];
            int y1 = r[1];
            int x2 = r[2];
            int y2 = r[3];

            // Total area of small rectangles
            area += (long long)(x2 - x1) * (y2 - y1);

            // Find big rectangle boundaries
            minX = min(minX, x1);
            minY = min(minY, y1);
            maxX = max(maxX, x2);
            maxY = max(maxY, y2);

            // Toggle all 4 corners
            vector<pair<int,int>> points = {
                {x1, y1},
                {x1, y2},
                {x2, y1},
                {x2, y2}
            };

            for(auto p : points) {

                if(corners.count(p))
                    corners.erase(p);
                else
                    corners.insert(p);
            }
        }

        // Area of the big rectangle
        long long bigArea =
            (long long)(maxX - minX) * (maxY - minY);

        // Area must match
        if(area != bigArea)
            return false;

        // Exactly 4 corners should remain
        if(corners.size() != 4)
            return false;

        // Those 4 corners must be the big rectangle's corners
        if(!corners.count({minX, minY}))
            return false;

        if(!corners.count({minX, maxY}))
            return false;

        if(!corners.count({maxX, minY}))
            return false;

        if(!corners.count({maxX, maxY}))
            return false;

        return true;
    }
};