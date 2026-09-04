class Solution {
public:
    int minSwapsCouples(vector<int>& row) {

        int n = row.size();

        int swaps = 0;

        for (int i = 0; i < n; i += 2) {

            // Person sitting at first seat
            int person = row[i];

            // Find their partner
            int partner;

            if (person % 2 == 0)
                partner = person + 1;
            else
                partner = person - 1;

            // If partner is not sitting next to them
            if (row[i + 1] != partner) {

                // Find partner somewhere ahead
                int j = i + 2;

                while (row[j] != partner) {
                    j++;
                }

                // Swap partner with row[i+1]
                swap(row[i + 1], row[j]);

                swaps++;
            }
        }

        return swaps;
    }
};