class Solution {
public:
    bool isNumber(string s) {

        bool seenDigit = false;
        bool seenDot = false;
        bool seenExponent = false;

        for (int i = 0; i < s.size(); i++) {

            char c = s[i];

            if (isdigit(c)) {
                seenDigit = true;
            }

            else if (c == '+' || c == '-') {

                // Sign is valid only at the beginning
                // or immediately after e/E
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }

            else if (c == '.') {

                // Dot cannot appear after exponent
                // and only one dot is allowed
                if (seenDot || seenExponent)
                    return false;

                seenDot = true;
            }

            else if (c == 'e' || c == 'E') {

                // Only one exponent allowed
                // and there must be a number before it
                if (seenExponent || !seenDigit)
                    return false;

                seenExponent = true;

                // Need digits after exponent
                seenDigit = false;
            }

            else {
                return false;
            }
        }

        return seenDigit;
    }
};