class Solution {
public:
    string countAndSay(int n) {
        string pre;
        if(n < 1)
            return pre;
        
        pre.push_back('1');
        int i = 1;
        for( i = 2;i <= n;i++){
            char prechar = pre[0];
            int numofchar = 1;
            string temp;
            pre.push_back('#');
            for(int j = 1;j < pre.size();j++){
                char curchar = pre[j];
                if(curchar == prechar){
                    numofchar++;
                }else{
                    
                    temp +=to_string(numofchar);
                   // temp.push_back(a);
                    temp.push_back(prechar);
                    prechar = curchar;
                    numofchar = 1;
                }
            }
            pre = temp;
        }
        return pre;
    }
};
