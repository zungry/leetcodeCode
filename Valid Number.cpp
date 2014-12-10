class Solution {
public:
    bool isNumber(const char *s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(s == NULL)return false;
        int len = strlen(s);
        int i = 0, j = len-1;
        while(i < len && s[i] == ' ')i++;//去掉首部空格
        if(i == len)return false;
        else if(s[i] == '-')i++;
        else if(s[i] == '+')i++;
        while(j >=0 && s[j] == ' ')j--;//去掉尾部空格
        len = j+1;
        int istart = i;
 
        while(i < len && s[i] >= '0' && s[i] <= '9')i++;
        if(i == len )
        {
            if(s[i-1] != '-' && s[i-1] != '+')return true;
            else return false;
        }
 
        if(s[i] == '.')
        {
            int doti = i;
            i++;
            while(i < len && s[i] >= '0' && s[i] <= '9')i++;
            if((doti == istart || s[doti-1] == '-' ||
                s[doti-1] == '+') && i == doti+1)return false;
            if(i == len)
                return true;
        }
 
        if(s[i] == 'e' || s[i] == 'E')
        {
            if(i == istart || s[i-1] == '-' || s[i-1] == '+')return false;
            if(s[++i] == '-' || s[i] == '+')i++;
            while(i < len && s[i] >= '0' && s[i] <= '9')i++;
            if(i == len)
            {
                if(s[i-1] < '0' || s[i-1] >'9')return false;
                return true;
            }
            else return false;
        }
        else return false;
    }
};