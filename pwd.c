#include <REG51.h>
#include "FinalCase.h"
#include "stdio.h"
#include "stdlib.h"
//#include "time.h"

void Ultimate(int p)
{
	int m=0,n=100,b=0;
	while(p!=b)
	{
		scanf("%d",&b);

		if(b>p)
		{
			if(b<=n)
			n=b;
			if(m==(p-1) && n==(p+1)) //成功條件 
			{
                aa = 0;
                bb = 200;
			}
            aa = m;
            bb = n;
		}
		else if(b<p)
		{
			if(b>=m)
			m=b;
			if(m==p-1 && n==p+1) //成功條件 
			{
                aa = 0;
                bb = 200;
			}
            aa = m;
            bb = n;
		
		}
	}
    aa = 0;
    bb = 404;	
}




void pwd_start(void)
{
	int a;
// 	srand(time(NULL));
 	a=(rand()%100)+1;
//	printf("%d",a);
//	Ultimate(a);
//	return 0;
}

