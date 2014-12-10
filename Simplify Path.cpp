class Solution {
public:
   string simplifyPath(string path) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        assert(path[0]=='/');  
        vector<string> vec;  
        int i = 0;  
        while(i < path.size())  
        {  
            int end = i+1;  
            while(end < path.size() && path[end] != '/')  
                end++;  
            string sub = path.substr(i+1,end-i-1);  
            if(sub.length()>0){  
                if(sub == ".."){  
                    if(!vec.empty()) vec.pop_back();  
                }  
                else if(sub != ".")  
                    vec.push_back(sub);  
            }  
            i=end;  
        }  
        if(vec.empty())return "/";  
        string res;  
        for(int i = 0; i< vec.size(); i++)  
            res += "/" + vec[i];  
        return res;  
    }  
};