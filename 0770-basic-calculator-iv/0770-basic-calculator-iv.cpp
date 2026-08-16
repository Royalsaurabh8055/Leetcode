class Solution {
public:
    // A "Poly" is a map from sorted variable-list (a term) -> coefficient
    // Term key: vector<string> of variable names, sorted lexicographically
    // We use a map<vector<string>, int> keyed by term for easy addition/multiplication
    
    using Term = vector<string>;
    using Poly = map<Term, int>;
    
    unordered_map<string, int> evalMap;
    string expr;
    int pos;
    
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        expr = expression;
        pos = 0;
        for (int i = 0; i < evalvars.size(); i++) {
            evalMap[evalvars[i]] = evalints[i];
        }
        
        Poly result = parseExpr();
        return formatResult(result);
    }
    
private:
    // Add poly b into poly a (a += b)
    void addTo(Poly& a, const Poly& b, int sign = 1) {
        for (auto& [term, coef] : b) {
            a[term] += sign * coef;
            if (a[term] == 0) a.erase(term);
        }
    }
    
    // Multiply two term keys together (merge variable lists, keep sorted)
    Term mulTerm(const Term& t1, const Term& t2) {
        Term result = t1;
        result.insert(result.end(), t2.begin(), t2.end());
        sort(result.begin(), result.end());
        return result;
    }
    
    // Multiply two polynomials
    Poly mulPoly(const Poly& a, const Poly& b) {
        Poly result;
        for (auto& [t1, c1] : a) {
            for (auto& [t2, c2] : b) {
                Term t = mulTerm(t1, t2);
                result[t] += c1 * c2;
                if (result[t] == 0) result.erase(t);
            }
        }
        return result;
    }
    
    void skipSpace() {
        while (pos < expr.size() && expr[pos] == ' ') pos++;
    }
    
    // parseExpr handles + and -
    Poly parseExpr() {
        Poly result = parseTerm();
        skipSpace();
        while (pos < expr.size() && (expr[pos] == '+' || expr[pos] == '-')) {
            char op = expr[pos];
            pos++; // skip operator
            skipSpace();
            Poly next = parseTerm();
            if (op == '+') addTo(result, next, 1);
            else addTo(result, next, -1);
            skipSpace();
        }
        return result;
    }
    
    // parseTerm handles *
    Poly parseTerm() {
        Poly result = parseFactor();
        skipSpace();
        while (pos < expr.size() && expr[pos] == '*') {
            pos++; // skip *
            skipSpace();
            Poly next = parseFactor();
            result = mulPoly(result, next);
            skipSpace();
        }
        return result;
    }
    
    // parseFactor handles numbers, variables, and parenthesized expressions
    Poly parseFactor() {
        skipSpace();
        Poly result;
        
        if (expr[pos] == '(') {
            pos++; // skip (
            result = parseExpr();
            skipSpace();
            pos++; // skip )
        } else if (isdigit(expr[pos])) {
            int num = 0;
            while (pos < expr.size() && isdigit(expr[pos])) {
                num = num * 10 + (expr[pos] - '0');
                pos++;
            }
            if (num != 0) {
                result[Term()] = num; // empty term = constant
            }
        } else {
            // variable
            int start = pos;
            while (pos < expr.size() && islower(expr[pos])) pos++;
            string var = expr.substr(start, pos - start);
            
            if (evalMap.count(var)) {
                int val = evalMap[var];
                if (val != 0) {
                    result[Term()] = val;
                }
            } else {
                result[Term({var})] = 1;
            }
        }
        
        return result;
    }
    
    vector<string> formatResult(Poly& poly) {
        // Sort terms by: degree descending, then lexicographic order of variables
        vector<pair<Term, int>> terms(poly.begin(), poly.end());
        
        sort(terms.begin(), terms.end(), [](const pair<Term,int>& a, const pair<Term,int>& b) {
            if (a.first.size() != b.first.size()) 
                return a.first.size() > b.first.size(); // higher degree first
            return a.first < b.first; // lexicographic
        });
        
        vector<string> res;
        for (auto& [term, coef] : terms) {
            if (coef == 0) continue;
            string s = to_string(coef);
            for (auto& var : term) {
                s += "*" + var;
            }
            res.push_back(s);
        }
        return res;
    }
};