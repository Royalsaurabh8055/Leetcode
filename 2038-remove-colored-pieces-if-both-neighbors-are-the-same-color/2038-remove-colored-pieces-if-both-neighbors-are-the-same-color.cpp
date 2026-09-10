class Solution {
public:
    bool winnerOfGame(string colors) {

        int alice = 0;
        int bob = 0;

        for (int i = 1; i < colors.length() - 1; i++) {

            // Alice can remove this A
            if (colors[i - 1] == 'A' &&
                colors[i] == 'A' &&
                colors[i + 1] == 'A') {
                
                alice++;
            }

            // Bob can remove this B
            if (colors[i - 1] == 'B' &&
                colors[i] == 'B' &&
                colors[i + 1] == 'B') {
                
                bob++;
            }
        }

        return alice > bob;
    }
};