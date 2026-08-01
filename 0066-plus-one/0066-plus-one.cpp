class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {

            // If digit is less than 9, simply increment it
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            // Otherwise, make it 0 and carry continues
            digits[i] = 0;
        }

        // All digits were 9
        digits.insert(digits.begin(), 1);

        return digits;
    }
};