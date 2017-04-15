#include <cstring>
#include <cstdio>

void computeLPSArray(char *pat, int* lps){
    int M=strlen(pat);
    int len=0;
    lps[0]=0;
    int i=1;
    while(i<M){
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        }else{ //(pat[i] != pat[len])
            if(len!=0){
                len=lps[len-1];
            }else{
                lps[i]=0;
                i++;
            }
        }
    }
}
void kmp(char *text, char *pat){
    int N=strlen(text);
    int M=strlen(pat);
    int* lps=new int[M];
    computeLPSArray(pat, lps);

    int i(0),j(0);
    while(i<N){
        if(pat[j]==text[i]){
            j++;i++;
        }
        if(j==M){
            printf("pattern found at %d !", i-M);
            j=lps[j-1];
        }else if(i<N&&pat[j]!=text[i]){
            if(j!=0) j=lps[j-1];
            else i++;
        }
    }
}

int main()
{
    char *txt = "ABABDABACDABABCABAB";
    char *pat = "ABABCABAB";
    kmp(txt, pat);
    return 0;
}