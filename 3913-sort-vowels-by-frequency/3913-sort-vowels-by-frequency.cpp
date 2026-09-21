class Solution {
public:
    string sortVowels(string s) {
        vector<int> freq(5, 0);
        vector<int> first(5, INT_MAX);

        string vowels = "aeiou";

        // Count frequency and first occurrence
        for(int i = 0; i < s.size(); i++) {
            for(int j = 0; j < 5; j++) {
                if(s[i] == vowels[j]) {
                    freq[j]++;
                    first[j] = min(first[j], i);
                }
            }
        }

        // Order vowels
        vector<int> order = {0, 1, 2, 3, 4};

        sort(order.begin(), order.end(), [&](int a, int b) {
            if(freq[a] != freq[b])
                return freq[a] > freq[b];

            return first[a] < first[b];
        });

        int pos = 0;

        for(int i = 0; i < s.size(); i++) {

            bool isVowel = false;

            for(int j = 0; j < 5; j++) {
                if(s[i] == vowels[j]) {
                    isVowel = true;
                    break;
                }
            }

            if(isVowel) {
                while(freq[order[pos]] == 0)
                    pos++;

                s[i] = vowels[order[pos]];
                freq[order[pos]]--;
            }
        }

        return s;
    }
};