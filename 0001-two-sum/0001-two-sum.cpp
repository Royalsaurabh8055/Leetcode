

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     
    map<int,int>mp;
    int n = nums.size();
    for(int i=0;i<n;i++)
    {
        int a = nums[i];
        int moreneed = target - a;

        if(mp.find(moreneed) != mp.end())
        return {mp[moreneed],i};

        mp[a]=i;
    }
    return {-1,-1};
    }
};
