class Solution {
public:
    string longestPrefix(string s) {

        int n = s.size();

        vector<int> lps(n, 0);

        int len = 0;
        int i = 1;

        while (i < n) {

            // Characters match
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            }

            // Characters don't match
            else {

                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // Last LPS value gives
        // longest prefix which is also suffix
        int length = lps[n - 1];

        return s.substr(0, length);
    }
};