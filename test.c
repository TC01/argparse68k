// C Source File
// Created 3/17/2016; 2:32:57 AM

// Delete or comment out the items you do not need.
#define COMMENT_STRING         "Place your comment here."
#define COMMENT_PROGRAM_NAME   "Place your program name here."
#define COMMENT_VERSION_STRING "Place your version string here."
#define COMMENT_VERSION_NUMBER 0,0,0,0 /* major, minor, revision, subrevision */
#define COMMENT_AUTHORS        "Place your author name(s) here."

#include <tigcclib.h>

#include "argparse.h"

// Main Function
void _main(void)
{
	const char* arg = get_str_arg(0, 1, "Hello world!");
	printf(arg);
}
