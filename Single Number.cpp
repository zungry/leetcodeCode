class Solution {
public:
    int singleNumber(int A[], int n) {
        if (A == NULL && n == 0) {
            return 0;
        }
        
        int ret = A[0];
        for (int i = 1; i < n; i++) {
            ret = ret ^ A[i];
        }
        
        return ret;
    }
};