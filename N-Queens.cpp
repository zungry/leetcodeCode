class Solution {
public:
    vector<vector<string> > re;

    //测试在第row行，第row列放置皇后是否有效 
    int isValid(int *a, int n, int row, int col)
    {
    	int tmpcol=0;
    	for(int tmprow=0;tmprow<row;tmprow++)
    	{
    		tmpcol = a[tmprow];
    		if(tmpcol == col)// 同列
    			return 0;
    		if((tmpcol-col) == (tmprow - row))// 在同一右斜线
    			return 0;
    		if((tmpcol-col) == (row - tmprow))// 在同一左斜线
    			return 0;
    	}
    	return 1;	
    }
    
    void PrintN(int *a, int n)
    {
    	vector<string> tmps;
    	for(int i=0;i<n;i++)
    	{
    		string s(n,'.');
    		s[a[i]]='Q';
    		tmps.push_back(s);		
    	}
    	re.push_back(tmps);
    }
    void n_queens(int *a,int n, int index)
    {
    	for(int i=0;i<n;i++)
    	{
    		if(isValid(a,n,index,i))
    		{
    			a[index]=i;
    			if(index == n-1)
    			{
    				PrintN(a,n);
    				a[index]=0;
    				return;
    			}
    			n_queens(a,n,index+1);
    			a[index]=0;
    		}
    	}
    }
    
    vector<vector<string> > solveNQueens(int n) {
    	
        int *a = new int[n];
        memset(a,0,sizeof(int)*n);
        n_queens(a,n,0);
        return re;
    }
};