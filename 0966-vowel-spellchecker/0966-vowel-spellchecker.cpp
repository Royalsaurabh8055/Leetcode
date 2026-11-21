class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u';
    }

    string toLower(string s) {
        for (char &ch : s) {
            ch = tolower(ch);
        }
        return s;
    }

    string devowel(string s) {
        for (char &ch : s) {
            if (isVowel(ch)) {
                ch = '*';
            }
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {

        unordered_set<string> exact;
        unordered_map<string, string> caseMap;
        unordered_map<string, string> vowelMap;

        // Preprocess wordlist
        for (string word : wordlist) {
            exact.insert(word);

            string lower = toLower(word);

            // Store only the first occurrence
            if (!caseMap.count(lower)) {
                caseMap[lower] = word;
            }

            string pattern = devowel(lower);

            if (!vowelMap.count(pattern)) {
                vowelMap[pattern] = word;
            }
        }

        vector<string> ans;

        for (string query : queries) {

            // 1. Exact match
            if (exact.count(query)) {
                ans.push_back(query);
                continue;
            }

            string lower = toLower(query);

            // 2. Case-insensitive match
            if (caseMap.count(lower)) {
                ans.push_back(caseMap[lower]);
                continue;
            }

            // 3. Vowel-error match
            string pattern = devowel(lower);

            if (vowelMap.count(pattern)) {
                ans.push_back(vowelMap[pattern]);
            } else {
                ans.push_back("");
            }
        }

        return ans;
    }
};