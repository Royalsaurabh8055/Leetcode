class Solution {
public:
    vector<string> printVertically(string s) {

        stringstream ss(s);
        vector<string> words;
        string word;

        while(ss >> word) {
            words.push_back(word);
        }

        int maxLen = 0;

        for(string &w : words) {
            maxLen = max(maxLen, (int)w.size());
        }

        vector<string> ans;

        for(int col = 0; col < maxLen; col++) {

            string temp = "";

            for(int row = 0; row < words.size(); row++) {

                if(col < words[row].size())
                    temp += words[row][col];
                else
                    temp += ' ';
            }

            // Remove trailing spaces
            while(!temp.empty() && temp.back() == ' ')
                temp.pop_back();

            ans.push_back(temp);
        }

        return ans;
    }
};