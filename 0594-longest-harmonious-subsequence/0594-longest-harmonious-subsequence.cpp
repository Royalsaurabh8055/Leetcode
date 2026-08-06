class Solution {
public:
    int findLHS(vector<int>& nums) {

        //sort(nums.begin(), nums.end());

        int ans =0;
        unordered_map<int,int>freq;

        for(int i =0; i<nums.size(); i++)
        {
            freq[nums[i]]++; // store the frequency of each element
        }

        for(auto it:freq)
        {
            //int n = freq[nums[i]];
            int n = it.first;

            if(freq.find(n+1) != freq.end())
            {
               
                ans = max(ans, freq[n] + freq[n+1] );
            }
        }
        return ans;
    }
};