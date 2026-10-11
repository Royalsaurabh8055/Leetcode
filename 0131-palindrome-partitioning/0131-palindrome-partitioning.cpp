class Solution {
public:
    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    void solve(string& s, int index,
               vector<string>& current,
               vector<vector<string>>& ans) {

        // Entire string is partitioned
        if (index == s.size()) {
            ans.push_back(current);
            return;
        }

        // Try every possible substring
        for (int end = index; end < s.size(); end++) {

            // Take s[index...end] only if palindrome
            if (isPalindrome(s, index, end)) {

                current.push_back(s.substr(index, end - index + 1));

                solve(s, end + 1, current, ans);

                // Backtrack
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> current;

        solve(s, 0, current, ans);

        return ans;
    }
};