class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<char>st;

        for(int i =0;i<num.length(); i++)
        {
            char ch = num[i];

            while(!st.empty() && st.top()>ch && k>0)
            {
                st.pop();
                k--;
            }
            st.push(ch);
        }

        while(!st.empty() && k>0)// when all num values pushed in stack(1,2,3,4,5)
        {
            st.pop();
            k--;
        }

        string ans = "";

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        // now we have created answer

        reverse(ans.begin(), ans.end());

    // now check zeroes

        int i =0;

        while(i<ans.length() && ans[i] == '0')
        {
            i++;
        }
        ans = ans.substr(i);

        if(ans.empty()) return "0";
        
        return ans;

    }
};