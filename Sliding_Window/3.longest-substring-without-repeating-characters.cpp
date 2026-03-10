// Problem: Longest Substring Without Repeating Characters
// Platform: LeetCode
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Problem Description:
// Given a string s, find the length of the longest substring
// without repeating characters.

// Approach:
// This solution uses a sliding window concept with a dynamic container (vector).
// We iterate through the string and store characters in a vector representing
// the current substring without duplicates.
//
// For each character:
// 1. Check if it already exists in the vector.
// 2. If a duplicate is found, remove all characters from the beginning
//    of the vector up to and including the duplicate.
// 3. Add the current character to the vector.
// 4. Update the current length and track the maximum length found.
//
// This ensures that the vector always stores a substring with unique characters.

// Time Complexity: O(n^2)
// Because for each character we may search the vector using find()
// and erase elements, which can take linear time.

// Space Complexity: O(n)
// In the worst case, the vector stores all unique characters of the string.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int maxLen = 0, curLen = 0;
        vector<char> v1;
        for (int i = 0; i < len; i++) {
            auto it = find(v1.begin(), v1.end(), s[i]);
            if (it != v1.end()) {
                // Erase from the beginning to the duplicate (inclusive)
                v1.erase(v1.begin(), it + 1);
                curLen = v1.size();  // reset current length after erasure
            }
            v1.push_back(s[i]);
            curLen++;
            if (curLen > maxLen)
                maxLen = curLen;
        }
        return maxLen;
    }
};
