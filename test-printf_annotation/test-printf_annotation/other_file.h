#include <windows.h>


void naked_printf_annotation( _Printf_format_string_ char* const ptr );
void PSTR_printf_annotation( _Printf_format_string_ PSTR const ptr );
void proper_printf_annotation( _In_z_ _Printf_format_string_ PSTR const ptr );



void noINannos( PSTR const ptr );

void INannos( _In_z_ PSTR const ptr );