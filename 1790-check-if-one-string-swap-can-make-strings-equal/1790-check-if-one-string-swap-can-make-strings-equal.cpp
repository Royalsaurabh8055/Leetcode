class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int first = -1, second = -1;

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                if (first == -1) {
                    first = i;
                } else if (second == -1) {
                    second = i;
                } else {
                    return false;
                }
            }
        }

        // Strings are already equal
        if (first == -1) return true;

        // Exactly one mismatch cannot be fixed by one swap
        if (second == -1) return false;

        // Check whether swapping fixes both mismatches
        return s1[first] == s2[second] &&
               s1[second] == s2[first];
    }
};