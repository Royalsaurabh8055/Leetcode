class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {

        long long totalCount = 0;
        long long sum = 0;

        int minimum = -1;
        int maximum = -1;

        int mode = 0;
        int maxFrequency = 0;

        // Find min, max, mean, mode
        for(int i = 0; i < count.size(); i++) {

            if(count[i] == 0)
                continue;

            // First existing value = minimum
            if(minimum == -1)
                minimum = i;

            // Last existing value = maximum
            maximum = i;

            // Total elements
            totalCount += count[i];

            // Sum of all elements
            sum += (long long)i * count[i];

            // Mode
            if(count[i] > maxFrequency) {
                maxFrequency = count[i];
                mode = i;
            }
        }

        double mean = (double)sum / totalCount;

        // Find median
        long long pos1 = (totalCount + 1) / 2;
        long long pos2 = (totalCount + 2) / 2;

        int median1 = 0;
        int median2 = 0;

        long long current = 0;

        for(int i = 0; i < count.size(); i++) {

            current += count[i];

            if(current >= pos1 && median1 == 0)
                median1 = i;

            if(current >= pos2) {
                median2 = i;
                break;
            }
        }

        double median = (median1 + median2) / 2.0;

        return {
            (double)minimum,
            (double)maximum,
            mean,
            median,
            (double)mode
        };
    }
};