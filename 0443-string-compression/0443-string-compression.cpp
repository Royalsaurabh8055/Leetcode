class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();

        int i = 0;      // used to read the array
        int index = 0;  // used to write compressed result

        while (i < n) {

            char ch = chars[i];

            int count = 0;

            // Count consecutive same characters
            while (i < n && chars[i] == ch) {
                count++;
                i++;
            }

            // Store the character
            chars[index] = ch;
            index++;

            // Store count only if count > 1
            if (count > 1) {

                string str = to_string(count);

                for (char c : str) {
                    chars[index] = c;
                    index++;
                }
            }
        }

        return index;
    }
};