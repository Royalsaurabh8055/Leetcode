class Solution {
public:

    int gcd(int a, int b) {

        while(b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }

    int findGCD(vector<int>& nums) {

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int x : nums) {
            mini = min(mini, x);
            maxi = max(maxi, x);
        }

        return gcd(mini, maxi);
    }
};