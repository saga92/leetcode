#include<string>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        int *arr=new int[256]{0};
        for(char ct:t){
            arr[ct-'a']++;
        }
        for(char cs:s){
            arr[cs-'a']--;
        }
        int i=0;
        for(i=0;i<256;i++){
            if(arr[i]>0)
                break;
        }
        return (char)(i+'a');
    }
};

int main(){
    Solution solution;
    char res=solution.findTheDifference("abcd","abcde");
    return 0;
}