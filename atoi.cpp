#include<string>
#include <limits.h>

using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        if(!str.size()) return 0;
        long long res=0;
        int sign=1;
        bool isHead(true);
        int numAmount=0;
        for(int i=0;i<str.size();i++){
            if(numAmount>10)
                return (int)(sign*res>INT_MAX?INT_MAX:sign*res<INT_MIN?INT_MIN:sign*res);
            switch(str[i]){
                case'0':case'1':case'2':case'3':case'4':case'5':case'6':case'7':case'8':case'9':
                    res=res*10+(str[i]-'0');
                    isHead=false;
                    numAmount++;
                    break;
                case ' ':
                    if(!isHead) return (int)(sign*res>INT_MAX?INT_MAX:sign*res<INT_MIN?INT_MIN:sign*res);
                    break;
                case '+':
                    if(!isHead) return 0;
                    else sign=1;
                    isHead=false;
                    break;
                case '-':
                    if(!isHead) return 0;
                    else sign=-1;
                    isHead=false;
                    break;
                default:
                    return (int)(sign*res>INT_MAX?INT_MAX:sign*res<INT_MIN?INT_MIN:sign*res);
            }
        }
        return (int)(sign*res>INT_MAX?INT_MAX:sign*res<INT_MIN?INT_MIN:sign*res);
    }
};

int main(){
    /*
     * "+-2"
     * "   2"
     * "2a3"
     * "11111111111111111111111111"
     *
     * */
    Solution solution;
    int res=solution.myAtoi("-2147483649");
    return 0;
}

