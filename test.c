// C Source File
// Created 3/17/2016; 2:32:57 AM

// Delete or comment out the items you do not need.
#define COMMENT_STRING         "argparse68k example"
#define COMMENT_PROGRAM_NAME   "example"
#define COMMENT_VERSION_STRING "1.0"
#define COMMENT_VERSION_NUMBER 1,0,0,0 /* major, minor, revision, subrevision */
#define COMMENT_AUTHORS        "Ben 'TC01' Rosser"

// Enable error returns; argparse68k uses this functionality.
#define ENABLE_ERROR_RETURN

#include <tigcclib.h>

// Include the argparse68k library's header file.
#include "argparse.h"

// Main Function
void _main(void)
{
	// This means "ask for the 0th argument, throw ER:ARGUMENT if it is not there.
	int val = get_int_arg(0, 0, 0);
	
	// This means "ask for the 1st argument, if it is not there, return "Hello world!"
	const char* arg = get_str_arg(1, 1, "Hello world!");

	// Now print out the arguments so the user can see what happened.
	clrscr();
	printf("Integer arg: %d\n", (int)val);
	printf(arg);
	ngetchx();
}

