class Solution {
public:
    int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }

    bool hasGroupsSizeX(vector<int>& deck) {

        unordered_map<int,int> mp;

        // Count frequency
        for(int card : deck) {
            mp[card]++;
        }

        int g = 0;

        // Find GCD of all frequencies
        for(auto it : mp) {
            g = gcd(g, it.second);
        }

        return g >= 2;
    }
};