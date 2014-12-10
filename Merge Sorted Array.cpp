class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if(n == 0)
            return;
        
        int len = m + n - 1;
        while(m != 0 && n != 0){
            if(A[m - 1] > B[n - 1]){
                A[len] = A[m - 1];
                --m;
            }
            else{
                A[len] = B[n - 1];
                --n;
            }
            len--;
        }
        
        while(n != 0){
            A[len--] = B[n - 1];
            n--;
        }
    }
};