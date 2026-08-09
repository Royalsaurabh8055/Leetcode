class Solution {
public:
    string nearestPalindromic(string n) {
        int length = n.length();
        long long num = stoll(n);
        
        set<long long> candidates;
        
        // 1. All 9s with one less digit (e.g., 999 for length 4)
        candidates.insert((long long)pow(10, length - 1) - 1);
        
        // 2. 1 followed by zeros followed by 1, one more digit (e.g., 10001 for length 4)
        candidates.insert((long long)pow(10, length) + 1);
        
        // 3. Mirror the first half with delta -1, 0, +1
        string prefix = n.substr(0, (length + 1) / 2);
        long long prefixNum = stoll(prefix);
        
        for (long long delta : {-1LL, 0LL, 1LL}) {
            string newPrefix = to_string(prefixNum + delta);
            string candidateStr;
            
            if (length % 2 == 0) {
                string rev = newPrefix;
                reverse(rev.begin(), rev.end());
                candidateStr = newPrefix + rev;
            } else {
                string toReverse = newPrefix.substr(0, newPrefix.length() - 1);
                string rev = toReverse;
                reverse(rev.begin(), rev.end());
                candidateStr = newPrefix + rev;
            }
            
            if (!candidateStr.empty()) {
                candidates.insert(stoll(candidateStr));
            }
        }
        
        // Remove the original number itself
        candidates.erase(num);
        
        // Pick the candidate with minimum absolute difference,
        // and in case of tie, the smaller value
        long long best = -1;
        bool first = true;
        
        for (long long c : candidates) {
            if (c < 0) continue;
            
            if (first) {
                best = c;
                first = false;
            } else {
                long long diffC = abs(c - num);
                long long diffBest = abs(best - num);
                if (diffC < diffBest || (diffC == diffBest && c < best)) {
                    best = c;
                }
            }
        }
        
        return to_string(best);
    }
};