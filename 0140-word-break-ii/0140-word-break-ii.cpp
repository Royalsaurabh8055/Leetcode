class Solution {
public:
    unordered_set<string> st;
    unordered_map<int, vector<string>> dp;

    vector<string> solve(string& s, int index) {

        // String completely used
        if (index == s.length()) {
            return {""};
        }

        // Already calculated
        if (dp.find(index) != dp.end()) {
            return dp[index];
        }

        vector<string> ans;
        string word = "";

        for (int i = index; i < s.length(); i++) {

            word += s[i];

            // Check if current part is a dictionary word
            if (st.find(word) == st.end()) {
                continue;
            }

            // Solve remaining string
            vector<string> remaining = solve(s, i + 1);

            for (string sentence : remaining) {

                if (sentence == "") {
                    ans.push_back(word);
                }
                else {
                    ans.push_back(word + " " + sentence);
                }
            }
        }

        return dp[index] = ans;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        for (string word : wordDict) {
            st.insert(word);
        }

        return solve(s, 0);
    }
};