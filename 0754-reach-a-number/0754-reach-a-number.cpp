class Solution {
public:
    int reachNumber(int target) {

        target = abs(target);

        int sum = 0;
        int moves = 0;

        while (sum < target || (sum - target) % 2 != 0) {

            moves++;
            sum += moves;
        }

        return moves;
    }
};