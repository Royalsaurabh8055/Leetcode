class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {

        unordered_map<string, int> mp;

        for (string s : cpdomains) {

            // Find space between count and domain
            int space = s.find(' ');

            int count = stoi(s.substr(0, space));

            string domain = s.substr(space + 1);

            // Add complete domain
            mp[domain] += count;

            // Add subdomains
            while (domain.find('.') != string::npos) {

                int pos = domain.find('.');

                domain = domain.substr(pos + 1);

                mp[domain] += count;
            }
        }

        vector<string> ans;

        for (auto& [domain, count] : mp) {
            ans.push_back(
                to_string(count) + " " + domain
            );
        }

        return ans;
    }
};