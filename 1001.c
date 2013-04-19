#include <stdio.h>
#include <string.h>

int Alphacode ( char digits[] )
{
	int sum[10000];
	int temp;
	int length = strlen ( digits );
	int i = 0;	
	if ( length == 1 ) return 1;
	sum[i++] = 1;
	
	if ( (digits[i]-'0' + (digits[i-1]-'0')*10) < 26  && digits[i] != '0' )
		sum[i++] = 2;
	else
		sum[i++] = 1;

/* Initialize finished. */

	while ( i < length )
	{
		if (digits[i] == '0') 
			sum[i] = sum[i-2];
		else if ( digits[i-1] == '0' )
			sum[i] = sum[i-1];	
		else if ( (digits[i]-'0' + (digits[i-1]-'0')*10) <= 26 )
			sum[i] = sum[i-1] + sum[i-2];
		else
			sum[i] = sum[i-1];
		i++;
	}


	return sum[i-1];
}

int main()
{
	char digits[10000];
	digits[0] = 0;
	while ( 1 )
	{
		scanf ( "%s", digits );
		if ( digits[0] == '0' ) break;
		printf ( "%d\n", Alphacode(digits) );
	}	
	return 0;
}


