#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area=0, l=0, r=height.size()-1;
        while(l<r){
            max_area=max(max_area, (r-l)*min(height[l],height[r]));
            if(height[r]>height[l]){
                l++;
            }else{
                r--;
            }
        }
        return max_area;
    }
};
/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area=0, area=0;
        for(int i=0;i<height.size()-1;i++){
            for(int j=i+1;j<height.size();j++){
                area=(j-i)*min(height[i], height[j]);
                max_area=max(max_area, area);
            }
        }
        return max_area;
    }
};
 */
