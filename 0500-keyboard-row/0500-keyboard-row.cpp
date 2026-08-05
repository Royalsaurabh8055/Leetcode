class Solution {
public:
    vector<string> findWords(vector<string>& words) {

        unordered_map<char, int> row;

        string r1 = "qwertyuiop";
        string r2 = "asdfghjkl";
        string r3 = "zxcvbnm";

        for (char c : r1)
            row[c] = 1;

        for (char c : r2)
            row[c] = 2;

        for (char c : r3)
            row[c] = 3;

        vector<string> ans;

        for (string word : words) {

            int currRow = row[tolower(word[0])];
            bool ok = true;

            for (char c : word) {

                if (row[tolower(c)] != currRow) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                ans.push_back(word);
        }

        return ans;
    }
};