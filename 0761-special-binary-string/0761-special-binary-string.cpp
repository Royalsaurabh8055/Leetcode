class Solution {
public:

    string makeLargestSpecial(string s) {

        vector<string> parts;

        int count = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '1')
                count++;
            else
                count--;

            // Found one complete special substring
            if (count == 0) {

                // Remove outer 1 and 0
                string inner =
                    s.substr(start + 1, i - start - 1);

                // Recursively make the inside largest
                inner = makeLargestSpecial(inner);

                // Put outer 1 and 0 back
                parts.push_back("1" + inner + "0");

                start = i + 1;
            }
        }

        // Put largest special substrings first
        sort(parts.rbegin(), parts.rend());

        string ans;

        for (string &part : parts)
            ans += part;

        return ans;
    }
};