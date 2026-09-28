class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        const long long MOD = 1e9 + 7;

        sort(inventory.rbegin(), inventory.rend());

        long long ans = 0;
        long long colors = 1;

        for (int i = 0; i < inventory.size() && orders > 0; i++, colors++) {

            int curr = inventory[i];
            int next = (i + 1 < inventory.size()) ? inventory[i + 1] : 0;

            long long diff = curr - next;

            // Number of balls we can sell while bringing
            // all 'colors' inventories down to 'next'
            long long canSell = diff * colors;

            if (canSell <= orders) {

                // Sell values:
                // curr, curr-1, ..., next+1
                long long sum = (long long)(curr + next + 1) * diff / 2;

                ans = (ans + sum * colors) % MOD;

                orders -= canSell;
            }
            else {

                // We cannot finish the whole level
                long long fullLevels = orders / colors;
                long long remaining = orders % colors;

                // Sell full levels:
                // curr, curr-1, ..., curr-fullLevels+1
                long long low = curr - fullLevels + 1;

                long long sum =
                    (long long)(curr + low) * fullLevels / 2;

                ans = (ans + sum * colors) % MOD;

                // Remaining balls are worth the next value
                ans = (ans + remaining * (curr - fullLevels)) % MOD;

                orders = 0;
            }
        }

        return ans;
    }
};