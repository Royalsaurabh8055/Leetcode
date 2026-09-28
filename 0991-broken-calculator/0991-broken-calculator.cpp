class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans = 0;

        while (target > startValue) {

            // If target is odd, we must increase it by 1
            if (target % 2 == 1) {
                target++;
            }
            else {
                // Reverse of multiply by 2
                target /= 2;
            }

            ans++;
        }

        // Now target <= startValue.
        // Only +1 in reverse is possible.
        ans += startValue - target;

        return ans;
    }
};