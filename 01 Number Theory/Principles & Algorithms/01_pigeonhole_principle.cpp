#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
    Q. N-Repeated Element in Size 2N Array. (LEETCODE: 961)

    You are given an integer array nums with the following properties:
        1. nums.length == 2 * n.
        2. nums contains n + 1 unique elements.
        3. Exactly one element of nums is repeated n times.
        
    Return the element that is repeated n times.

    > Intution:
        The array contains 2n elements where one element repeats n times and all others appear once. This means the repeated element occupies exactly half the array.

        > Proof by Pigeonhole Principle:
            Given all other elements are distinct there exists a subsequence (or a subarray), where the repeated element must appear more than half.

            1. The repeated element takes up n out of 2n positions (half of the array).
            2. We pick the smallest meaningful subarray window size (3).
            3. Then, there exists a window where at least 2 out of 3 positions contain the repeated element.
            4. We, check if position i matches position i+1 or position i+2.
        
        > Edge Case
            Ex: [4,1,2,4]
            
            Since we only scanned up to length − 2, we can't reach the duplicate via comparison.

            However, the problem is guranteed to return the repeating element. The only remaining unchecked candidate is the last element. Therefore, it must be the repeated value.
    */

    int repeatedNTimes(vector<int>& nums) {
        for (int i=0; i<nums.size()-2; i++){
            if (nums[i]==nums[i+1] || nums[i]==nums[i+2])
                return nums[i];
        }

        return nums.back();
    }
};
