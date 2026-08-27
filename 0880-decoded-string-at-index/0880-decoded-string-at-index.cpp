class Solution {
public:
    string decodeAtIndex(string s, int k) {

        long long size = 0;

        // Find length of decoded string
        for (char ch : s) {

            if (ch >= 'a' && ch <= 'z') {
                size++;
            }
            else {
                size = size * (ch - '0');
            }
        }

        // Go backwards
        for (int i = s.size() - 1; i >= 0; i--) {

            // Convert k into position inside current string
            k = k % size;

            // If k == 0 and current character is a letter,
            // this character is our answer
            if (k == 0 && s[i] >= 'a' && s[i] <= 'z') {
                return string(1, s[i]);
            }

            // Reverse the operation
            if (s[i] >= '2' && s[i] <= '9') {
                size = size / (s[i] - '0');
            }
            else {
                size--;
            }
        }

        return "";
    }
};