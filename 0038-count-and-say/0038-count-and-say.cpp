class Solution {
public:
    string countAndSay(int n) {

        string ans = "1";

        for (int i = 2; i <= n; i++) {

            string temp = "";

            int j = 0;

            while (j < ans.length()) {

                char ch = ans[j];
                int count = 0;

                // Count consecutive same characters
                while (j < ans.length() && ans[j] == ch) {
                    count++;
                    j++;
                }

                // Add count + character
                temp += to_string(count);
                temp += ch;
            }

            ans = temp;
        }

        return ans;
    }
};