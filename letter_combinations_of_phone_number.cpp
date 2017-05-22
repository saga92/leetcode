#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        unordered_map<int,string> map={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
        letterCombinationsRecursive(res,map,"",digits);
        return res;
    }

    void letterCombinationsRecursive(vector<string>& res, unordered_map<int,string> map, string s, string digits){
        if(digits.size()==0){
            if(!s.empty())
                res.push_back(s);
            return;
        }
        int idx=digits.at(0)-'0';
        for(int i=0;i<map[idx].size();i++){
            s+=map[idx].at(i);
            if(digits.size()!=1){
                letterCombinationsRecursive(res,map,s,digits.substr(1,digits.size()-1));
            }else{
                letterCombinationsRecursive(res,map,s,"");
            }
            s=s.substr(0,s.size()-1);
        }
    }
};

int main(){
    Solution solution;
    vector<string> res=solution.letterCombinations("2");
    return 0;
}
