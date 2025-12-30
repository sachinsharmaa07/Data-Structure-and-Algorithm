#include<iostream>
using namespace std;
#include<stack>
#include<limits.h>

// MinStack implementation using space-optimized encoding
// Instead of storing pairs (value, min), we encode the minimum value within the stack values
// Time Complexity: O(1) for all operations
// Space Complexity: O(n) where n is the number of elements
class MinStack {
public:
    stack<long long> s;  // Use long long to prevent integer overflow during encoding
    long long minVal;    // Tracks the current minimum value
    
    // Constructor: Initialize the MinStack
    MinStack() {
        // No initialization needed; stack is empty and minVal will be set on first push
    }
    
    // push(val): Add an element to the stack while maintaining minimum value info
    // If val is the new minimum, we encode it as 2*val - old_minVal to distinguish it
    void push(int val) {
        // First element: just push it and update minVal
        if(s.empty()){
            s.push(val);
            minVal = val;
        }
        else {
            // If new value is smaller than current minimum, encode it
            // Formula: 2*val - minVal results in a value less than minVal
            // This allows us to detect encoded values later during pop/top operations
            if(val < minVal){
                s.push(2LL * val - minVal);  // Cast to long long to avoid overflow
                minVal = val;  // Update minimum
            }
            else {
                // Regular value: just push as is
                s.push(val);
            }
        }
    }
    
    // pop(): Remove the top element and update minVal if needed
    void pop() {
        // If top element is less than minVal, it means this is an encoded value
        // We need to restore the previous minimum value
        if(s.top() < minVal){
            // Decode: extract previous minVal from the formula 2*val - minVal
            // Previous minVal = 2*minVal - encoded_value
            minVal = 2 * minVal - s.top();
        }
        // Remove the top element from stack (for both encoded and regular values)
        s.pop();
    }
    
    // top(): Return the actual top element without removing it
    // If the value is encoded (< minVal), return the true minimum
    int top() {
        // If top element is less than minVal, it's an encoded value
        // The actual value we should return is the current minVal
        if(s.top() < minVal){
            return (int)minVal;
        }
        // Regular value: return as is
        return (int)s.top();
    }
    
    // getMin(): Return the current minimum value in the stack
    int getMin() {
        return (int)minVal;
    }
};

// Test the MinStack implementation
int main(){
    MinStack minStack;
    
    // Push: -2, 0, -3
    // Stack operations trace:
    // push(-2): Stack=[-2], min=-2
    // push(0):  Stack=[-2, 0], min=-2
    // push(-3): Stack=[-2, 2*(-3)-(-2)=-4], min=-3 (encoded -4 means -3 was pushed)
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    
    cout << minStack.getMin() << endl;  // Returns -3
    minStack.pop();                      // Remove encoded -3
    cout << minStack.top() << endl;      // Returns 0
    cout << minStack.getMin() << endl;   // Returns -2
    
    return 0;
}
