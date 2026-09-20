class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {

        unordered_set<string> st;

        // Store all roots
        for(string word : dictionary) {
            st.insert(word);
        }

        stringstream ss(sentence);
        string word;
        string ans = "";

        while(ss >> word) {

            string prefix = "";
            string replacement = word;

            // Check prefixes from shortest to longest
            for(char ch : word) {
                prefix += ch;

                if(st.find(prefix) != st.end()) {
                    replacement = prefix;
                    break;
                }
            }

            if(!ans.empty())
                ans += " ";

            ans += replacement;
        }

        return ans;
    }
};