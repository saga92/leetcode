#include<string>
#include <sstream>

using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        else if(n==2) return "11";
        string s("11");
        int count=0;
        char pre_char='\0';
        if(n<1) return "";
        string ret;
        for(int i=2;i<n;i++){
            count=1;
            pre_char=s[0];
            for(int j=1;j<=s.length();j++){
                if(j==s.length()){
                    stringstream ss;
                    ss<<count;
                    ret += ss.str()+pre_char;
                    continue;
                }
                if(pre_char!=s.at(j)){
                    stringstream ss;
                    ss<<count;
                    if(j!=0)
                        ret += ss.str()+pre_char;
                    count=1;
                    pre_char=s.at(j);
                }else count++;
            }
            s=ret;
            ret="";
        }
        return s;
    }
};

int main(){
    Solution solution;
    string ret=solution.countAndSay(3);
    return 0;
}