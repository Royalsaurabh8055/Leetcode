class Solution {
public:
    string fractionAddition(string expression) {
        long long numResult = 0, denResult = 1;
        int i = 0, n = expression.length();
        
        while (i < n) {
            // Parse sign
            long long sign = 1;
            if (expression[i] == '+' || expression[i] == '-') {
                if (expression[i] == '-') sign = -1;
                i++;
            }
            
            // Parse numerator
            long long num = 0;
            while (i < n && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            num *= sign;
            
            // Skip '/'
            i++; // move past '/'
            
            // Parse denominator
            long long den = 0;
            while (i < n && isdigit(expression[i])) {
                den = den * 10 + (expression[i] - '0');
                i++;
            }
            
            // Add fraction num/den to result
            numResult = numResult * den + num * denResult;
            denResult = denResult * den;
            
            // Reduce fraction to keep numbers manageable
            long long g = gcd(abs(numResult), denResult);
            if (g != 0) {
                numResult /= g;
                denResult /= g;
            }
        }
        
        return to_string(numResult) + "/" + to_string(denResult);
    }
    
private:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
};