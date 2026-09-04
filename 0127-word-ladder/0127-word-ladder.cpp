class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        // endWord must be present
        if (st.find(endWord) == st.end())
            return 0;

        queue<pair<string, int>> q;

        q.push({beginWord, 1});

        // beginWord is already visited
        st.erase(beginWord);

        while (!q.empty()) {

            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // Try changing every character
            for (int i = 0; i < word.length(); i++) {

                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    word[i] = ch;

                    // Found next valid word
                    if (st.find(word) != st.end()) {

                        if (word == endWord)
                            return steps + 1;

                        q.push({word, steps + 1});

                        // Mark visited
                        st.erase(word);
                    }
                }

                // Restore original character
                word[i] = original;
            }
        }

        return 0;
    }
};