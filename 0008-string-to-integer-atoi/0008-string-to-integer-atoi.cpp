class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();

        while ( i < n && s[i] == ' ') {
            i++;
        }

        int sign = 1;

        if ( i < n && s[i] == '-' ) {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }
        long long result = 0;
        while ( i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            result = result * 10 + digit;

            if (sign == 1 && result > INT_MAX) {
                return INT_MAX;
            }

            if (sign == -1 && -result < INT_MIN) {
                return INT_MIN;
            }
            i++;
        }
        return (int)(result * sign );
    }
};