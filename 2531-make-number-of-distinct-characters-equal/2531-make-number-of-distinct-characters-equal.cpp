class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> f1(26, 0), f2(26, 0);

        for (char c : word1) f1[c - 'a']++;
        for (char c : word2) f2[c - 'a']++;

        for (int i = 0; i < 26; i++) {
            if (f1[i] == 0) continue;

            for (int j = 0; j < 26; j++) {
                if (f2[j] == 0) continue;

                // Simulate swapping character i with character j
                f1[i]--;
                f2[i]++;
                f2[j]--;
                f1[j]++;

                int d1 = 0, d2 = 0;

                for (int k = 0; k < 26; k++) {
                    if (f1[k] > 0) d1++;
                    if (f2[k] > 0) d2++;
                }

                if (d1 == d2) return true;

                // Restore original frequencies
                f1[i]++;
                f2[i]--;
                f2[j]++;
                f1[j]--;
            }
        }

        return false;
    }
};