class Solution {
public:
    bool checkValidString(string s) {
        

        int high =0;
        int low = 0;

        // we need to keep track of the opening  and closing brackets as low and high and * as low-- and high++ 
     // * is used to achive our target means low tending to 0 and high++(avoid negative)

     for(char ch : s)
     {
        if(ch == '(')
        {
            low++;
            high++;
        }

        else if(ch == ')')
        {
            low--;
            high--;
        }

        else
        {
            // * found
            low--;
            high++;
        }
         
     
    low = max(0,low); // don't want low to negative high is allowoed to -ve

    if(high < 0) return false; // too many closing brackets
     }
    return (low == 0) ;


       }
};