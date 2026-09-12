class Solution {
public:
    string findValidPair(string s) {

        int freq[10] = {0};

        // Frequency count
        for (char ch : s) {
            freq[ch - '0']++;
        }

        // Check adjacent digits
        for (int i = 0; i < s.length() - 1; i++) {

            int a = s[i] - '0';
            int b = s[i + 1] - '0';

            // Both digits must be different
            // and frequency must equal the digit itself
            if (a != b &&
                freq[a] == a &&
                freq[b] == b) {

                return s.substr(i, 2);
            }
        }

        return "";
    }
};