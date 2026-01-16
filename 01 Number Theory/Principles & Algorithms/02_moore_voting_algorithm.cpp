#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
    Q. Given an array nums of size n, return the majority element. The majority element is the element that appears more than ⌊n / 2⌋ times. 
    You may assume that the majority element always exists in the array.

    > Intution:
        > Boyer–Moore Voting Algorithm
        
        If an element appears more than ⌊n/2⌋ times, it will survive pairwise cancellation against all other elements.
            1. Think of each majority element as a “vote”.
            2. Every different element cancels one vote.
            3. Since the majority element appears more than all others combined, it cannot be fully canceled.
    */

    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            
            if(candidate == num) count++;
            else count--;
        }
        
        return candidate;
    }
};
