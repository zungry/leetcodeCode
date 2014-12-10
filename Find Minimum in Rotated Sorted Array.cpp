class Solution {
public:
    int findMin(vector<int> &num) {
        int left = 0;
        int right = num.size()-1;
        
        
        
        while(left < right){
            int mid = (left + right)/2;
            if(num[left] > num[right]){
            if(num[mid]>num[left]){
                left = mid;
            }else if(num[mid] < num[left]){
                right = mid;
            }else{
                break;
            }}else{
                break;
            }
        }
        return min(num[left],num[right]);
    }
};