class Solution {
public:
    string compressedString(string word) {

        string ans = "";

        int i = 0;

        while (i < word.size()) {

            char ch = word[i];
            int count = 0;

            // Count same characters, maximum 9
            while (i < word.size() &&
                   word[i] == ch &&
                   count < 9) {

                count++;
                i++;
            }

            // Add count + character
            ans += to_string(count);
            ans += ch;
        }

        return ans;
    }
};