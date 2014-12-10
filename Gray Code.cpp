class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        int numsize = 1 << n;
        
        for(int i = 0;i < numsize;i++){
            ret.push_back((i>>1)^i);
        }
        return ret;
    }
};