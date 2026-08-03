class Fancy {
public:
    static const int MOD = 1e9 + 7;

    vector<long long> nums;
    long long mul = 1;
    long long add = 0;

    long long power(long long a, long long b) {
        long long res = 1;

        while (b) {
            if (b & 1)
                res = (res * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return res;
    }

    long long modInverse(long long x) {
        return power(x, MOD - 2);
    }

    Fancy() {}

    void append(int val) {

        long long x = (val - add + MOD) % MOD;
        x = (x * modInverse(mul)) % MOD;

        nums.push_back(x);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {

        if (idx >= nums.size())
            return -1;

        return (nums[idx] * mul + add) % MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */