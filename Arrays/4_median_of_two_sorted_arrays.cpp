// Problem: Median of Two Sorted Arrays
// Platform: LeetCode
// Link: https://leetcode.com/problems/median-of-two-sorted-arrays/

// Problem Description:
// Given two sorted arrays nums1 and nums2 of size m and n respectively,
// return the median of the two sorted arrays.
// The overall run time complexity should ideally be O(log (m+n)).

// Approach:
// This solution uses a simple merge technique similar to the merge step
// of Merge Sort.
//
// 1. Traverse both sorted arrays using two pointers.
// 2. Compare elements and insert the smaller one into a new vector.
// 3. Continue until all elements from both arrays are merged.
// 4. Once the merged sorted array is obtained, calculate the median.
//    - If the total number of elements is odd, return the middle element.
//    - If even, return the average of the two middle elements.

// Time Complexity: O(m + n)
// Because we traverse both arrays once to merge them.

// Space Complexity: O(m + n)
// A new vector is used to store the merged elements.

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int i = 0, j = 0;

        // merge both arrays
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                result.push_back(nums1[i++]);
            } else {
                result.push_back(nums2[j++]);
            }
        }

        // add remaining elements
        while (i < nums1.size()) {
            result.push_back(nums1[i++]);
        }

        while (j < nums2.size()) {
            result.push_back(nums2[j++]);
        }

        int n = result.size();

        // find median
        if (n % 2 != 0) {
            return result[n / 2];
        } else {
            return (result[n / 2 - 1] + result[n / 2]) / 2.0;
        }
    }
};