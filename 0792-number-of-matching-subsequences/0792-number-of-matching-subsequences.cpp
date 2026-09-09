class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {

        vector<vector<int>> pos(26);

        // Store positions of every character
        for (int i = 0; i < s.length(); i++) {
            pos[s[i] - 'a'].push_back(i);
        }

        int ans = 0;

        for (string word : words) {

            int prev = -1;
            bool possible = true;

            for (char ch : word) {

                vector<int>& v = pos[ch - 'a'];

                // Find first position > prev
                auto it = upper_bound(v.begin(), v.end(), prev);

                if (it == v.end()) {
                    possible = false;
                    break;
                }

                prev = *it;
            }

            if (possible)
                ans++;
        }

        return ans;
    }
};