class Solution {
public:
    int maxProduct(int A[], int n) {
        if(n < 1) return 0;
        
        int minSum = A[0];
        int maxSum = A[0];

        int ret = A[0];

        for(int i = 1;i < n;i++){
            int a = maxSum * A[i];
            int b = minSum * A[i];
            int c = A[i];
            maxSum = max(max(a,b),c);
            minSum = min(min(a,b),c);

            ret = maxSum > ret ? maxSum : ret;
            }
      return ret;  
    }
};