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
 Time Complexity: O(log_10(n))
 Space Complexity: O(1)
 */

bool isPalindrome(int x) {
    // Special cases:
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }
    // Revert half of the number to avoid overflow
    int revertedNumber = 0;
    while (x > revertedNumber) {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }
    // When length is odd the middle digit is appended to revertedNumber, but doesn't matter
    return x == revertedNumber || x == revertedNumber / 10;
}

int main(int argc, const char * argv[]) {
    
    assert(isPalindrome(121) == true);
    assert(isPalindrome(-121) == false);
    assert(isPalindrome(10) == false);
    
    return 0;
}
