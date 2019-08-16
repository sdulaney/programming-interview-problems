//
//  main.cpp
//  020 - validParentheses
//
//  Created by Stewart Dulaney on 8/16/19.
//  Copyright © 2019 Stewart Dulaney. All rights reserved.
//

#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

/*
 Let n be the number of characters in the string s.
 Time Complexity: O(n)
 Space Complexity: O(n)
 */

/*
 Pseudocode:
 for each character c in s
    if c is an opening brace
        push it on the stack
    else if it is a closing brace
        if it's the matching brace to top()
            pop() the stack
        else
            return false
 if stack is not empty
    return false
 return true
*/

bool isValid(string s) {
    stack<char> openingParens;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            openingParens.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (!openingParens.empty()) {
                if (openingParens.top() == '(' && s[i] == ')') {
                    openingParens.pop();
                }
                else if (openingParens.top() == '{' && s[i] == '}') {
                    openingParens.pop();
                }
                else if (openingParens.top() == '[' && s[i] == ']') {
                    openingParens.pop();
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }
    if (!openingParens.empty()) {
        return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
   
    assert(isValid("()") == true);
    assert(isValid("()[]{}") == true);
    assert(isValid("(]") == false);
    assert(isValid("([)]") == false);
    assert(isValid("{[]}") == true);

    return 0;
}
