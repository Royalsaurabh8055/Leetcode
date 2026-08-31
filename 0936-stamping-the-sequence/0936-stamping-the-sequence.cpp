class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {

        int m = stamp.size();
        int n = target.size();

        vector<int> answer;

        // Keep track of positions that became '?'
        vector<bool> done(n, false);

        int count = 0;

        // Keep trying to remove the stamp
        while (count < n) {

            bool found = false;

            for (int i = 0; i <= n - m; i++) {

                if (canStamp(stamp, target, done, i)) {

                    // Remove this part
                    for (int j = 0; j < m; j++) {

                        if (!done[i + j]) {
                            done[i + j] = true;
                            count++;
                        }
                    }

                    answer.push_back(i);
                    found = true;
                }
            }

            // We could not make any progress
            if (!found) {
                return {};
            }
        }

        // We worked backwards,
        // so reverse the answer
        reverse(answer.begin(), answer.end());

        return answer;
    }

    bool canStamp(
        string stamp,
        string target,
        vector<bool>& done,
        int start
    ) {

        bool hasNewCharacter = false;

        for (int j = 0; j < stamp.size(); j++) {

            // If this position is already removed,
            // we don't care about it.
            if (done[start + j]) {
                continue;
            }

            // Otherwise it must match the stamp
            if (target[start + j] != stamp[j]) {
                return false;
            }

            hasNewCharacter = true;
        }

        return hasNewCharacter;
    }
};