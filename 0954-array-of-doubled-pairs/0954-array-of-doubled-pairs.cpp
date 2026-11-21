class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> freq;

        for (int x : arr) {
            freq[x]++;
        }

        if (freq[0] % 2 != 0)
            return false;

        sort(arr.begin(), arr.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });

        for (int x : arr) {
            if (freq[x] == 0)
                continue;

            // Use long long to avoid integer overflow
            long long doubled = 2LL * x;

            if (doubled < INT_MIN || doubled > INT_MAX)
                return false;

            if (freq[(int)doubled] == 0)
                return false;

            freq[x]--;
            freq[(int)doubled]--;
        }

        return true;
    }
};