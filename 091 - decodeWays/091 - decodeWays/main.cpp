//
//  main.cpp
//  091 - decodeWays
//
//  Created by Stewart Dulaney on 12/30/19.
//  Copyright © 2019 Stewart Dulaney. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

/*
 Let n be the number of characters in s.
 Time: O(n)
 Space: O(n)
 */

int numDecodings(string s) {
    int arr[s.length() + 1];
    arr[0] = 1;
    arr[1] = s[0] == '0' ? 0 : 1;
    for (int i = 2; i <= s.length(); i++) {
        arr[i] = 0;
        int oneDigit = stoi(s.substr(i - 1, 1));
        int twoDigits = stoi(s.substr(i - 2, 2));
        if (oneDigit != 0) {
            arr[i] += arr[i - 1];
        }
        if (twoDigits >= 10 && twoDigits <= 26) {
            arr[i] += arr[i - 2];
        }
    }
    return arr[s.length()];
}

int main(int argc, const char * argv[]) {
    cout << numDecodings("12") << endl;
    
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
