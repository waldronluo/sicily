#include <stdio.h>
#include <string.h>

int main()
{
    char c;
    int arr[255] = {0};
    while ( 10 != (c = getchar()) ){
        arr[c]++;
    };
    {
        int i = 0;
        for ( ; i < 255 ; i ++ )
            if ( ('a' <= i && i <= 'z') || ('A' <= i && i <= 'Z' ) )
                printf("%c:%d\t", i, arr[i]);
        printf("\n");
    }
    return 0;
}
