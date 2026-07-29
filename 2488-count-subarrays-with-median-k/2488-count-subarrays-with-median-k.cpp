class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {

        int n = nums.size();
        int pos = 0;

        // Find the position of k
        for (int i = 0; i < n; i++) {
            if (nums[i] == k) {
                pos = i;
                break;
            }
        }

        unordered_map<int, int> mp;
        mp[0] = 1;

        int balance = 0;

        // Traverse left of k
        for (int i = pos - 1; i >= 0; i--) {

            if (nums[i] < k)
                balance--;
            else
                balance++;

            mp[balance]++;
        }

        int ans = 0;
        balance = 0;

        // Traverse from k towards right
        for (int i = pos; i < n; i++) {

            if (nums[i] < k)
                balance--;
            else if (nums[i] > k)
                balance++;

            ans += mp[-balance];
            ans += mp[-balance + 1];
        }

        return ans;
    }
};