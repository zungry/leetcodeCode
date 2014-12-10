class Solution {
public:
    int maxSubArray(int A[], int n) {
        int ret = INT_MIN;
        int temp = 0;
        for(int i = 0;i < n;++i){
            temp += A[i];
            ret = max(ret,temp);
            if(temp < 0)
                temp = 0;
        }
        return ret;
    }
};