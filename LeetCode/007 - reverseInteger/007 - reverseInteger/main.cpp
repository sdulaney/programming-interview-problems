//
//  main.cpp
//  007 - reverseInteger
//
//  Created by Stewart Dulaney on 8/7/19.
//  Copyright © 2019 Stewart Dulaney. All rights reserved.
//

#include <iostream>
#include <cassert>

/*
 Time Complexity: O(log_10(x))
 Space Complexity: O(1)
*/

int reverse(int x) {
    int reverse = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        if (reverse > INT_MAX/10 || (reverse == INT_MAX/10 && pop > 7)) {
            return 0;
        }
        if (reverse < INT_MIN/10 || (reverse == INT_MIN/10 && pop < -8)) {
            return 0;
        }
        reverse = reverse * 10 + pop;
    }
    return reverse;
}

int main(int argc, const char * argv[]) {
    
    assert(reverse(123) == 321);
    assert(reverse(-123) == -321);
    assert(reverse(120) == 21);
    
    return 0;
}
