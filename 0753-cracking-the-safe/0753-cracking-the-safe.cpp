class Solution {
public:
    string ans;
    unordered_set<string> visited;

    int n, k;

    void dfs(string node) {

        for (int digit = 0; digit < k; digit++) {

            char ch = '0' + digit;

            // Current node + new digit
            string next = node + ch;

            // This n-digit combination
            if (visited.find(next) != visited.end())
                continue;

            // Mark this combination as used
            visited.insert(next);

            // Keep last n-1 characters
            string newNode = next.substr(1);

            dfs(newNode);

            // Add while returning from recursion
            ans += ch;
        }
    }

    string crackSafe(int n, int k) {

        this->n = n;
        this->k = k;

        string start(n - 1, '0');

        dfs(start);

        ans += start;

        return ans;
    }
};