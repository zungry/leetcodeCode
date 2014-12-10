class Solution{
public:
    int jump(int A[],int n){
        int cur = n-1;
        int pre = 0;
        int count = 0;
        
        while (true) {
            
            if (pre == cur) {
                return 0;
            }
            
            count++;
            pre = cur;
            
            
            for (int i = n-2; i>=0; i--) {
                if (A[i]+i >=pre) {
                    if (cur > i) {
                        cur = i;
                    }
                }
            }
            
            if (cur == 0) {
                return count;
            }
            
        }
    }
};