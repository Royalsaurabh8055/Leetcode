class Solution {
public:

    vector<string> words;
    string result;

    int mp[26];
    bool used[10];
    bool leading[26];

    bool solve(int col, int row, int sum) {

        // All columns completed
        if (col == result.size()) {
            return sum == 0;
        }

        // Processed all words for this column
        if (row == words.size()) {

            char ch = result[result.size() - 1 - col];

            int digit = sum % 10;
            int carry = sum / 10;

            // Already assigned
            if (mp[ch - 'A'] != -1) {
                if (mp[ch - 'A'] != digit)
                    return false;

                return solve(col + 1, 0, carry);
            }

            // Try assigning digit to result character
            if (used[digit])
                return false;

            if (digit == 0 && leading[ch - 'A'])
                return false;

            mp[ch - 'A'] = digit;
            used[digit] = true;

            if (solve(col + 1, 0, carry))
                return true;

            // Backtrack
            mp[ch - 'A'] = -1;
            used[digit] = false;

            return false;
        }

        // Current word doesn't have this column
        if (col >= words[row].size()) {
            return solve(col, row + 1, sum);
        }

        char ch = words[row][words[row].size() - 1 - col];

        // Character already assigned
        if (mp[ch - 'A'] != -1) {
            return solve(col, row + 1, sum + mp[ch - 'A']);
        }

        // Try digits 0-9
        for (int digit = 0; digit <= 9; digit++) {

            if (used[digit])
                continue;

            if (digit == 0 && leading[ch - 'A'])
                continue;

            mp[ch - 'A'] = digit;
            used[digit] = true;

            if (solve(col, row + 1, sum + digit))
                return true;

            // Backtrack
            mp[ch - 'A'] = -1;
            used[digit] = false;
        }

        return false;
    }

    bool isSolvable(vector<string>& words, string result) {

        this->words = words;
        this->result = result;

        // Initialize mapping
        for (int i = 0; i < 26; i++) {
            mp[i] = -1;
            leading[i] = false;
        }

        for (int i = 0; i < 10; i++) {
            used[i] = false;
        }

        // Mark leading characters
        for (string word : words) {
            if (word.size() > 1) {
                leading[word[0] - 'A'] = true;
            }
        }

        if (result.size() > 1) {
            leading[result[0] - 'A'] = true;
        }

        // Number of columns must be result length
        for (string word : words) {
            if (word.size() > result.size())
                return false;
        }

        return solve(0, 0, 0);
    }
};