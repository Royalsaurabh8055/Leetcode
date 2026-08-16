class Solution {
public:
    string countOfAtoms(string formula) {

        // Stack stores atom-frequency maps
        // for different levels of parentheses
        stack<map<string, int>> st;

        st.push(map<string, int>());

        int n = formula.size();
        int i = 0;

        while (i < n) {

            // Opening parenthesis
            if (formula[i] == '(') {

                st.push(map<string, int>());
                i++;
            }

            // Closing parenthesis
            else if (formula[i] == ')') {

                // Get the map inside parentheses
                map<string, int> current = st.top();
                st.pop();

                i++; // skip ')'

                // Read multiplier
                int multiplier = 0;

                while (i < n && isdigit(formula[i])) {
                    multiplier = multiplier * 10 + (formula[i] - '0');
                    i++;
                }

                // No number means multiplier = 1
                if (multiplier == 0)
                    multiplier = 1;

                // Add multiplied atoms to outer scope
                for (auto& [atom, count] : current) {
                    st.top()[atom] += count * multiplier;
                }
            }

            // Atom
            else {

                string atom;

                // First character is uppercase
                atom += formula[i];
                i++;

                // Following lowercase characters
                while (i < n && islower(formula[i])) {
                    atom += formula[i];
                    i++;
                }

                // Read atom count
                int count = 0;

                while (i < n && isdigit(formula[i])) {
                    count = count * 10 + (formula[i] - '0');
                    i++;
                }

                // No number means count = 1
                if (count == 0)
                    count = 1;

                st.top()[atom] += count;
            }
        }

        // map automatically keeps atoms sorted
        string ans;

        for (auto& [atom, count] : st.top()) {

            ans += atom;

            if (count > 1)
                ans += to_string(count);
        }

        return ans;
    }
};