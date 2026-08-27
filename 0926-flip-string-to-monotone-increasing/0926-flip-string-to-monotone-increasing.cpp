class Solution {
public:
    int minFlipsMonoIncr(string s) {

        int ones = 0;
        int flips = 0;

        for (char ch : s) {

            // If we see 1,
            // just count it.
            if (ch == '1') {
                ones++;
            }

            // If we see 0 after some 1s,
            // we have a problem.
            else {

                // Option 1:
                // Flip this 0 -> 1
                int option1 = flips + 1;

                // Option 2:
                // Flip all previous 1s -> 0
                int option2 = ones;

                flips = min(option1, option2);
            }
        }

        return flips;
    }
};