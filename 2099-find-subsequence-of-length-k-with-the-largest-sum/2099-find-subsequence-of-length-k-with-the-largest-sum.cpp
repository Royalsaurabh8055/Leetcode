class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {

        vector<pair<int,int>> v;

        for(int i = 0; i < nums.size(); i++)
        {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.first > b.first;
        });

        vector<pair<int,int>> selected;

        for(int i = 0; i < k; i++)
        {
            selected.push_back(v[i]);
        }

        sort(selected.begin(), selected.end(), [](auto &a, auto &b){
            return a.second < b.second;
        });

        vector<int> ans;

        for(auto &x : selected)
        {
            ans.push_back(x.first);
        }

        return ans;
    }
};