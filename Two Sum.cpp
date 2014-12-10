class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret;
        map<int,int> mapping;
        
        for(int i = 0;i < numbers.size();++i){
            if(mapping.count(target-numbers[i])){
                ret.push_back(mapping[target-numbers[i]]+1);
                ret.push_back(i+1);
                break;
            }else{
                mapping[numbers[i]] = i;
            }
        }
        return ret;
    }
};