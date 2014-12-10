class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> strHash;
        for(auto strVal : strs){
            string key = strVal;
            sort(key.begin(), key.end());
            strHash[key].push_back(strVal);
        }
        
        vector<string> ret;
        for(auto resVal : strHash){
            if (resVal.second.size() > 1) {
                for(auto strVal : resVal.second)
                    ret.push_back(strVal);
            }
        }
        return ret;
    }
};