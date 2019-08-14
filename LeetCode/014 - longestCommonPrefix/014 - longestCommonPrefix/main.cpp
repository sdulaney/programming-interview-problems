//
//  main.cpp
//  014 - longestCommonPrefix
//
//  Created by Stewart Dulaney on 8/12/19.
//  Copyright © 2019 Stewart Dulaney. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/*
 Let n be the number of strings in the array of strings.
 Let m be the maximum number of characters in any string in the array.
 Time Complexity: O(m * n)
 Space Complexity: O(1)
 */

string longestCommonPrefix(vector<string>& strs) {
    string result = "";
    if (strs.size() == 0) {
        return result;
    }
    for (int i = 0; i < strs[0].length(); i++) {
        for (int j = 1; j < strs.size(); j++) {
            if (i >= strs[j].length() || strs[j][i] != strs[0][i]) {
                return result;
            }
        }
        result += strs[0][i];
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
    vector<string> input1 = {"flower", "flow", "flight"};
    assert(longestCommonPrefix(input1) == "fl");
    vector<string> input2 = {"dog","racecar","car"};
    assert(longestCommonPrefix(input2) == "");
    
    return 0;
}
