#include<string>
using namespace std;
class Solution {
public:
    int countSegments(string s) {
        int res=0;
        s+=" ";
        for(int i=1;i<s.size();i++){
            if(s[i]==' '&&s[i-1]!=' ')
                res++;
        }
        return res;
    }
};
