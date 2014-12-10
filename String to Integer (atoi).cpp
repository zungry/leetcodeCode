class Solution {
public:
    int atoi(const char *str) {
        long long ret = 0;
        if(str == NULL)
            return 0;

        bool neg = false;
        //bool zheng = false;
        int i = 0; 
        while(str[i] !='\0' && str[i] == ' ') i++;
     
        if(str[i] == '-'){
            neg = true;
            i++;
        }else if(str[i] == '+'){
            neg = false;
            i++;
        }   
        for(; str[i] != '\0';i++){
            if(str[i] >= '0' && str[i] <= '9'){
                int tmp = str[i] - '0';
                ret = ret * 10 + tmp;
            }
            else break;
        }

        if(neg)
            ret = -ret;

        if(ret > INT_MAX) ret = INT_MAX;
        else if(ret < INT_MIN) ret = INT_MIN;
        ret = int(ret);
        return ret;
    }
};