#include <bits/stdc++.h> 
// Stack class.
class Stack {
    int *arr;
    int topIndex;
    int size;

public:
    
    Stack(int capacity) {
        // Write your code here.
        arr = new int[capacity];
        size = capacity;
        topIndex = -1;
    }

    void push(int num) {
        // Write your code here.
        if(isFull()) return;

        topIndex++;
        arr[topIndex] = num;
    }

    int pop() {
        // Write your code here.

        if(isEmpty()) return -1;
        int ans = arr[topIndex];
        topIndex--;
        return ans;

    }
    
    int top() {
        // Write your code here.
        if(isEmpty()) return -1;

        return arr[topIndex];

    }
    
    int isEmpty() {
        // Write your code here.
        return topIndex==-1;
    }
    
    int isFull() {
        // Write your code here.

        return (topIndex-1) == size;
    }
    
};
