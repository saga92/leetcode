#include<queue>
using namespace std;
class MyStack {
private:
    queue<int> que;
public:

    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
        for(int i=0;i<que.size()-1;i++){
            int y=que.front();
            que.push(y);
            que.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int y=que.front();
        que.pop();
        return y;
    }

    /** Get the top element. */
    int top() {
        return que.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
};
