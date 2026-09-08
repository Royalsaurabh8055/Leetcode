class Solution {
public:
    const int MOD = 1e9 + 7;

    int factorial(int n) {
        long long ans = 1;

        for (int i = 2; i <= n; i++) {
            ans = (ans * i) % MOD;
        }

        return ans;
    }

    int numPrimeArrangements(int n) {

        // Find prime numbers
        vector<bool> prime(n + 1, true);

        prime[0] = false;

        if (n >= 1)
            prime[1] = false;

        int primeCount = 0;

        for (int i = 2; i <= n; i++) {

            if (prime[i]) {

                primeCount++;

                // Mark multiples as non-prime
                for (int j = i + i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }

        int nonPrimeCount = n - primeCount;

        long long primeWays = factorial(primeCount);
        long long nonPrimeWays = factorial(nonPrimeCount);

        return (primeWays * nonPrimeWays) % MOD;
    }
};