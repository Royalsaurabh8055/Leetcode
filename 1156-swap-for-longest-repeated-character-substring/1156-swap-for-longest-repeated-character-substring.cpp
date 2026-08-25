class Solution {
public:
    int maxRepOpt1(string text) {

        int freq[26] = {};

        for (char ch : text) {
            freq[ch - 'a']++;
        }

        int ans = 0;
        int n = text.size();

        for (int i = 0; i < n; ) {

            int j = i;

            // First consecutive group
            while (j < n && text[j] == text[i]) {
                j++;
            }

            int left = j - i;

            // We can replace one character
            ans = max(ans, min(left + 1, freq[text[i] - 'a']));

            // Check second group
            int k = j + 1;

            while (k < n && text[k] == text[i]) {
                k++;
            }

            int right = k - j - 1;

            if (j < n && text[j] != text[i] && right > 0) {

                int total = left + right;

                // One extra occurrence can be swapped in
                if (freq[text[i] - 'a'] > total) {
                    total++;
                }

                ans = max(ans, total);
            }

            i = j;
        }

        return ans;
    }
};