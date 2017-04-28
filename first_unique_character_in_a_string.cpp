#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> m1;
        unordered_map<char,int>::iterator it;
        for(char ch:s){
            if((it=m1.find(ch))!=m1.end()){
                it->second++;
            }else{
                m1.insert({ch,1});
            }
        }
        for(int i=0;i<s.size();i++){
            it=m1.find(s[i]);
            if(it->second==1){
                return i;
            }
        }
        return -1;
    }
};
