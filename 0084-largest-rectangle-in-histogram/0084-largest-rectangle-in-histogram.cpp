class Solution {
public:

void nextSmaller(vector<int>& heights, vector<int>& nextAns)
    {
        stack<int>st; 

        st.push(-1);
        int n = heights.size();

        for(int i = n-1; i>=0; i--) 
        {
            int element = heights[i];
            // because we are pushing in stack and checking the top so iterrate from last
            while(st.top()!= -1 && heights[st.top()]>=element)
            {
                st.pop();
            }

            nextAns.push_back(st.top());

            st.push(i);

        }

    }
        
    void PrevSmaller(vector<int>& heights, vector<int>& prevAns)
    {
        stack<int>st; 

        st.push(-1);
        int n = heights.size();

        for(int i =0; i<n; i++) 
        {
            int element = heights[i];
            // because we are pushing in stack and checking the top so iterrate from last
            while(st.top()!= -1 && heights[st.top()]>=element)
            {
                st.pop();
            }

            prevAns.push_back(st.top());

            st.push(i);

        }
    }

      
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nextAns; 
        vector<int>prevAns;

        nextSmaller(heights,nextAns);

        reverse(nextAns.begin(),nextAns.end()); // we need to reverse it 

        for(int i =0;i<nextAns.size(); i++)
        {
            if(nextAns[i] == -1)
            nextAns[i] = nextAns.size(); /// because in next index is increased not -1
        }

        PrevSmaller(heights,prevAns); 

        vector<int>Area; 
        for(int i =0;i<nextAns.size(); i++)
        {
            int height = heights[i]; 
            int width = nextAns[i] - prevAns[i] -1; 

            int currArea = height*width;
            Area.push_back(currArea);
        }
         int maxArea = INT_MIN; 

        for(int i =0;i<Area.size(); i++)
        {
           
            maxArea = max(maxArea, Area[i]);
        }

        return maxArea; 

    }
};