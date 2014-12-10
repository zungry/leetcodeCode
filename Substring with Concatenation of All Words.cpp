class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        ret.clear();

        int numbers = L.size();
        if(numbers <= 0)
            return ret;
        int wordsize = L[0].size();
        map<string,int> word_count;
        map<string,int> current;

        for(int i =0;i < L.size();i++){
            ++word_count[L[i]];
        }

        int i,j;
        for(i = 0;i <= int(S.size())-numbers * wordsize ; ++i){
            current.clear();
            for(j =0;j < L.size();j++){
                string word = S.substr(i + j * wordsize,wordsize);
                if(word_count.find(word) != word_count.end()){
                    ++current[word];
                    if(current[word] > word_count[word])
                        break;
                }else{
                    break;
                }
            }

            if(j == numbers)
                ret.push_back(i);
        }
        return ret;
    }
};

