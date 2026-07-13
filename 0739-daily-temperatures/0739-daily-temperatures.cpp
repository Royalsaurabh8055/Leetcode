class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);

        stack<int>st;
        st.push(-1);

        // here we are focusing next greater element kind of things and storing the indices

        for(int i=n-1;i>=0;i--)// for next greater/smaller start from end
        {
            int curr = temperatures[i];
            while(!st.empty() && st.top()>=0 && temperatures[st.top()] <= curr )
            {
// because what we are using as index is firstly processed and we are checking with the 
// previous (i-1)th so next greter is checked if so pop 


                st.pop();
            }
            if(st.top() == -1)
            ans[i] = 0;

            else
            ans[i] = st.top() -i;

            st.push(i);
        }
        return ans;
    }
};