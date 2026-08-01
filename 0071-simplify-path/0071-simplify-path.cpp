class Solution {
public:
    string simplifyPath(string path) {

        stack<string> st;
        string curr = "";

        for (int i = 0; i <= path.size(); i++) {

            // Process when we hit '/' or reach the end
            if (i == path.size() || path[i] == '/') {

                if (curr == "" || curr == ".") {
                    // Ignore empty parts and "."
                }

                else if (curr == "..") {

                    if (!st.empty())
                        st.pop();
                }

                else {
                    st.push(curr);
                }

                curr = "";
            }

            else {
                curr += path[i];
            }
        }

        // Build answer
        vector<string> temp;

        while (!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }

        reverse(temp.begin(), temp.end());

        string ans = "";

        for (string &dir : temp) {
            ans += "/" + dir;
        }

        return ans.empty() ? "/" : ans;
    }
};