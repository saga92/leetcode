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
    int x=0;
    int m=0;
    int p=0;
    vector<int> ca;
    for(int i=0;(p=(m+mypow(2,i)))<=n;i++){
        for (int j = m; j < p; j++) {
            x += (arr[j] == -1 ? 0 : arr[j]);
        }
        ca.insert(ca.end(),x);
        x=0;
        m+=mypow(2,i);
    }
    int* resArr=new int[ca.size()];
    int max=0;
    resArr[0]=ca[0];
    if(ca.size()==1){
        cout<<resArr[0];
    }
    if(ca.size()==2){
        resArr[1]=std::max(ca[0], ca[1]);
        cout<<resArr[1];
    }
    for(int i=2;i<ca.size();i++){
        resArr[i]=std::max(resArr[i-1], resArr[i-2]+ca[i]);
    }
    for(int i=0;i<ca.size();i++){
        max=std::max(resArr[i],max);
    }
    cout<<max;
    return 0;
}

