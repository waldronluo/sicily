#include <string.h>
#define MAX_BUF 256
typedef unsigned long size_t;
/* how to make size_t unsigned long int?*/


void qsort_kernel ( void* base, size_t n, size_t size, int (*cmp)(const void*, const void*), void (*print)(const void*) )
{
	while (n > 1)
	{
		size_t i = 0;
		size_t j = n-1;
		char* qi = (char *)base;
		char* qj = (char *)base + size * j;
		char* qp = qj;
		while ( i<j )
		{
			printf ("\n----BEGIN-----Array qsorting---------\n");
			printf("i:%d j:%d n:%d\n", i , j, n );
///////////////////////////////////////////////////////////////////////////////////////
			char* result1 = base;
			{
				int k;
				for ( k=0 ; k<n; k++ )
				{
					print( &(result1[k*size]) );
				}
				printf("\n");
			}
			/* Find the sub-array that worth sorting */
			while ( i<j && (*cmp)( qi, qp ) <=0 )
				++i, qi += size;
			while ( i<j && (*cmp)( qp, qj ) <=0 )
				--j, qj -= size;
			printf("i:%d j:%d n:%d\n", i , j, n );
//			printf("i:%d\tj:%d\n",i,j);
			if ( i<j )
			{
				printf("in\n");
				char buf[MAX_BUF];
				char *q1;
				char *q2;
				size_t m , ms;
				
				q1 = qi;
				q2 = qj;
				for ( ms = size; 0<ms ; ms -= m, q1 += m , q2 -= m )
				{
					m = ms < sizeof (buf)? ms : sizeof(buf);
					memcpy ( buf, q1, m );
					memcpy ( q1, q2, m );
					memcpy ( q2, buf, m );
				}
				++i, qi += size;
//				printf("%d\n", i );
			}
		}
		if ( qi != qp )
		{
			char buf[MAX_BUF];
			char *q1; 
			char *q2; 
			size_t m, ms;
			q1 = qi;
			q2 = qj;
			for ( ms=size ; 0 < ms ; ms -=m , q1 += m , q2 -= m )
			{
					m = ms < sizeof (buf)? ms : sizeof(buf);
					memcpy ( buf, q1, m );
					memcpy ( q1, q2, m );
					memcpy ( q2, buf, m );
			}
		}
		j = n - i - 1, qi += size;
		printf("i:%d j:%d n:%d\n", i , j, n );
///////////////////////////////////////////////////////////////////////////////////////
	char* result = base;
	{
		int k;
		for ( k=0 ; k<n; k++ )
		{
			print( &(result[k*size]) );
		}
		printf("\n");
	}
		printf ("----END-----Array qsorting---------\n\n");
///////////////////////////////////////////////////////////////////////////////////////
		if ( j<i ){
			if ( 1<j )
				qsort_kernel ( qi, j , size, cmp, print );	
			n = i;
		}
		else{
			if ( 1<i )
				qsort_kernel ( base, i , size , cmp, print );
			base = qi;
			n = j;
		}
	}
}

void sort ( void* base, size_t n, size_t size, int (*cmp)(const void*, const void*), void (*print)(const void*) )
{
	char* result = base;
	{/* Output the original array */
		int i;
		printf ("Array before qsort\n");
		for ( i=0 ; i<n; i++ )
		{
			print( &(result[i*size]) );
		}
		printf("\n");
	}/* Output the original array */
	
	qsort_kernel ( base, n, size, cmp, print );

	{/* Output the sorted array */
		int i;
		printf ("Array After qsort\n");
		for ( i=0 ; i<n; i++ )
		{
			print( &(result[i*size]) );
		}
		printf("\n");
	}/* Output the sorted array */
	
}

void print ( const void* i )
{
	printf ( "%d,",*(int*) i );
}

int cmp ( const void *a, const void* b )
{
//	printf ( "%d,%d\n",*(int*)a, *(int*)b );
	return ( *(int*)a - *(int*)b );
}

int main()
{
	int a[] = {1,2,3,4,9,8,7,6,5,5};
//	printf("%d %d %d\n", sizeof(long int),sizeof(int), sizeof(char) );
	sort ( a, 10, sizeof(int), cmp, print );
	
	return 0;
}


