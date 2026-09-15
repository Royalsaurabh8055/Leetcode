class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {

        vector<int> time;

        // Convert HH:MM into minutes
        for(string s : timePoints) {

            int hours = stoi(s.substr(0, 2));
            int minutes = stoi(s.substr(3, 2));

            time.push_back(hours * 60 + minutes);
        }

        sort(time.begin(), time.end());

        int ans = INT_MAX;

        // Difference between adjacent times
        for(int i = 1; i < time.size(); i++) {
            ans = min(ans, time[i] - time[i - 1]);
        }

        // Difference between last and first
        // because clock is circular
        int circular = 1440 - time.back() + time[0];

        ans = min(ans, circular);

        return ans;
    }
};