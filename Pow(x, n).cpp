class Solution {
public:
    double pow(double x, int n) {
        bool g_InvalidInput = false;
        if(equal(n,0.0) && n < 0){
            g_InvalidInput = true;
            return 0.0;
        }
        
        unsigned int absExponent = (unsigned int) (n);
        if(n < 0)
        absExponent =(unsigned int)(-n);
        
        
        double ret = PowerWithUnsignedExponent(x,absExponent);
        if(n < 0)
        ret = 1.0/ret;
        return ret;
    }
    
bool equal(double num1,double num2){
    if((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
        return true;
    else
        return false;
}
    
double PowerWithUnsignedExponent(double base,unsigned int exponent){
    if(exponent == 0)
        return 1;
    if(exponent == 1)
        return base;
        
    double result = PowerWithUnsignedExponent(base,exponent >> 1);
    result *= result;
    if(exponent & 0x1 == 1)
        result *= base;//如果幂是奇数的话得多乘一个底数
        
    return result;
}
};