#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mr;
        unordered_map<char,int>::iterator it;
        for(char ch:ransomNote){
            if((it=mr.find(ch))!=mr.end()){
                it->second++;
            }else{
                mr.insert({ch,1});
            }
        }
        for(char ch:magazine){
            if((it=mr.find(ch))!=mr.end()){
                it->second--;
                if(!it->second){
                    mr.erase(ch);
                }
            }
        }
        if(mr.empty())
            return true;
        return false;
    }
};

int main(){
    Solution solution;
    bool res=solution.canConstruct("aa", "aab");
    return 0;
}
