class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {

        long long total = 0;
        long long maximum = 0;

        // Find total milestones
        // and the project with maximum milestones
        for (int x : milestones) {
            total += x;
            maximum = max(maximum, (long long)x);
        }

        // Milestones belonging to all other projects
        long long other = total - maximum;

        // If maximum project is too large,
        // we must alternate:
        // maximum, other, maximum, other...
        if (maximum > other + 1) {
            return other * 2 + 1;
        }

        // Otherwise, we can finish everything
        return total;
    }
};