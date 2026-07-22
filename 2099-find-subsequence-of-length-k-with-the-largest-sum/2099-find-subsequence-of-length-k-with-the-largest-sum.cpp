
bool compare(pair<int,int>&a,pair<int,int>&b)
{
    return a.first>b.first;
}

bool compareIndex(pair<int,int>&a, pair<int,int>&b)
{
    return a.second<b.second;
}

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {

        vector<pair<int,int>> v;

        for(int i = 0; i < nums.size(); i++)
        {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end(), compare);




        vector<pair<int,int>> selected;

        for(int i = 0; i < k; i++)
        {
            selected.push_back(v[i]);
        }

        sort(selected.begin(), selected.end(),compareIndex);
            

        vector<int> ans;

        for(auto &x : selected)
        {
            ans.push_back(x.first);
        }

        return ans;
    }
};