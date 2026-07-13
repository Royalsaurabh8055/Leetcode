class Solution {
public:
    int longestValidParentheses(string s) {
        // we are using indices and tracking the longest continous valid parenthesis

        int ans =0;

        stack<int>st;
        st.push(-1); //let index store here is -1;


        for(int i=0;i<s.length(); i++)
        {
            char ch = s[i];

            if( ch == '(') 
            st.push(i);

            else { // closing backets

                st.pop();
            
                // uf stack got empty then update the index in stack(store)

                if(st.empty())
                st.push(i);

                else

                ans = max(ans, i-st.top());
            }

        }
        return ans;
    }
};