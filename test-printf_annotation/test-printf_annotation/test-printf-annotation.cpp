#include <cstdio>
#include <windows.h>
#include <memory>
#include <vector>

#include "other_file.h"
#include "printf_custom.h"


void boring_printf( _In_z_ _Printf_format_string_ const char* const ptr ) {
	printf( ptr, "" );
	}


int main( ) {
	//char* const nullPTR = nullptr;
	char c = L'c';
	char* const ptr = &c;
	char non_str[ 2 ] = { 'c', 'c' };
	std::unique_ptr<char> uptr = std::make_unique<char>( 'c' );
	std::vector<char> fake_big_str;
	fake_big_str.resize( 4090 );
	for ( auto& character : fake_big_str ) {
		character = 'A';
		}

	//noINannos( nullPTR );
	//INannos( nullPTR );
	//naked_printf_annotation( nullPTR );
	//PSTR_printf_annotation( nullPTR );
	//proper_printf_annotation( nullPTR );
	//printf( nullPTR );



	naked_printf_annotation( ptr );
	PSTR_printf_annotation( ptr );
	proper_printf_annotation( ptr );
	noINannos( ptr );
	INannos( ptr );
	printf( ptr );
	custom_printf( ptr );

	naked_printf_annotation( non_str );
	PSTR_printf_annotation( non_str );
	proper_printf_annotation( non_str );
	noINannos( non_str );
	INannos( non_str );
	printf( non_str );
	custom_printf( non_str );

	naked_printf_annotation( uptr.get( ) );
	PSTR_printf_annotation( uptr.get( ) );
	proper_printf_annotation( uptr.get( ) );
	noINannos( uptr.get( ) );
	INannos( uptr.get( ) );
	printf( uptr.get( ) );
	custom_printf( uptr.get( ) );

	printf( "fake_big_str data pointer: %p\r\n", fake_big_str.data( ) );
	Sleep( 5000000 );

	naked_printf_annotation( fake_big_str.data( ) );
	PSTR_printf_annotation( fake_big_str.data( ) );
	proper_printf_annotation( fake_big_str.data( ) );
	noINannos( fake_big_str.data( ) );
	INannos( fake_big_str.data( ) );
	printf( fake_big_str.data( ) );
	custom_printf( fake_big_str.data( ) );


	char valid_string[ 7 ] = "aaaaaa";
	char copy_valid_string[ 1000 ] = { };

	strcpy_s( copy_valid_string, valid_string );

	naked_printf_annotation( valid_string );
	PSTR_printf_annotation( valid_string );
	proper_printf_annotation( valid_string );
	noINannos( valid_string );
	INannos( valid_string );
	printf( valid_string );
	custom_printf( valid_string );

	valid_string[ 6 ] = 'a';
	
	naked_printf_annotation( valid_string );
	PSTR_printf_annotation( valid_string );
	proper_printf_annotation( valid_string );
	noINannos( valid_string );
	INannos( valid_string );
	printf( valid_string );
	custom_printf( valid_string );

	strcpy_s( copy_valid_string, valid_string );
	

	char three_char_str_format[ 3 ] = "%s";

	boring_printf( three_char_str_format );
	three_char_str_format[ 2 ] = '`';
	boring_printf( three_char_str_format );
}
