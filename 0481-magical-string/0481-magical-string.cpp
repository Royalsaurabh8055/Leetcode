class Solution {
public:
    int magicalString(int n) {

        if (n <= 0)
            return 0;

        if (n <= 3)
            return 1;

        string s = "122";

        int i = 2;

        while (s.length() < n) {

            // Last number kya tha?
            // Agar 1 tha to next 2 hoga
            // Agar 2 tha to next 1 hoga
            char next = (s.back() == '1') ? '2' : '1';

            // s[i] batayega next number kitni baar add karna hai
            int count = s[i] - '0';

            for (int j = 0; j < count; j++) {
                s += next;
            }

            i++;
        }

        int ans = 0;

        // First n characters me kitne '1' hain
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                ans++;
        }

        return ans;
    }
};