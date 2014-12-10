class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        int nLength = num.size();
        if(nLength == 0)
            return vector<vector<int> >();
        
        permute(num,0,nLength);
        return ret;
    }
    
    void permute(vector<int> &num,int index,int &nLength){
        if(index == nLength - 1)
            ret.push_back(num);
        else{
            for(int i = index;i < nLength;i++){
                int temp = num[i];
                num[i] = num[index];
                num[index] = temp;
                
                permute(num,index+1,nLength);
                
                temp = num[i];
                num[i] = num[index];
                num[index] = temp;
            }
        }
    };
private:
    vector<vector<int> > ret;
};