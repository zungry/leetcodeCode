class Solution{
  public:
      char *strStr(char *haystack,char *needle){
          if(haystack == NULL || needle == NULL)
            return NULL;
       int hlen = strlen(haystack);
        int nlen = strlen(needle);
        if(hlen == 0 && nlen == 0){
            return "";
        }
  
          if(nlen > hlen)
            return NULL;
  
          for(int i = 0;i <=hlen - nlen;i++){
              char *p=&haystack[i];
              int j = 0;
              for(;j < nlen;j++){
                  if(*p!=needle[j])
                    break;
                  p++;
              }   
              if(j == nlen)
                return &haystack[i];
          }   
          return NULL;
      }   
};
