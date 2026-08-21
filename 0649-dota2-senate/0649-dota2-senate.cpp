class Solution {
public:
    string predictPartyVictory(string senate) {

        queue<int>r,d;
        int i =0;
        for(;i<senate.size();i++)
        {
            char ch = senate[i];

            if(ch == 'R') r.push(i);
            else{
                // if ch == D
                d.push(i);
        }// q with both D and R indexes created 
        }
        while(!r.empty() && !d.empty())
        {
            int rFront = r.front();
            r.pop(); // poping 

            int dFront = d.front();
            d.pop() ;// poping from both queue but place again on basis of index 

            if(rFront < dFront)
            r.push(i++);// it will be added in last 

            else
            d.push(i++); // which came earlier is pushed again after banning other  
        }
        
        if(!r.empty()) return "Radiant";

        else 
        return "Dire";


    }
};