class Solution {
public:

    int maxScoreWords(vector<string>& words,
                      vector<char>& letters,
                      vector<int>& score) {

        // Count available letters
        vector<int> count(26, 0);

        for (char ch : letters) {
            count[ch - 'a']++;
        }

        return solve(words, 0, count, score);
    }

    int solve(vector<string>& words,
              int index,
              vector<int>& count,
              vector<int>& score) {

        // We have processed all words
        if (index == words.size()) {
            return 0;
        }

        // Option 1: Don't take this word
        int skip = solve(words, index + 1, count, score);

        // Option 2: Try taking this word
        int take = 0;
        bool canTake = true;

        // Check if we have enough letters
        for (char ch : words[index]) {

            count[ch - 'a']--;

            if (count[ch - 'a'] < 0) {
                canTake = false;
            }

            take += score[ch - 'a'];
        }

        // If we have enough letters
        if (canTake) {
            take += solve(words, index + 1, count, score);
        }

        // IMPORTANT:
        // Put the letters back
        for (char ch : words[index]) {
            count[ch - 'a']++;
        }

        return max(skip, canTake ? take : 0);
    }
};