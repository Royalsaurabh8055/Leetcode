
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        int n = s.length();
        int wordCount = words.size();
        int wordLen = words[0].size();

        unordered_map<string,int> target;

        for(auto &word : words)
        {
            target[word]++;
        }

        // Try all possible starting offsets
        for(int offset = 0; offset < wordLen; offset++)
        {
            unordered_map<string,int> seen;

            int left = offset;
            int count = 0;

            for(int right = offset; right + wordLen <= n; right += wordLen)
            {
                string word = s.substr(right, wordLen);

                if(target.count(word))
                {
                    seen[word]++;
                    count++;

                    while(seen[word] > target[word])
                    {
                        string leftWord = s.substr(left, wordLen);

                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if(count == wordCount)
                    {
                        ans.push_back(left);

                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                }
                else
                {
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return ans;
    }
};