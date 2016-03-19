// C Source File
// Created 3/16/2016; 9:49:29 PM

//#define _GENERIC_ARCHIVE

#define ENABLE_ERROR_RETURN

#include <args.h>
#include <error.h>

// Define an 'empty' tag using one the AMS does not use.
#define NULL_TAG _VAR_Q_TAG

/* Helper function to check if an argument index is valid.
   Takes an integer index, throws ER_ARGUMENT if it is less than zero
   or greater than or equal to the number of argumennts actually
   passed to the program.
 */
void bounds_check(int index)
{
	if (!((0 <= index) && (index < (int)ArgCount())))
	{
		ER_throw(ER_ARGUMENT);
	}
}

/* Helper function to check if an argument type is valid.
   Takes a CESI argument pointer and up to two character types.
   If the type of the argument pointer is neither of these,
   throw ER_ARGUMENT.
 */
void type_check(CESI argptr, unsigned char type, unsigned char type2)
{
	unsigned char argtype;
	argtype = GetArgType(argptr);
	
	int success = 1;

	// We assume that NULL_TAG is the equivalent to "no type"
	// (so you can run this function with 1 or two arguments).
	if (argtype != type)
	{
		if (type2 != NULL_TAG && argtype == type)
		{
			success = 1;
		}
		else
		{
			success = 0;
		}
	}

	// Throw ER_ARGUMENT if we failed.
	if (!success)
	{
		ER_throw(ER_ARGUMENT);
	}
}

// Method to check the maximum number of arguments.
// Definition in argparse.h.

void check_max_args(int max)
{
	if ((int)ArgCount() > max)
	{
		ER_throw(ER_ARGUMENT);
	}
}

// The following routines are more or less the same.
// Their method definitions are in argparse.h.
// Inline comments provided where one diverges significantly.

int get_int_arg(int index, int silent, int default_val)
{
	ESI argptr;
	int result;

	// Use TIGCC style try/except blocks here.
	TRY
		// First check bounds, then call EX_getArg if the check succeeds
		// (i.e. does not throw an exception).
		bounds_check(index);
		argptr = EX_getArg(index);

		// If we get this far, then call a type check and then process the results.
		type_check(argptr, POSINT_TAG, NEGINT_TAG);
		result = GetIntArg(argptr);
	
	// If an error happens and silent is set, assign result anyway.
	ONERR
		if (silent > 0 && errCode == ER_ARGUMENT) {
			result = default_val;
		}	else {
			PASS;
		}
	ENDTRY

	// Return the result (if we got this far).
	return result;
}

int get_pos_int_arg(int index, int silent, int default_val)
{
	ESI argptr;
	int result;

	// Use TIGCC style try/except blocks here.
	TRY
		// First check bounds, then call EX_getArg if the check succeeds
		// (i.e. does not throw an exception).
		bounds_check(index);
		argptr = EX_getArg(index);

		// If we get this far, then call a type check and then process the results.
		type_check(argptr, POSINT_TAG, NULL_TAG);
		result = GetIntArg(argptr);
	
	// If an error happens and silent is set, assign result anyway.
	ONERR
		if (silent > 0 && errCode == ER_ARGUMENT) {
			result = default_val;
		}	else {
			PASS;
		}
	ENDTRY

	// Return the result (if we got this far).
	return result;
}

int get_neg_int_arg(int index, int silent, int default_val)
{
	ESI argptr;
	int result;

	// Use TIGCC style try/except blocks here.
	TRY
		// First check bounds, then call EX_getArg if the check succeeds
		// (i.e. does not throw an exception).
		bounds_check(index);
		argptr = EX_getArg(index);

		// If we get this far, then call a type check and then process the results.
		type_check(argptr, NEGINT_TAG, NULL_TAG);
		result = GetIntArg(argptr);
	
	// If an error happens and silent is set, assign result anyway.
	ONERR
		if (silent > 0 && errCode == ER_ARGUMENT) {
			result = default_val;
		}	else {
			PASS;
		}
	ENDTRY

	// Return the result (if we got this far).
	return result;
}

float get_float_arg(int index, int silent, float default_val)
{
	ESI argptr;
	float result;

	// Use TIGCC style try/except blocks here.
	TRY
		// First check bounds, then call EX_getArg if the check succeeds
		// (i.e. does not throw an exception).
		bounds_check(index);
		argptr = EX_getArg(index);

		// If we get this far, then call a type check and then process the results.
		type_check(argptr, FLOAT_TAG, NULL_TAG);
		result = GetFloatArg(argptr);
	
	// If an error happens and silent is set, assign result anyway.
	ONERR
		if (silent > 0 && errCode == ER_ARGUMENT) {
			result = default_val;
		}	else {
			PASS;
		}
	ENDTRY

	// Return the result (if we got this far).
	return result;
}

const char* get_str_arg(int index, int silent, const char* default_val)
{
	ESI argptr;
	const char* result;

	// Use TIGCC style try/except blocks here.
	TRY
		// First check bounds, then call EX_getArg if the check succeeds
		// (i.e. does not throw an exception).
		bounds_check(index);
		argptr = EX_getArg(index);

		// If we get this far, then call a type check and then process the results.
		type_check(argptr, STR_TAG, NULL_TAG);
		result = GetStrnArg(argptr);
	
	// If an error happens and silent is set, assign result anyway.
	ONERR
		if (silent > 0 && errCode == ER_ARGUMENT) {
			result = default_val;
		}	else {
			PASS;
		}
	ENDTRY

	// Return the result (if we got this far).
	return result;
}

