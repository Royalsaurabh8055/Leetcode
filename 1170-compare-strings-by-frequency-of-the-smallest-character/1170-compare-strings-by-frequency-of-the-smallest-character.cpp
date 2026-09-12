class Solution {
public:

    int getFrequency(string s) {

        int freq[26] = {0};

        // Count every character
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // First non-zero frequency
        // gives frequency of smallest character
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0)
                return freq[i];
        }

        return 0;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries,
                                      vector<string>& words) {

        vector<int> wordFreq;

        // Find f(word) for every word
        for (string word : words) {
            wordFreq.push_back(getFrequency(word));
        }

        // Sort frequencies
        sort(wordFreq.begin(), wordFreq.end());

        vector<int> ans;

        for (string query : queries) {

            int qFreq = getFrequency(query);

            // Find first frequency > qFreq
            int index = upper_bound(
                wordFreq.begin(),
                wordFreq.end(),
                qFreq
            ) - wordFreq.begin();

            // Everything after index is greater
            ans.push_back(wordFreq.size() - index);
        }

        return ans;
    }
};