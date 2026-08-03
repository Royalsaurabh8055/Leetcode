class Solution {
public:
    vector<string> ans;

    void solve(string &curr, int n) {

        if (curr.size() == n) {
            ans.push_back(curr);
            return;
        }

        for (char ch : {'a', 'b', 'c'}) {

            if (!curr.empty() && curr.back() == ch)
                continue;

            curr.push_back(ch);

            solve(curr, n);

            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {

        string curr = "";

        solve(curr, n);

        if (k > ans.size())
            return "";

        return ans[k - 1];
    }
};