class Solution{
   public:
        int trap(int A[],int n){ 
        if(n == 0)
            return 0;
        
        int *left = new int[n];
        int *right = new int[n];

        int ret = 0;
        

        left[0]=A[0];
        
        for(int i = 1;i < n-1;i++){
            if(A[i] > left[i - 1]) 
                left[i] = A[i];
             else
              left[i] = left[i - 1];
        }   
        left[0] = 0;

        right[n-1] = A[n-1];
        for(int i = n-2;i > 0;i--){
            if(A[i] > right[i+1])
              right[i] = A[i];
             else
                right[i] = right[i+1];
        }   
        right[n-1]=0;

        for(int i=1;i<n - 1;i++){
            int temp = min(left[i],right[i]) - A[i];
            if(temp > 0)
              ret += temp;
           
        }   
        delete left,right;
        return ret;                                                                                                                                                                                          
    }   
};
