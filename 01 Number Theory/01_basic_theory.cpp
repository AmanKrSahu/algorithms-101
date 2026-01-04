#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    """
    Q. Count the number of digits in a number.
    """

    int countDigits(int num) {
        int ans = (int)log10(num) + 1;
        return ans;
    }

    """
    Q. Reverse a number (both positive and negative). (LEETCODE: 7)

    > Constraints: -2^31 <= x <= 2^31 - 1
    """

    int reverseNumber(int num) {
        int ans = 0;
        
        while (num != 0) {
            int digit = num % 10;

            if (ans > INT_MAX/10 || (ans == INT_MAX/10 && digit > 7)) return 0;
            if (ans < INT_MIN/10 || (ans == INT_MIN/10 && digit < -8)) return 0;

            ans = ans * 10 + digit;
            num /= 10;
        }
        
        return ans;
    }

    """
    Q. Check if a number is a palindrome. (LEETCODE: 9)
    """

    bool checkPalindrome(int num) {
        if (num < 0 || (num%10 == 0 && num != 0)) return false;

        int rev = 0;
        
        while (num > rev) {
            int digit = num % 10;
            rev = rev * 10 + digit;
            num /= 10;
        }

        return num == rev || num == rev/10;
    }
};
