//
//  main.cpp
//  009 - palindromeNumber
//
//  Created by Stewart Dulaney on 8/12/19.
//  Copyright © 2019 Stewart Dulaney. All rights reserved.
//

#include <iostream>
#include <cassert>

using namespace std;

/*
 Let n be the number of digits/characters in x
 Time Complexity: O(n/2) = O(n)
 Space Complexity: O(1)
 */

bool isPalRec(string str) {
    int len = str.length();
    // Base cases
    if (len == 0 || len == 1) {
        return true;
    }
    if (str[0] == str[len - 1]) {
        return isPalRec(str.substr(1, len - 2));
    }
    return false;
}

bool isPalindrome(int x) {
    string str = to_string(x);
    return isPalRec(str);
}

int main(int argc, const char * argv[]) {
    
    assert(isPalindrome(121) == true);
    assert(isPalindrome(-121) == false);
    assert(isPalindrome(10) == false);
    
    return 0;
}
