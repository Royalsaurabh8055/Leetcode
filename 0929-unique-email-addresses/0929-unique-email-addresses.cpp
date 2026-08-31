class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {

        unordered_set<string> st;

        for (string email : emails) {

            // Find @
            int at = email.find('@');

            // Get local part
            string local = email.substr(0, at);

            // Get domain part
            string domain = email.substr(at + 1);

            string newLocal = "";

            // Process local part
            for (char ch : local) {

                // Everything after + is ignored
                if (ch == '+') {
                    break;
                }

                // Ignore .
                if (ch == '.') {
                    continue;
                }

                newLocal += ch;
            }

            // Create actual email
            string finalEmail = newLocal + "@" + domain;

            // Store unique email
            st.insert(finalEmail);
        }

        return st.size();
    }
};