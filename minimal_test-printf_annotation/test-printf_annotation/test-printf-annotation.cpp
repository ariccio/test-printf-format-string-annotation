#include <cstdio>
#include <windows.h>

void boring_printf_1( const char* const ptr ) {
	printf( ptr, "" );
	}


void boring_printf_2( _Printf_format_string_ const char* const ptr ) {
	printf( ptr, "" );
	}

void boring_printf_3( _In_z_ _Printf_format_string_ const char* const ptr ) {
	printf( ptr, "" );
	}

void boring_printf_4( _In_z_ const char* const ptr ) {
	printf( "%s", ptr );
	}

void boring_vdebugf( _In_z_ _Printf_format_string_ const char* const ptr, va_list args ) {
	const rsize_t buffer_size = 512u;
	char buffer[ buffer_size ] = { };
	_vsnprintf_s( buffer, buffer_size, _TRUNCATE, ptr, args );
	OutputDebugStringA( buffer );
	}

void boring_debugf( _In_z_ _Printf_format_string_ const char* const ptr, ... ) {
	va_list args;
	va_start( args, ptr );
	boring_vdebugf( ptr, args );
	va_end( args );
	}

int main( ) {
	char three_char_str_format[ 30 ];
	three_char_str_format[ 0 ] = '%';
	three_char_str_format[ 1 ] = 's';
	three_char_str_format[ 2 ] = 0;

	boring_printf_1( three_char_str_format );

	boring_printf_2( three_char_str_format );

	boring_printf_3( three_char_str_format );

	boring_printf_4( three_char_str_format );

	boring_debugf( three_char_str_format, "yo" );

	three_char_str_format[ 2 ] = '`';

	boring_printf_1( three_char_str_format );

	boring_printf_2( three_char_str_format );

	boring_printf_3( three_char_str_format );

	boring_printf_4( three_char_str_format );

	boring_debugf( three_char_str_format, "yo" );


}
