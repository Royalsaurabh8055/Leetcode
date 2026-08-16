class Solution {
public:
    double soupServings(int n) {
        // Quantize by 25ml units
        int m = (n + 24) / 25; // ceil(n/25)
        
        if (m >= 200) return 1.0; // probability approaches 1 for large n
        
        vector<vector<double>> memo(m + 1, vector<double>(m + 1, -1.0));
        return dfs(m, m, memo);
    }
    
private:
    double dfs(int a, int b, vector<vector<double>>& memo) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        
        if (memo[a][b] != -1.0) return memo[a][b];
        
        double result = 0.25 * (
            dfs(max(a - 4, 0), b, memo) +
            dfs(max(a - 3, 0), max(b - 1, 0), memo) +
            dfs(max(a - 2, 0), max(b - 2, 0), memo) +
            dfs(max(a - 1, 0), max(b - 3, 0), memo)
        );
        
        memo[a][b] = result;
        return result;
    }
};