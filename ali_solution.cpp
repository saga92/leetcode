#include<iostream>
#include <vector>
using namespace std;
int mypow(int x, int n){
    int res=1;
    for(int i=0;i<n;i++){
        res*=x;
    }
    return res;
}
int main(){
    string s;
    vector<int> arr;
    int res=0;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i])) {
            res = res * 10 + s[i] - '0';
        }else if(s[i]=='^'){
            res=-1;
        }else{
            arr.insert(arr.end(), res);
            res=0;
        }
    }
    arr.insert(arr.end(), res);
    //cal
    int n=arr.size();
    int x1=0,x2=0;
    int m=0;
    int p=0;
    for(int i=0;(p=(m+mypow(2,i)))<=n;i++){
        if(i&1){
            //x2
            for(int j=m;j<p;j++){
                x2+=(arr[j]==-1?0:arr[j]);
            }
        }else{
            //x1
            for(int j=m;j<p;j++){
                x1+=(arr[j]==-1?0:arr[j]);
            }
        }
        m+=mypow(2,i);
    }
    cout<<std::max(x1,x2);
    return 0;
}

