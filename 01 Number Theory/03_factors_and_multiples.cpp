#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
    Q. Find all divisors of a number.
    */

    vector<int> divisors(int n) {
        vector<int> ans;
        
        for (int i=1; i*i<=n; i++) {
            if (n % i == 0) {
                ans.push_back(i);
                
                if (i != n/i) ans.push_back(n/i);
            }
        }
        
        return ans;
    }

    /*
    Q. Check if a number is prime.
    */

    bool isPrime(int n) {
        if(n == 1) return false;
        
        for(int i=2; i*i<=n; i++) {
            if(n % i == 0) return false;
        }
        
        return true;
    }

    /*
    Q. Find the GCD or HCF of two numbers.

    > Euclidean Algorithm:
        The Euclidean Algorithm is a method for finding the greatest common divisor (GCD)
        of two numbers. It operates on the principle that the GCD of two numbers remains
        the same even if the smaller number is subtracted from the larger number.

        To find the GCD of n1 and n2 where n1 > n2:
            1. Repeatedly subtract the smaller number from the larger number until one of them becomes 0.
            2. Once one becomes 0, the other is the GCD of the original numbers.
    */

    int gcd(int a, int b) {
        while (a != 0 && b != 0) {
            if (a > b) a %= b;
            else b %= a;
        }

        return a == 0 ? b : a;
    }
};
