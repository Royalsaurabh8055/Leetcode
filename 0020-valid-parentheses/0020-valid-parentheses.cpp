class Solution {
public:
    bool isValid(string s) {

        stack<char>st;

        int l = s.length();

       // if(l&1) return false;

        for(int i =0;i<l;i++)
        {
            char ch = s[i];

            if(ch == '(' || ch =='{' || ch == '[')
            {
                st.push(ch);
            }
            else { // closing brackets 

           if (st.empty()) return false; // nothing is pushed and closing brackets found

            else if( ch == ')' && st.top() != '(')
            return false; 

            else if(ch == '}' && st.top() != '{')
            return false;

            else if(ch == ']' && st.top() != '[')
            return false; 

            else
            {
                // matching barckets found 
                st.pop();
            }
        }

        }
       return st.empty(); 
    }
};