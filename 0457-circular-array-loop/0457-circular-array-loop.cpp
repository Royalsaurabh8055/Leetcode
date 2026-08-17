class Solution {
public:

    int nextIndex(vector<int>& nums, int i) {
        int n = nums.size();

        return ((i + nums[i]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {

        int n = nums.size();

        if (n < 2)
            return false;

        for (int i = 0; i < n; i++) {

            if (nums[i] == 0)
                continue;

            int slow = i;
            int fast = nextIndex(nums, i);

            // Both pointers must follow the same direction
            while (
                nums[i] * nums[fast] > 0 &&
                nums[i] * nums[nextIndex(nums, fast)] > 0
            ) {

                // Cycle detected
                if (slow == fast) {

                    // One-element cycle is NOT valid
                    if (slow == nextIndex(nums, slow))
                        break;

                    return true;
                }

                slow = nextIndex(nums, slow);

                fast = nextIndex(
                    nums,
                    nextIndex(nums, fast)
                );
            }

            // Mark this path as visited
            // so we don't process it again
            slow = i;

            while (nums[i] * nums[slow] > 0) {

                int next = nextIndex(nums, slow);

                nums[slow] = 0;

                slow = next;
            }
        }

        return false;
    }
};