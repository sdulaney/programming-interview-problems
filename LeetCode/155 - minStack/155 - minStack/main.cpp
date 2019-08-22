//
//  main.cpp
//  155 - minStack
//
//  Created by Stewart Dulaney on 8/22/19.
//  Copyright © 2019 Stewart Dulaney. All rights reserved.
//

#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

/*
 Alg:
 Maintain one stack (vals) to hold all of the values. Maintain another stack (mins) which will have the minimum value at the top.
 
 push:
 if mins.empty()
    mins.push(x)
 else if x is <= mins.top()
    mins.push(x)
 vals.push(x)
 
 pop:
 if mins.empty()
    vals.pop()
 else if vals.top() == mins.top()
    vals.pop()
    mins.pop()
 else
    vals.pop()
 */

/*
 Time: O(1) for all methods
 Space: O(2n) = O(n)
*/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if (mins.empty()) {
            mins.push(x);
        }
        else if (x <= mins.top()) {
            mins.push(x);
        }
        vals.push(x);
    }
    
    void pop() {
        if (mins.empty()) {
            vals.pop();
        }
        else if (vals.top() == mins.top()) {
            vals.pop();
            mins.pop();
        }
        else {
            vals.pop();
        }
    }
    
    int top() {
        return vals.top();
    }
    
    int getMin() {
        return mins.top();
    }
    
    stack<int> vals;
    stack<int> mins;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(int argc, const char * argv[]) {
    
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    assert(obj->getMin() == -3);
    obj->pop();
    assert(obj->top() == 0);
    assert(obj->getMin() == -2);
    
    return 0;
}
