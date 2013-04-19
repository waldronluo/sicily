#include <stdio.h>
#include <memory.h>

int max ( int i , int j )
{
	return (i>j)? i:j;
}

int main()
{
	int N,m;
	int v,p;
	int values[30000];
	int i,j;
	int result = 0 ;
	while ( 1 )
	{
		if ( scanf ( "%d %d", &N, &m ) == EOF ) break;		
		memset ( values, 0 , sizeof(values) );
		for ( i=0 ; i<m ; i++ )
		{
			scanf ("%d %d",&v, &p );
			for ( j=N; j>=v; j-- )
				if ( values[j-v] + v*p > values[j] )
					values[j] = values[j-v] + v*p; 
		}	
		printf("%d\n", values[N] );
	}
}
