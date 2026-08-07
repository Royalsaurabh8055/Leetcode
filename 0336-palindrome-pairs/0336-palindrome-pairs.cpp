class Solution {
public:
    bool isPalindrome(string &s, int left, int right) {

        while (left < right) {

            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {

        unordered_map<string, int> mp;

        for (int i = 0; i < words.size(); i++) {
            mp[words[i]] = i;
        }

        vector<vector<int>> ans;

        for (int i = 0; i < words.size(); i++) {

            string word = words[i];

            for (int j = 0; j <= word.size(); j++) {

                string left = word.substr(0, j);
                string right = word.substr(j);

                // Case 1
                if (isPalindrome(word, 0, j - 1)) {

                    string rev = right;
                    reverse(rev.begin(), rev.end());

                    if (mp.find(rev) != mp.end() && mp[rev] != i) {
                        ans.push_back({mp[rev], i});
                    }
                }

                // Case 2
                if (j != word.size() && isPalindrome(word, j, word.size() - 1)) {

                    string rev = left;
                    reverse(rev.begin(), rev.end());

                    if (mp.find(rev) != mp.end() && mp[rev] != i) {
                        ans.push_back({i, mp[rev]});
                    }
                }
            }
        }

        return ans;
    }
};