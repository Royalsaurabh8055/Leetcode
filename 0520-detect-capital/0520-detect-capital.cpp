class Solution {
public:
    bool detectCapitalUse(string word) {

        int capital = 0;

        for (char ch : word) {
            if (ch >= 'A' && ch <= 'Z') {
                capital++;
            }
        }

        // All lowercase
        if (capital == 0)
            return true;

        // All uppercase
        if (capital == word.length())
            return true;

        // Only first letter uppercase
        if (capital == 1 && word[0] >= 'A' && word[0] <= 'Z')
            return true;

        return false;
    }
};