#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    """
    Q. Rotate an array to the right by k steps.

    1. A right rotation by k means the last k elements must move to the front while preserving order.
    2. Instead of shifting elements one by one (inefficient), we use array reversal to reposition elements in bulk.
    3. By reversing the entire array, the elements that must appear in front are brought forward, then two targeted reversals restore the correct internal order.
    """

    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
