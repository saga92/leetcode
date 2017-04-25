#include<stack>
using namespace std;
class MyQueue {
private:
    stack<int> input;
    stack<int> output;
public:

    /** Push element x to the back of queue. */
    void push(int x) {
        input.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x=peek();
        output.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        if(output.empty()){
            while(!input.empty()){
                int x=input.top();
                output.push(x);
                input.pop();
            }
        }
        return output.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return input.empty()&&output.empty();
    }
};
