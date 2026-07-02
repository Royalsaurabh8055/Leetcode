class Solution {
public:
vector<int>prevsmallest(vector<int>&nums)
{
    stack<int>st;
    st.push(-1);

    vector<int>ans(nums.size(), -1); // to store the indices of prev ssmallest found

    for(int i =0; i<nums.size();i++)
    {
        while(!st.empty() && st.top() != -1 && nums[st.top()] > nums[i])
        st.pop();

        ans[i] = st.top(); // yha aa gye matlb chota mil gya to ans me dal do

        st.push(i); // current index ko stack me push kar do
    }
    return ans;

}

vector<int>nextsmallest(vector<int>&nums)
{
    stack<int>st;
    st.push(-1);

    vector<int>ans(nums.size(), -1); // to store the indices of prev ssmallest found

    for(int i =nums.size()-1; i>=0;i--)
    {
        while(!st.empty() && st.top() != -1 && nums[st.top()] >= nums[i])
        st.pop();

        ans[i] = st.top(); // yha aa gye matlb chota mil gya to ans me dal do

        st.push(i); // current index ko stack me push kar do
    }
    return ans;

}
vector<int>nextgreatest(vector<int>&nums)
{
    stack<int>st;
    st.push(-1);

    vector<int>ans(nums.size(), -1); // to store the indices of prev ssmallest found

    for(int i =nums.size()-1; i>=0;i--)
    {
        while(!st.empty() && st.top() != -1 && nums[st.top()] <= nums[i])
        st.pop();

        ans[i] = st.top(); // yha aa gye matlb bda mil gya to ans me dal do

        st.push(i); // current index ko stack me push kar do
    }
    return ans;

}

vector<int>prevgreatest(vector<int>&nums)
{
    stack<int>st;
    st.push(-1);

    vector<int>ans(nums.size(), -1); // to store the indices of prev ssmallest found

    for(int i =0; i<nums.size();i++)
    {
        while(!st.empty() && st.top() != -1 && nums[st.top()] < nums[i])
        st.pop();

        ans[i] = st.top(); // yha aa gye matlb bda mil gya to ans me dal do

        st.push(i); // current index ko stack me push kar do
    }
    return ans;

}
long long nextSmaller(vector<int>&nums)
{
    // if we found the previous smaller elemnt and nextsmaller element it means in that range its min

    auto prev = prevsmallest(nums);
    auto next = nextsmallest(nums);

    long long sum =0;
     for(int i=0;i<nums.size(); i++){
    long long previ = prev[i];
    long long nexti = next[i] == -1 ? nums.size() : next[i];

    long long left = i - previ;
    long long right = nexti - i;

    long long curr = left*right; // how many times that element appeared(obvossilsy its min among )
    long long total = curr*nums[i];

    sum = sum + total; 
     }

     return sum;

}



long long nextGreater(vector<int>&nums)
{
    auto next = nextgreatest(nums);
    auto prev = prevgreatest(nums);

    long long sum =0;

    for(int i=0;i<nums.size();i++)
    {
        long long nexti = next[i] == -1 ? nums.size() : next[i];
        long long previ = prev[i];

        long long left = i - previ; 
        long long right = nexti - i; 

        long long curr = left*right; 
        long long total = curr*nums[i];

        sum = sum+total;
    }

    return sum; 

}



    long long subArrayRanges(vector<int>& nums) {
        // here we find sum of the largest elements of subarrays then 
        // substract the sum of the minimum(least element of subarrays)

        auto sumoflargest = nextGreater(nums);
        auto sumofsmallest = nextSmaller(nums);

        return (sumoflargest - sumofsmallest);
    }
};