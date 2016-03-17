// C Source File
// Created 3/16/2016; 9:49:29 PM

//#define _GENERIC_ARCHIVE

#include <tigcclib.h>

int bounds_check(int index, int silent)
{
	if (!((0 < index) && (index < (int)ArgCount())))
	{
		if (silent <= 0)
		{
			ER_throw(ER_ARGUMENT);
		}
		return 0;
	}
	return 1;
}

int type_check(CESI argptr, int silent, enum Tags type)
{
	if (GetArgType(argptr) != type)
	{
		if (silent <= 0)
		{
			ER_throw(ER_ARGUMENT);
		}
		return 0;
	}
	return 1;
}

int get_int_arg(int index, int silent, int default_val)
{
	ESI argptr;

	if (bounds_check(index, silent) == 0)
	{
		return default_val;
	}
	
	argptr = EX_getArg(index);
	if (type_check(argptr, silent, INT_TAG) == 0)
	{
		return default_val;
	}
	else
	{
		return GetIntArg(argptr);
	}
}

float get_float_arg(int index, int silent, float default_val)
{
	ESI argptr;

	if (bounds_check(index, silent) == 0)
	{
		return default_val;
	}
	
	argptr = EX_getArg(index);
	if (type_check(argptr, silent, FLOAT_TAG) == 0)
	{
		return default_val;
	}
	else
	{
		return GetFloatArg(argptr);
	}
}

const char* get_str_arg(int index, int silent, const char* default_val)
{
	ESI argptr;

	if (bounds_check(index, silent) == 0)
	{
		return default_val;
	}
	
	argptr = EX_getArg(index);
	if (type_check(argptr, silent, STR_TAG) == 0)
	{
		return default_val;
	}
	else
	{
		return GetStrnArg(argptr);
	}
}