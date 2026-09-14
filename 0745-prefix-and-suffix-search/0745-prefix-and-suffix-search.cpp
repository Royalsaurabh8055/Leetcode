class WordFilter {
public:
    unordered_map<string, int> mp;

    WordFilter(vector<string>& words) {

        for(int i = 0; i < words.size(); i++) {

            string word = words[i];

            // All prefixes
            for(int p = 0; p <= word.length(); p++) {

                string pref = word.substr(0, p);

                // All suffixes
                for(int s = 0; s <= word.length(); s++) {

                    string suff = word.substr(s);

                    string key = suff + "#" + pref;

                    mp[key] = i;
                }
            }
        }
    }

    int f(string pref, string suff) {

        string key = suff + "#" + pref;

        if(mp.find(key) != mp.end()) {
            return mp[key];
        }

        return -1;
    }
};