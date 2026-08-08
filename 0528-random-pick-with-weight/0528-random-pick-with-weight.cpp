class Solution {
public:
    vector<int> prefix;

    Solution(vector<int>& w) {

        prefix.push_back(w[0]);

        for (int i = 1; i < w.size(); i++) {
            prefix.push_back(prefix.back() + w[i]);
        }
    }

    int pickIndex() {

        int total = prefix.back();

        int randomNumber = rand() % total + 1;

        int left = 0;
        int right = prefix.size() - 1;

        while (left < right) {

            int mid = left + (right - left) / 2;

            if (prefix[mid] >= randomNumber)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};