class Solution {
public:
    int minSwaps(string s) {
        
//         stack<char>st; 

//         for(int i =0;i<s.length();i++)
//         {
//             char ch = s[i];

//             if(ch == '[')
//             st.push(ch); // if open found simply push we need to check for close ones

//             else // closing brackets found
//             {
//                 if(!st.empty() && st.top() == '[') // top pr open hai
//                 st.pop(); // cancel valid pairs

//                 else
//                 st.push(ch);
//             }
//         }
//         int open =0;
//         int close =0;
//         while(!st.empty())
//         {
//             if(st.top() == '[') open++;

//             else
//             close++;

//             st.pop();
//         }

//         return (open+1)/2;

    int open =0;
    int imbalance =0;

    for(int i=0;i<s.length();i++)
    {
        char ch = s[i];

        if(ch == '[') open++;

        else// its ]
        {
            if(open>0)
            open--;

            else
            imbalance++;
        }
    }

    return (imbalance+1)/2;

    }
};