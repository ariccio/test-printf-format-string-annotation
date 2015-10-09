#include <Windows.h>
#include <cstdarg>
#include <cstdio>

inline void custom_vprintf( _In_z_ _Printf_format_string_ const char* const format, va_list args ) {
	char buffer[ 512u ] = { };
	_vsnprintf_s( buffer, _TRUNCATE, format, args );
	( void ) buffer;
	}

inline void custom_printf( _In_z_ _Printf_format_string_ const char* const format, ... ) {
	va_list args;
	va_start( args, format );
	custom_vprintf( format, args );
	va_end( args );
	}

