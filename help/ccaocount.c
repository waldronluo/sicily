#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    char c;
    int arr[255] = {0};
    while ( ( c = getchar() ) != 10 ) {
        arr[c] ++;
    }
    for ( int i=0 ; i < 255 ; i++ ) {
        if ( ( i >= 'a' && i <= 'z' ) ||
                ( i >= 'A' && i <= 'Z' ) )
            cout << (char) i << ":" << arr[i] << "\t" ;
    }
    cout << endl;
    return 0;
}
