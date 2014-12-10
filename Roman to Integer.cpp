class Solution{
public:
    int romanToInt(string s){
       int len = s.length();
       if(len <= 0)
         return 0;

       int ret = 0;
       char start = s[0];
       int startInt = getValueOfRoman(start);
       int temp = startInt;

       for(int i = 1; i < len ;i++){
        char current = s[i];
        int currentInt = getValueOfRoman(current);
        if(currentInt == startInt)
            temp += currentInt;
        else if(currentInt < startInt){
            ret += temp;
            temp = currentInt;
            
        }
        else
            temp = currentInt - temp;
        startInt = currentInt;
       }
       ret += temp;
       return ret;
    }

    int getValueOfRoman(char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default : return 0;
        }
    }
};         