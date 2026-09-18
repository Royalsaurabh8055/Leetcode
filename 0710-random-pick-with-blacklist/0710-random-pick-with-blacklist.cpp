class Solution {
public:
    unordered_map<int, int> mp;
    int size;

    Solution(int n, vector<int>& blacklist) {

        size = n - blacklist.size();

        unordered_set<int> black;

        for(int x : blacklist) {
            black.insert(x);
        }

        int last = n - 1;

        for(int x : blacklist) {

            // Only blacklist numbers inside [0, size-1]
            if(x < size) {

                // Find an allowed number from the end
                while(black.count(last)) {
                    last--;
                }

                mp[x] = last;
                last--;
            }
        }
    }

    int pick() {

        int x = rand() % size;

        if(mp.find(x) != mp.end()) {
            return mp[x];
        }

        return x;
    }
};