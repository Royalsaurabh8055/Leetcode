class Solution {
public:

    int m, n;
    int total;

    unordered_map<int, int> mp;

    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        total = m * n;
    }

    vector<int> flip() {

        // Pick a random index from remaining cells
        int x = rand() % total;

        // If x is already mapped, use mapped value
        // otherwise use x itself
        int index;

        if (mp.find(x) != mp.end())
            index = mp[x];
        else
            index = x;

        // Remove one available position
        total--;

        // Move the last available position to x
        if (mp.find(total) != mp.end())
            mp[x] = mp[total];
        else
            mp[x] = total;

        // Convert 1D index to 2D
        int row = index / n;
        int col = index % n;

        return {row, col};
    }

    void reset() {

        total = m * n;
        mp.clear();
    }
};