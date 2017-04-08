#include<vector>
#include <string>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        int minlen=-1;
        for(string s:strs) {
            if (minlen == -1)
                minlen = s.length();
            else
                minlen = minlen <= s.length() ? minlen : s.length();
        }
        int i=0;
        for(i=0;i<minlen;++i){
            char ch='\0';
            for(string s:strs){
                if(ch=='\0')
                    ch=s[i];
                else if(ch!=s[i]){
                    return s.substr(0, i);
                }
            }
        }
        return strs[0].substr(0, i);
    }
};

int main(){
    Solution solution;
    vector<string> strs;
    strs.push_back("aa");
    strs.push_back("a");
    solution.longestCommonPrefix(strs);
}