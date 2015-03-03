#include <stdio.h>

#define MAKE_ENUM( ... ) enum{ __VA_ARGS__ }

int main( int argc, char *argv[] )
{
        MAKE_ENUM( a, b, c );
        printf( "a = %d, b = %d, c = %d\n", a, b, c );
        return 0;
}
