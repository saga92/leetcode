#include<string>
#include <vector>

using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        if(s.size()==1) return s;
        int min_start=0,max_len=1;
        int slen=s.size();
        vector<vector<int>> dp(slen, vector<int>(slen));
        //init
        for(int i=0;i<slen;i++){
            for(int j=0;j<slen;j++){
                if(i>=j){
                    dp[i][j]=1;
                }
            }
        }
        int i=0,j=0;
        for(int k=1;k<s.size();k++){
            for(i=0;(j=i+k)<s.size();i++){
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1];
                    if(dp[i][j]){
                        if(k+1>max_len){
                            min_start=i;
                            max_len=k+1;
                        }
                    }
                }else{
                    dp[i][j]=0;
                }
            }
        }
        return s.substr(min_start,max_len);
    }
};

int main(){
    Solution solution;
    string res=solution.longestPalindrome("bb");
    return 0;
}