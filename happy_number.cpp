#include<unordered_set>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(s.find(n)==s.end()){
            s.insert(n);
            int tn=n;
            n=0;
            while(tn){
                n+=(tn%10)*(tn%10);
                tn/=10;
            }
            if(n==1)
                return true;
        }
        return false;
    }
};
