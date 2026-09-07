class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {

        long long ans = 0;

        // Try every possible number of pens
        for (int pens = 0; pens <= total / cost1; pens++) {

            // Money left after buying pens
            int remaining = total - pens * cost1;

            // Maximum pencils we can buy
            int pencils = remaining / cost2;

            // We can buy 0, 1, 2, ..., pencils
            ans += pencils + 1;
        }

        return ans;
    }
};