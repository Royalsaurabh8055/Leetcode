class Solution {
public:
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans; 

       deque<int>dq;

       // processing for 1st window of k size 
       // storing every index as it could be max for next window but popping only if 
       // greater than the present in queue is found

       for(int i = 0;i<k;i++)
       {

        while(!dq.empty() && nums[dq.back()]<nums[i])
        {
            dq.pop_back();
        }

            // then addition logic as it is 
            dq.push_back(i);
  
       }
        ans.push_back(nums[dq.front()]);
       // now do for remaining window

       for(int i =k; i < nums.size(); i++)
       {
        // removal from window

        while(!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }

        // else include it 
        while(!dq.empty() && nums[dq.back()] < nums[i])
        dq.pop_back();

        dq.push_back(i);

        ans.push_back(nums[dq.front()]);

       }
return ans;
    }
};