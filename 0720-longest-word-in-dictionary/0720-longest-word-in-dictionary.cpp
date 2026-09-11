class Solution {
public:
    string longestWord(vector<string>& words) {

        // Lexicographical order me sort
        sort(words.begin(), words.end());

        unordered_set<string> st;

        string ans = "";

        for (string word : words) {

            // Word ka previous part
            string previous = word.substr(0, word.length() - 1);

            // Agar word single character ka hai
            // ya previous word already available hai
            if (word.length() == 1 || st.find(previous) != st.end()) {

                st.insert(word);

                // Longer word mila
                if (word.length() > ans.length()) {
                    ans = word;
                }
            }
        }

        return ans;
    }
};