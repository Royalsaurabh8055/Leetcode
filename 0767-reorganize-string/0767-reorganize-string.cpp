class Solution {
public:
    string reorganizeString(string s) {

        int n = s.size();

        // Count frequency of every character
        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Find character with maximum frequency
        int maxFreq = 0;
        int maxChar = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                maxChar = i;
            }
        }

        // If one character occurs too many times,
        // answer is impossible
        if (maxFreq > (n + 1) / 2) {
            return "";
        }

        string ans(n, ' ');

        int index = 0;

        // First put the most frequent character
        while (freq[maxChar] > 0) {

            ans[index] = char('a' + maxChar);

            freq[maxChar]--;

            index += 2;

            // If even positions are finished,
            // start using odd positions
            if (index >= n) {
                index = 1;
            }
        }

        // Put remaining characters
        for (int i = 0; i < 26; i++) {

            while (freq[i] > 0) {

                ans[index] = char('a' + i);

                freq[i]--;

                index += 2;

                if (index >= n) {
                    index = 1;
                }
            }
        }

        return ans;
    }
};