class Solution{
public:
    int maxArea(vector<int> &height){
        int len = height.size();
        if(len <= 0)
          return 0;

        int i = 0;
        int j = height.size() - 1;

        int ret = 0;
        while(i < j){ 
            ret =max(ret, min(height[j],height[i]) * (j - i));
            if(height[i] < height[j]) i++;
            else j--;
        }   
        return ret;
    }   
};