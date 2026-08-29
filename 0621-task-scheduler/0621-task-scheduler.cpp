class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // Count frequency of each task
        vector<int> freq(26, 0);

        for (char ch : tasks) {
            freq[ch - 'A']++;
        }

        // Find maximum frequency
        int maxFreq = 0;

        for (int i = 0; i < 26; i++) {
            maxFreq = max(maxFreq, freq[i]);
        }

        // Count how many tasks have maximum frequency
        int countMax = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] == maxFreq) {
                countMax++;
            }
        }

        // Build the minimum required frame
        int answer =
            (maxFreq - 1) * (n + 1) + countMax;

        // If there are enough different tasks to fill
        // all the idle spaces, answer is simply
        // total number of tasks.
        return max((int)tasks.size(), answer);
    }
};