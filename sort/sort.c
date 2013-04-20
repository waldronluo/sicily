#include <stdlib.h>
#include <string.h>
#define MAX_BUF 256
typedef unsigned long size_t;
/* how to make size_t unsigned long int?*/


void qsort_kernel ( void* base, size_t n, size_t size, int (*cmp)(const void*, const void*) )
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
			/* Find the sub-array that worth sorting */
			while ( i<j && (*cmp)( qi, qp ) <=0 )
				++i, qi += size;
			while ( i<j && (*cmp)( qp, qj ) <=0 )
				--j, qj -= size;
			if ( i<j )
			{
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
			}
		}
		if ( qi != qp )
		{
			char buf[MAX_BUF];
			char *q1; 
			char *q2; 
			size_t m, ms;
			q1 = qi;
			q2 = qp;
			for ( ms=size ; 0 < ms ; ms -=m , q1 += m , q2 -= m )
			{
					m = ms < sizeof (buf)? ms : sizeof(buf);
					memcpy ( buf, q1, m );
					memcpy ( q1, q2, m );
					memcpy ( q2, buf, m );
			}
		}
		j = n - i - 1, qi += size;
		if ( j<i ){
			if ( 1<j )
				qsort_kernel ( qi, j , size, cmp );	
			n = i;
		}
		else{
			if ( 1<i )
				qsort_kernel ( base, i , size , cmp );
			base = qi;
			n = j;
		}
	}
}

void stack_sort ( void* base, size_t n, size_t size, int (*cmp)(const void*, const void*) )
{
	/*Initial the stack*/
	{
		int i;
		for ( i = n/2 ; i>=0 ; i-- )
		{	
			int j;
			j = i;
			while ( 1 )
			{
				int k;
				char *left, *right, *middle, *larger;
				k = j;
				left = ( 2*k+1 >= n ) ? NULL : (char*) base + size * (2*k+1) ;
				right =( 2*k+2 >= n ) ? NULL : (char*) base + size * (2*k+2) ;
				middle = (char*) base + size * k;
				larger = left;
				if ( right != NULL )
				{
					if ( (*cmp) ( right , left ) > 0 )
					{
						larger = right ;
						k = 2 * j + 2;
					}			 
					else
						k = 2 * j + 1;
				}
				if ( left != NULL )
				{
					if ( (*cmp)  (middle, larger) < 0 )
					{
						char buf[MAX_BUF];
						char *q1 = larger;
						char *q2 = middle;
						size_t m, ms;
						for ( ms = size; 0<ms ; ms -= m, q1 += m, q2 -= m )
						{
							m = ms < sizeof (buf) ? ms : sizeof (buf);
							memcpy ( buf, q1, m);
							memcpy ( q1, q2, m );
							memcpy ( q2, buf, m);
						}
						j = k;
					}
					else
						break;	
				}
				if ( right == NULL && left == NULL )
					break;
			}
		}
	}
	/*Begin to sort*/
	{
		int i = n;
		while ( i ) 
		{
		/* swap the head and the rear  */
			int j;
			char buf[MAX_BUF];
			char *q1;
			char *q2;
			size_t m , ms;
			q1 = base;
			q2 = (char*) base + (i-1) * size;
			for ( ms = size; 0<ms ; ms -=m , q1 += m , q2 -= m )
			{
				m = ms < sizeof (buf) ? ms : sizeof (buf);
				memcpy ( buf , q1 , m );
				memcpy ( q1 , q2 , m );
				memcpy ( q2 , buf , m );
			}
			i--;
			j = 0;
		/* recursively sort the heap */
			while ( 1 )
			{
				int k;
				char *left, *right, *middle, *larger;
				k = j;
				left = ( 2*k+1 >= i ) ? NULL : (char*) base + size * (2*k+1) ;
				right =( 2*k+2 >= i ) ? NULL : (char*) base + size * (2*k+2) ;
				middle = (char*) base + size * k;
				larger = left;
				if ( right != NULL )
				{
					if ( (*cmp) ( right , left ) > 0 )
					{
						larger = right ;
						k = 2 * j + 2;
					}			 
					else
						k = 2 * j + 1;
				}
				if ( left != NULL )
				{
					if ( (*cmp)  (middle, larger) < 0 )
					{
						char buf[MAX_BUF];
						char *q1 = larger;
						char *q2 = middle;
						size_t m, ms;
						for ( ms = size; 0<ms ; ms -= m, q1 += m, q2 -= m )
						{
							m = ms < sizeof (buf) ? ms : sizeof (buf);
							memcpy ( buf, q1, m);
							memcpy ( q1, q2, m );
							memcpy ( q2, buf, m);
						}
						j = k;
					}
					else
						break;	
				}
				if ( right == NULL && left == NULL )
					break;
			}
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
	
//	qsort_kernel ( base, n, size, cmp );
	stack_sort ( base, n , size, cmp );
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
	return ( *(int*)a - *(int*)b );
}

int main()
{
	int a[1000];
	srand(0);
	{
		int i=0;
		for ( i=0 ; i<1000 ; i++ )
			a[i] = rand()%1000;
	}	
	sort ( a, 1000 , sizeof(int), cmp, print );
	
	return 0;
}


