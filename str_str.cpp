#include<string>
using namespace std;
class Solution {
public:
    int* computeLPSArray(string s){
        int* lps=new int[s.length()];
        int i(0),j(1);
        lps[0]=0;
        while(j<s.length()){
            if(s[j]==s[i]){
                i++;
                lps[j]=i;
                j++;
            }else{
                if(i!=0){
                    i=lps[i-1];
                }else{
                    lps[j]=0;
                    j++;
                }
            }
        }
        return lps;
    }

    int strStr(string haystack, string needle) {
        if(!needle.length()) return 0;
        if(!haystack.length()) return -1;
        if(haystack.length()<needle.length()) return -1;

        int* lps=computeLPSArray(needle);
        int i(0),j(0);
        while(i<haystack.length()){
            if(haystack[i]==needle[j]){
                j++;i++;
            }
            if(j==needle.length()){
                return (i-needle.length());
            }else if(i<haystack.length()&&needle[j]!=haystack[i]){
                if(j!=0) j=lps[j-1];
                else i++;
            }
        }
        return -1;
    }
};


//class Solution {
//public:
//    int strStr(string haystack, string needle) {
//        if(!needle.length()) return 0;
//        if(!haystack.length()) return -1;
//        if(haystack.length()<needle.length()) return -1;
//        for(int i=0;i<(haystack.length()-needle.length()+1);i++){
//            int j=0;
//            for(j=0;j<needle.length();j++){
//                if(haystack[i+j]!=needle[j]) break;
//            }
//            if(j==needle.length()){
//                return i;
//            }
//        }
//        return -1;
//    }
//};

int main(){
    Solution solution;
    int res=solution.strStr("mississippi", "issi");
    return 0;
}
