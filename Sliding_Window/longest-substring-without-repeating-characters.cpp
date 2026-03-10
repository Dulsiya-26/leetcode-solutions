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