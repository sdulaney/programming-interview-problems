//
//  main.cpp
//  012 - integerToRoman
//
//  Created by Stewart Dulaney on 8/8/19.
//  Copyright © 2019 Stewart Dulaney. All rights reserved.
//

#include <iostream>
#include <cassert>

using namespace std;

/*
 Time Complexity: O(1)
 Space Complexity: O(1)
*/

string intToRoman(int num) {
    int nums[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string symbols[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    string result = "";
    int i = 12;
    while (num > 0) {
        int quotient = num / nums[i];
        num = num % nums[i];
        for (int j = 0; j < quotient; j++) {
            result += symbols[i];
        }
        i--;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
    assert(intToRoman(3) == "III");
    assert(intToRoman(4) == "IV");
    assert(intToRoman(9) == "IX");
    assert(intToRoman(58) == "LVIII");
    assert(intToRoman(1994) == "MCMXCIV");

    return 0;
}
