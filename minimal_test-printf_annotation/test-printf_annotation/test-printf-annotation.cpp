#include <cstdio>
#include <windows.h>

void boring_printf_4( _In_z_ const char* const ptr ) {
	printf( "%s\r\n", ptr );
	}

int main( ) {
	char three_char_str_format[ 3 ];
	three_char_str_format[ 0 ] = '%';
	three_char_str_format[ 1 ] = 's';
	three_char_str_format[ 2 ] = 0;

	boring_printf_4( three_char_str_format );

	three_char_str_format[ 2 ] = '`';

	boring_printf_4( three_char_str_format );
}
