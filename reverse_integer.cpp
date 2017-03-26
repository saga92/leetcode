#include <stack>
#include <cmath>
class Solution {
public:
    int reverse(int x) {
        std::stack<int>  numstack;
        for(int i=x; i!=0; i=i/10){
            numstack.push(i%10);
        }
        int i=0;
        long long result=0;
        long long ten=1;
        while(!numstack.empty()){
            long n=numstack.top();
            numstack.pop();
            ten = mypow(10,i);
            result += (n*ten);
            i++;
        }
        if(2147483647<result || result <-2147483647){
            return 0;
        }
        return (int)result;
    }

    long long mypow(int r, int x){
        long long result=1;
        for(int i=0; i<x; ++i){
            result *=r;
        }
        return result;
    }
};

int main(){
    Solution solution;
    int result = solution.reverse(1534236469);
    return 0;
}
