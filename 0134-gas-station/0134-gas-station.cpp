class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = -1; 

        // go to each iteration and check movement is possible or not 
        int balance = 0;
        int deficit = 0;
        int start = 0; 

        for(int i =0; i<gas.size(); i++)
        {
            
           if(balance + gas[i] < cost[i])
           {
            // cannot move ahead calculate deficit 
            deficit += balance + gas[i] - cost[i];
            balance  =0;
            start = i+1;
              
           }
           else
           {
                balance = balance + gas[i] - cost[i];
                
           }
  

        
        }
        if(deficit + balance >=0)
         return start;
         else 
        return ans; 
    }
};