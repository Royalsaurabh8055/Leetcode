class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {

        vector<string> letterLogs;
        vector<string> digitLogs;

        // Separate letter logs and digit logs
        for (string log : logs) {

            int pos = log.find(' ');

            // Character after the identifier
            char firstChar = log[pos + 1];

            if (isdigit(firstChar)) {
                digitLogs.push_back(log);
            }
            else {
                letterLogs.push_back(log);
            }
        }

        // Sort letter logs
        sort(letterLogs.begin(), letterLogs.end(),
            [](string a, string b) {

                // Get everything after identifier
                string contentA = a.substr(a.find(' ') + 1);
                string contentB = b.substr(b.find(' ') + 1);

                // If contents are same,
                // compare identifiers
                if (contentA == contentB) {
                    return a < b;
                }

                return contentA < contentB;
            }
        );

        // Answer starts with letter logs
        // and then digit logs
        vector<string> answer;

        for (string log : letterLogs) {
            answer.push_back(log);
        }

        for (string log : digitLogs) {
            answer.push_back(log);
        }

        return answer;
    }
};