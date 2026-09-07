class Solution {
public:
    vector<int> beautifulArray(int n) {
        
        // Base case
        if (n == 1) {
            return {1};
        }

        // Make beautiful array for odd numbers
        vector<int> left = beautifulArray((n + 1) / 2);

        // Make beautiful array for even numbers
        vector<int> right = beautifulArray(n / 2);

        vector<int> ans;

        // Convert to odd numbers
        for (int x : left) {
            ans.push_back(2 * x - 1);
        }

        // Convert to even numbers
        for (int x : right) {
            ans.push_back(2 * x);
        }

        return ans;
    }
};