class Solution {
public:
    int singleNumber(int A[], int n) {
        int ret = 0;
        int bit[32] = {0};
        for (int i =0; i < 32; i++) {
            for (int j = 0; j < n; j++) {
                bit[i]+=(A[j]>>i) & 1;
            }
            
            ret |=(bit[i]%3) << i;
        }
        return ret;
    }
};