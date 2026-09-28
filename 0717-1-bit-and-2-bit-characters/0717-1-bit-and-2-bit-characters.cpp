class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        int n = bits.size();

        while (i < n - 1) {
            if (bits[i] == 1) {
                // 2-bit character: 10 or 11
                i += 2;
            } else {
                // 1-bit character: 0
                i += 1;
            }
        }

        // If we land exactly on the last bit,
        // it is a 1-bit character.
        return i == n - 1;
    }
};