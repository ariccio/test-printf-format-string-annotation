#include <Windows.h>
#include "other_file.h"
#include "printf_custom.h"
#include <cstdio>
#include <memory>
#include <strsafe.h>

rsize_t custom_strlen( _In_z_ const char* const ptr ) {
	rsize_t count = 0u;
	const char* ptr_iter = ptr;	
	while ( (*ptr_iter) != 0 ) {
		++ptr_iter;
		}
	return count;
	}

void naked_printf_annotation( _Printf_format_string_ char* const ptr ) {
	const rsize_t alloc_size_needed = custom_strlen( ptr );
	std::unique_ptr<char[ ]> new_char_buffer = std::make_unique<char[ ]>( alloc_size_needed );
	StringCchCopyA( new_char_buffer.get( ), alloc_size_needed, ptr );
	custom_printf( "`%s`\r\n", new_char_buffer.get( ) );
	}

void PSTR_printf_annotation( _Printf_format_string_ PSTR const ptr ) {
	const rsize_t alloc_size_needed = custom_strlen( ptr );
	std::unique_ptr<char[ ]> new_char_buffer = std::make_unique<char[ ]>( alloc_size_needed );
	StringCchCopyA( new_char_buffer.get( ), alloc_size_needed, ptr );
	custom_printf( "`%s`\r\n", new_char_buffer.get( ) );
	}

void proper_printf_annotation( _In_z_ _Printf_format_string_ PSTR const ptr ) {
	const rsize_t alloc_size_needed = custom_strlen( ptr );
	std::unique_ptr<char[ ]> new_char_buffer = std::make_unique<char[ ]>( alloc_size_needed );
	StringCchCopyA( new_char_buffer.get( ), alloc_size_needed, ptr );
	custom_printf( "`%s`\r\n", new_char_buffer.get( ) );
	}

void noINannos( PSTR const ptr ) {
	const rsize_t alloc_size_needed = custom_strlen( ptr );
	std::unique_ptr<char[ ]> new_char_buffer = std::make_unique<char[ ]>( alloc_size_needed );
	StringCchCopyA( new_char_buffer.get( ), alloc_size_needed, ptr );
	custom_printf( "`%s`\r\n", new_char_buffer.get( ) );
	}

void INannos( _In_z_ PSTR const ptr ) {
	const rsize_t alloc_size_needed = custom_strlen( ptr );
	std::unique_ptr<char[ ]> new_char_buffer = std::make_unique<char[ ]>( alloc_size_needed );
	StringCchCopyA( new_char_buffer.get( ), alloc_size_needed, ptr );
	custom_printf( "`%s`\r\n", new_char_buffer.get( ) );
	}
