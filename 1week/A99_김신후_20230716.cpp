/*
20. Valid Parentheses
Easy
20.8K
1.3K
Companies
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> pt;
        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                pt.push(c);
            } else{
                if (pt.empty()) {
                    return false;
                }
                switch(pt.top()){
                    case '(':
                        if(c != ')') return false;
                        break;
                    case '{':
                        if(c != '}') return false;
                        break;
                    case '[':
                        if(c != ']') return false;
                        break;
                }
                pt.pop();
            }
        }
        return pt.empty();
    }
};