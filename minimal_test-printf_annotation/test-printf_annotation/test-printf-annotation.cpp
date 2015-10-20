#include <cstdio>
#include <windows.h>

void boring_printf( _In_z_ const char* const ptr ) {
	printf( "%s\r\n", ptr );
	}

int main( ) {
	char three_char_str[ 3 ];
	three_char_str[ 0 ] = 'b';
	three_char_str[ 1 ] = 'a';
	three_char_str[ 2 ] = 0;

	boring_printf( three_char_str );

	three_char_str[ 2 ] = '`';

	boring_printf( three_char_str );
}
