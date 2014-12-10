class Solution {
public:
    int findMin(vector<int> &num) {
        int left = 0;
        int right = num.size()-1;
        int mid = left;
        
        
        while(num[left] >= num[right]){
            if(right - left == 1){
                mid = right;
                break;
            }
            
            mid = (left + right) / 2;
            
            if(num[left] == num[right] && num[left] == num[mid]){
                return Min(num,left,right);
            }
            
            if(num[mid] >= num[left])
                left = mid;
            else if(num[mid] <= num[right])
                right = mid;
        }
        return num[mid];
    }
    
    int Min(vector<int>&num,int left,int right){
        int minum = num[left];
        for(int i = left + 1;i <= right;++i){
            minum = min(num[i],minum);
        }
        return minum;
    }
};