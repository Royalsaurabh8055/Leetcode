class Solution {
public:

    bool canForm(string word, unordered_set<string>& st) {

        int n = word.length();

        vector<bool> dp(n + 1, false);

        dp[0] = true;

        for (int i = 1; i <= n; i++) {

            for (int j = 0; j < i; j++) {

                if (!dp[j])
                    continue;

                string part = word.substr(j, i - j);

                if (st.find(part) != st.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

        unordered_set<string> st;

        // Put all words in set
        for (string word : words) {
            st.insert(word);
        }

        vector<string> ans;

        for (string word : words) {

            // Temporarily remove itself
            st.erase(word);

            if (canForm(word, st)) {
                ans.push_back(word);
            }

            // Put it back
            st.insert(word);
        }

        return ans;
    }
};