#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
    Q. Search in a Rotated Sorted Array (LEETCODE: 33)
    */

    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;

        while (l <= r) {
            int mid = l + (r - l)/2;

            if(nums[mid] == target) return mid;
            else if(nums[l] <= nums[mid]) {
                if(nums[l] <= target && nums[mid] >= target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            else {
                if(nums[mid] <= target && nums[r] >= target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return -1;
    }

    /*
    Q. Search in a Rotated Sorted Array with Duplicates (LEETCODE: 81)

    > Edge Cases:
        1. nums[l] == nums[mid] == nums[r] (e.g., [1, 1, 1, 1, 1])

        Here, we cannot determine which part is sorted, so we move both l and r inward.
    */

    bool search(vector<int>& nums, int target) {
       int l = 0, r = nums.size() - 1;

       while(l <= r) {
            int mid = l + (r - l)/2;

            if(nums[mid] == target) return true;
            else if(nums[l] == nums[mid] && nums[mid] == nums[r]) {
                l += 1;
                r -= 1;
                continue;
            }
            else if(nums[l] <= nums[mid]) {
                if(nums[l] <= target && nums[mid] >= target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            else {
                if(nums[mid] <= target && nums[r] >= target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
       }

       return false; 
    }
};
