// Forward declaration of isBadVersion API.
bool isBadVersion(int version){
    if(version>=1702766719)
        return true;
    return false;
}

class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(1))
            return 1;
        long long i=1, j=n, mid=0;
        while((j-i)!=1){
            mid=(i+j)/2;
            if(isBadVersion(mid)){
                j=mid;
            }else{
                i=mid;
            }
        }
        return j;
    }
};

int main(){
    Solution solution;
    int res=solution.firstBadVersion(2126753390);
    return 0;
}
