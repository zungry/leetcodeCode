class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for(int i = 0;i < n;i++){
            if(A[i] > 0 && A[i] < n){
                if(A[A[i] - 1] != A[i]){
                    int tmp =   A[A[i]-1];
                    
                    A[A[i]-1] = A[i];
                    A[i] = tmp;
                    i--;
                }
            }
            
        }
        
        for (int j=0; j<n; ++j)  
            if (A[j]-1 != j)  
                return j+1;  
        
        return n+1;
    }
};