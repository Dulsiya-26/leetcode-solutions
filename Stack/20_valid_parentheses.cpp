/*# Valid Parentheses

## Problem

Given a string containing the characters `()`, `{}`, and `[]`, determine if the input string is valid.

A string is valid if:

* Open brackets are closed by the same type.
* Open brackets are closed in the correct order.

## Approach

Use a **stack** to store opening brackets.

* Push opening brackets `(` `{` `[` into the stack.
* When a closing bracket appears, check the top of the stack.
* If it matches, pop it; otherwise return false.
* At the end, the stack should be empty for the string to be valid.

## Complexity

* Time Complexity: **O(n)**
* Space Complexity: **O(n)**

## Language

C++
*/

class Solution {
public:
    bool isValid(const string& s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else { 
                if (st.empty()) return false;
                char t = st.top();
                if ((t == '(' && c == ')') ||
                    (t == '{' && c == '}') ||
                    (t == '[' && c == ']')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
