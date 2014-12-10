class Solution {
public:
    bool isValid(string s) {
        stack<int> Parenthese;
        int count = 0;
        int len = s.size();

        if(len < 0 || len % 2 == 1)
            return false;

        for(int i = 0 ; i < len ; i++){
            if(s[0] == ')' || s[0] == ']' || s[0] == '}')
                return false;
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                Parenthese.push(s[i]);
                count++;
            }
            else if(s[i] == ')'){
                if(Parenthese.top() != '(')
                    return false;
                count--;
                Parenthese.pop();
            }
            else if(s[i] == ']'){
                if(Parenthese.top() != '[')
                    return false;
                count--;
                Parenthese.pop();
            }
            else if(s[i] == '}'){
                if(Parenthese.top() != '{')
                    return false;
                count--;
                Parenthese.pop();
            }
        }
 //       if(count == 0)
   //         return true;
     //   else 
       //     return false;

        if(Parenthese.empty())
            return true;
        else 
            return false;
    }
};