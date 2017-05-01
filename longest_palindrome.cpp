#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        unordered_map<char,int>::iterator it;
        for(char cs:s){
            if((it=m.find(cs))!=m.end()){
                it->second++;
            }else{
                m.insert({cs,1});
            }
        }
        int len=0,n=0, mid=0;
        for(it=m.begin();it!=m.end();it++){
            n+=it->second/2;
            it->second%=2;
            if(it->second)
                mid=1;
        }
        len=2*n+mid;
        return len;
    }
};
