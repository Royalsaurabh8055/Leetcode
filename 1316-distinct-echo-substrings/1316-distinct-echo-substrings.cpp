class Solution {
public:
    int distinctEchoSubstrings(string text) {

        int n = text.size();

        // Store distinct echo substrings
        unordered_set<string> st;

        // len = length of one half
        for (int len = 1; len <= n / 2; len++) {

            int same = 0;

            // Compare two parts:
            // text[i] and text[i + len]
            for (int i = 0, j = len; j < n; i++, j++) {

                if (text[i] == text[j]) {
                    same++;
                }
                else {
                    same = 0;
                }

                // We found len consecutive matching characters
                if (same == len) {

                    string half = text.substr(i - len + 1, len);

                    st.insert(half);

                    // Move window forward
                    same--;
                }
            }
        }

        return st.size();
    }
};