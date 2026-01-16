#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
    Q. Find the minimum element in a rotated sorted array. (LEETCODE: 153)
    */

    int findMin(vector<int>& nums) {
        int ans = INT_MAX, l = 0, r = nums.size()-1;

        while(l <= r) {
            int mid = l + (r - l)/2;

            if(nums[l] <= nums[mid]) {
                ans = min(ans, nums[l]);
                l = mid + 1;
            } else {
                ans = min(ans, nums[mid]);
                r = mid - 1;
            }
        }

        return ans;
    }
    /*
    Q. Find the single non-duplicate element in an array. (LEETCODE: 540)

    > Intution: 
        In a sorted array where every element appears twice except one.
            1. Before the single element, pairs start at even indices.
            2. After the single element, pairs start at odd indices.

        This creates a parity break at the single element.

        At any index mid:

        1. If mid is even:
            > Normally, nums[mid] == nums[mid + 1]

        2. If mid is odd:
            > Normally, nums[mid] == nums[mid - 1]

        When this pattern breaks, the single element lies at or to the left of mid. So,

        1. If the parity alignment is correct, move right
        2. If the parity alignment is broken, move left

    > Edge Cases:
        1. Array of size 1
            > The only element is the answer.

        2. Single element at the beginning
            > Detected when nums[mid] is different from both neighbors.

        3. Single element at the end
            > Detected when nums[mid] is different from both neighbors.

        4. Single element in the middle
            > Detected when nums[mid] is different from both neighbors.

        5. Boundary protection
            > Search range limited to [1, n-2] to safely access mid-1 and mid+1.
    */

    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        int l = 1, r = n - 2;

        while(l <= r) {
            int mid = l + (r - l)/2;

            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
            else if((mid%2 == 0 && nums[mid] == nums[mid-1]) || (mid%2 == 1 && nums[mid] == nums[mid+1])) r = mid - 1;
            else l = mid + 1;
        }

        return -1;
    }

    /*
    Q. Find the peak element in an array. (LEETCODE: 162)

    > Intution:
        1. Peak element is greater than its neighbors.
        2. If mid is peak, return mid.
        3. If mid is not peak, move to the side where the neighbor is greater.

    > Edge Cases:
        1. Array of size 1
            > The only element is the answer.

        2. Peak element at the beginning
            > Detected when nums[mid] is greater than nums[mid+1].

        3. Peak element at the end
            > Detected when nums[mid] is greater than nums[mid-1].

        4. Peak element in the middle
            > Detected when nums[mid] is greater than both neighbors.

        5. Boundary protection
            > Search range limited to [1, n-2] to safely access mid-1 and mid+1.
    */

    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if(nums.size() == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;

        int l = 1, r = n - 2;

        while(l <= r) {
            int mid = l + (r - l)/2;

            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            else if(nums[mid] > nums[mid-1]) l = mid + 1;
            else r = mid - 1;
        }

        return -1;
    }
};
