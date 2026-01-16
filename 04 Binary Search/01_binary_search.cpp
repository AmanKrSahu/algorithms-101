#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
    Q. Search for a target value in a sorted array using binary search. (LEETCODE: 704)
    */

    int binarySearch(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        
        return -1;
    }

    /*
    Q. Find the lower bound of a target value in a sorted array using binary search.

    > Intution:
        1. The lower bound is the smallest index (idx) where arr[idx] >= target.
    */

    int lowerbound(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] >= target) r = mid - 1;
            else l = mid + 1;
        }

        return l;
    }

    /*
    Q. Find the upper bound of a target value in a sorted array using binary search.

    > Intution:
        1. The upper bound is the smallest index (idx) where arr[idx] > target.
    */

    int upperbound(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] <= target) l = mid + 1;
            else r = mid - 1;
        }

        return l;
    }
};
