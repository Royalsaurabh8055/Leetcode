class UnionFind {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

    int find(int x) {
        if (!parent.count(x))
            parent[x] = x;

        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return;

        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Solution {
public:
    int countComponents(vector<int>& nums, int threshold) {

        UnionFind uf;

        for (int num : nums) {
            for (int multiple = 2 * num; multiple <= threshold; multiple += num) {
                uf.Union(num, multiple);
            }
        }

        unordered_set<int> components;

        for (int num : nums)
            components.insert(uf.find(num));

        return components.size();
    }
};