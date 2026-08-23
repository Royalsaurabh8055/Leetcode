class Solution {
public:
    int calculate(string s) {

        stack<long long> st;

        long long ans = 0;
        long long sign = 1;
        long long num = 0;

        for (int i = 0; i < s.size(); i++) {

            if (isdigit(s[i])) {

                num = 0;

                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                i--;

                ans += sign * num;
            }

            else if (s[i] == '+') {
                sign = 1;
            }

            else if (s[i] == '-') {
                sign = -1;
            }

            else if (s[i] == '(') {

                st.push(ans);
                st.push(sign);

                ans = 0;
                sign = 1;
            }

            else if (s[i] == ')') {

                long long prevSign = st.top();
                st.pop();

                long long prevAns = st.top();
                st.pop();

                ans = prevAns + prevSign * ans;
            }
        }

        return (int)ans;
    }
};