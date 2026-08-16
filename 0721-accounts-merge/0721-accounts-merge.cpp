class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] == x)
            return x;

        // Path compression
        return parent[x] = find(parent[x]);
    }

    void Union(int a, int b) {

        int pa = find(a);
        int pb = find(b);

        if (pa == pb)
            return;

        // Union by rank
        if (rank[pa] < rank[pb]) {
            parent[pa] = pb;
        }
        else if (rank[pa] > rank[pb]) {
            parent[pb] = pa;
        }
        else {
            parent[pb] = pa;
            rank[pa]++;
        }
    }

    vector<vector<string>> accountsMerge(
        vector<vector<string>>& accounts) {

        int n = accounts.size();

        parent.resize(n);
        rank.resize(n, 0);

        // Initially every account is its own component
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // email -> account index
        unordered_map<string, int> emailToAccount;

        // --------------------------------
        // STEP 1: Union accounts
        // --------------------------------

        for (int i = 0; i < n; i++) {

            for (int j = 1; j < accounts[i].size(); j++) {

                string email = accounts[i][j];

                if (emailToAccount.find(email) ==
                    emailToAccount.end()) {

                    // First time seeing this email
                    emailToAccount[email] = i;
                }
                else {

                    // Email already belongs to another account
                    Union(i, emailToAccount[email]);
                }
            }
        }

        // --------------------------------
        // STEP 2: Group emails by root
        // --------------------------------

        unordered_map<int, vector<string>> groups;

        for (auto& it : emailToAccount) {

            string email = it.first;
            int accountIndex = it.second;

            int root = find(accountIndex);

            groups[root].push_back(email);
        }

        // --------------------------------
        // STEP 3: Create answer
        // --------------------------------

        vector<vector<string>> ans;

        for (auto& it : groups) {

            int root = it.first;

            vector<string> emails = it.second;

            // Emails must be sorted
            sort(emails.begin(), emails.end());

            vector<string> account;

            // Name of root account
            account.push_back(accounts[root][0]);

            // Add emails
            for (string email : emails) {
                account.push_back(email);
            }

            ans.push_back(account);
        }

        return ans;
    }
};