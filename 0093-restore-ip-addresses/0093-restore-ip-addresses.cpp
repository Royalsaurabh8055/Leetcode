class Solution {
public:
    void solve(string& s, int index, int parts,
               string current, vector<string>& ans) {

        // Exactly 4 parts and all digits are used
        if (parts == 4) {
            if (index == s.size()) {
                current.pop_back(); // remove last '.'
                ans.push_back(current);
            }
            return;
        }

        // Try taking 1, 2, or 3 digits
        for (int len = 1; len <= 3; len++) {

            if (index + len > s.size())
                break;

            string part = s.substr(index, len);

            // Leading zero is not allowed
            if (len > 1 && part[0] == '0')
                continue;

            // Value must be <= 255
            if (stoi(part) > 255)
                continue;

            solve(s, index + len, parts + 1,
                  current + part + ".", ans);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;

        if (s.length() < 4 || s.length() > 12)
            return ans;

        solve(s, 0, 0, "", ans);

        return ans;
    }
};