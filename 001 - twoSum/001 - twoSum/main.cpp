//
//  main.cpp
//  001 - twoSum
//
//  Created by Stewart Dulaney on 8/7/19.
//  Copyright © 2019 Stewart Dulaney. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;

/*
 Time Complexity: O(n)
 Space Complexity: O(n)
*/

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> umap;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (umap.find(complement) != umap.end()) {
            result = {umap[complement], i};
            return result;
        }
        umap[nums[i]] = i;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
    vector<int> nums = {2, 7, 11, 15};
    vector<int> solution = {0, 1};
    assert(twoSum(nums, 9) == solution);
    
    return 0;
}
