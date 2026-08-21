class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes,
                               vector<int>& bobSizes) {

        int sumA = 0, sumB = 0;

        for (int x : aliceSizes)
            sumA += x;

        for (int x : bobSizes)
            sumB += x;

        // a - b = (sumA - sumB) / 2
        int diff = (sumA - sumB) / 2;

        unordered_set<int> bobSet(bobSizes.begin(), bobSizes.end());

        for (int a : aliceSizes) {

            int b = a - diff;

            if (bobSet.count(b)) {
                return {a, b};
            }
        }

        return {};
    }
};