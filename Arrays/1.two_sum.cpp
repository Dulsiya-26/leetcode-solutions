// Problem: Two Sum
// Platform: LeetCode
// Link: https://leetcode.com/problems/two-sum/

// Problem Description:
// Given an array of integers nums and an integer target,
// return the indices of the two numbers such that they add up to target.
// You may assume that each input has exactly one solution,
// and you may not use the same element twice.

// Approach:
// This solution uses a brute-force approach.
// We check every pair of elements in the array using two loops.
// For each element nums[i], we compare it with the remaining elements nums[j].
// If nums[i] + nums[j] equals the target, we return their indices.

// Time Complexity: O(n^2)
// Because we use two nested loops to check all possible pairs.

// Space Complexity: O(1)
// No extra space is used except for the returned result.
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // Return empty vector if no solution is found
    }
};
