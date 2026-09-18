class Solution {
public:
    int distinctSubseqII(string s) {

        const long long MOD = 1000000007;

        // end[c] = number of distinct subsequences
        // ending with character c
        vector<long long> end(26, 0);

        long long total = 0;

        for(char ch : s) {

            int c = ch - 'a';

            // New subsequences formed by current character
            long long add = (total - end[c] + 1 + MOD) % MOD;

            // Add them to total
            total = (total + add) % MOD;

            // These new subsequences now end with ch
            end[c] = (end[c] + add) % MOD;
        }

        return total;
    }
};