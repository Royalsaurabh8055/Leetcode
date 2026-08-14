class Solution {
public:
    int maxDiff(int num) {

        string s = to_string(num);

        // -------------------------
        // Find maximum number
        // -------------------------
        string maxi = s;

        char replaceMax = 0;

        // Find first digit that is not 9
        for (char c : s) {
            if (c != '9') {
                replaceMax = c;
                break;
            }
        }

        // Replace it everywhere with 9
        if (replaceMax != 0) {
            for (char &c : maxi) {
                if (c == replaceMax)
                    c = '9';
            }
        }

        // -------------------------
        // Find minimum number
        // -------------------------
        string mini = s;

        char replaceMin = 0;
        char replacement = 0;

        // If first digit is not 1,
        // replace it with 1.
        if (s[0] != '1') {

            replaceMin = s[0];
            replacement = '1';

        } else {

            // First digit is already 1.
            // Find first digit that is not 0 or 1.
            for (int i = 1; i < s.size(); i++) {

                if (s[i] != '0' && s[i] != '1') {
                    replaceMin = s[i];
                    replacement = '0';
                    break;
                }
            }
        }

        // Perform replacement
        if (replaceMin != 0) {

            for (char &c : mini) {
                if (c == replaceMin)
                    c = replacement;
            }
        }

        int maximum = stoi(maxi);
        int minimum = stoi(mini);

        return maximum - minimum;
    }
};