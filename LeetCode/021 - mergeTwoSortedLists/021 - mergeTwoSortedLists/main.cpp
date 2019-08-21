//
//  main.cpp
//  021 - mergeTwoSortedLists
//
//  Created by Stewart Dulaney on 8/19/19.
//  Copyright © 2019 Stewart Dulaney. All rights reserved.
//

#include <iostream>

/*
 2) Example:
 
    Input: 1->5->6->8->10, 1->2->5->6->7->11
    Output: 1->1->2->5->5->6->6->7->8->10->11
 
 3) Alg:
 if l1 is NULL
    return l2
 else if l2 is NULL
    return l1
 else if l1->val <= l2->val
    l1->next = mergeTwoLists(l1->next, l2)
    return l1
 else
    l2->next = mergeTwoLists(l1, l2->next)
    return l2
 
 
 Let m = # of nodes in l1, n = # of nodes in l2.
 Time: O(m + n)
 Space: O(m + n) stack frames
 
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) {
        return l2;
    }
    else if (l2 == NULL) {
        return l1;
    }
    else if (l1->val <= l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
