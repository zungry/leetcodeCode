class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> ret;
        if(tokens.size() == 0)
            return 0;
        int result = 0;    
        
            
        for(int i = 0;i < tokens.size();++i){
            if(tokens[i] == "+"){
                int num1 = ret.top();
                ret.pop();
                int num2 = ret.top();
                ret.pop();
                result = num1 + num2;
                ret.push(result);
            }else if(tokens[i] == "-"){
                int num1 = ret.top();
                ret.pop();
                int num2 = ret.top();
                ret.pop();
                result = num2 - num1;
                ret.push(result);
            }else if(tokens[i] == "*"){
                int num1 = ret.top();
                ret.pop();
                int num2 = ret.top();
                ret.pop();
                result = num2 * num1;
                ret.push(result);
            }else if(tokens[i] == "/"){
                int num1 = ret.top();
                ret.pop();
                int num2 = ret.top();
                ret.pop();
                if(num1 != 0)
                    result = num2 / num1;
                ret.push(result);
            }else{
                ret.push(atoi(tokens[i].c_str()));
            }
        }
        return ret.top();
    }
};