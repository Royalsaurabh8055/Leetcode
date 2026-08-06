class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int ans = 0; 
        unordered_map<int,int>mp;
        int n = candyType.size();

        for(int i =0;i<candyType.size();i++)
        {
            mp[candyType[i]]++;
  
        }
        if(mp.size()>= n/2) // means more than  n/2 types present
            return n/2;

            else
            {
                return mp.size();
            }

    }
};