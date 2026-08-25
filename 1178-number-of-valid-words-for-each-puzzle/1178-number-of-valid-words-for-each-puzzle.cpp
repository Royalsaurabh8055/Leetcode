class Solution {
public:

    vector<int> findNumOfValidWords(vector<string>& words,
                                    vector<string>& puzzles) {

        unordered_map<int, int> mp;

        // Step 1: Create mask for every word
        for (string word : words) {

            int mask = 0;

            for (char ch : word) {
                mask |= (1 << (ch - 'a'));
            }

            mp[mask]++;
        }

        vector<int> ans;

        // Step 2: Process every puzzle
        for (string puzzle : puzzles) {

            int puzzleMask = 0;

            for (char ch : puzzle) {
                puzzleMask |= (1 << (ch - 'a'));
            }

            // First character of puzzle
            int firstChar = 1 << (puzzle[0] - 'a');

            int count = 0;

            // Generate all submasks
            int sub = puzzleMask;

            while (sub > 0) {

                // Must contain first character
                if ((sub & firstChar) != 0) {

                    if (mp.find(sub) != mp.end()) {
                        count += mp[sub];
                    }
                }

                // Move to next submask
                sub = (sub - 1) & puzzleMask;
            }

            ans.push_back(count);
        }

        return ans;
    }
};