// Header File
// Created 3/16/2016; 9:49:34 PM

/* check_max_args: throws an exception if there are too many arguments.

 * max: the maximum number of arguments to allow.
 
 * check_max_args takes an integer argument, *max*, and if more than
 * *max* aguments were passed to the program, it throws ER_ARGUMENT.
 * Note that "max" is not a zero-indexed parameter here (whereas all
 * the other argparse.h functions take zero-indexed arguments).
 */
void check_max_args(int max);

/* get_int_arg: retrieves an integer argument passed to the program.

 * index: the argument number to retrieve, starting from 0.
 * silent: if silent is a positive integer, do not throw ER_ARGUMENT
   on failure. if silent <= 0, throw ER_ARGUMENT.
 * default_val: if silent is set and we fail to parse an argument,
   return default_val.
   
 * get_int_arg returns an integer equal to the integer value passed
   to the program as the (index)th argument. In the event of failure,
   get_int_arg returns default_val or throws ER_ARGUMENT depending on
   the value of silent (as described above).
 */
int get_int_arg(int index, int silent, int default_val);

/* get_pos_int_arg: retrieves a positive integer argument passed to the program.

 * index: the argument number to retrieve, starting from 0.
 * silent: if silent is a positive integer, do not throw ER_ARGUMENT
   on failure. if silent <= 0, throw ER_ARGUMENT.
 * default_val: if silent is set and we fail to parse an argument,
   return default_val.
   
 * get_pos_int_arg is identical to get_int_arg, but only will parse
   a positive integer.
 */
int get_pos_int_arg(int index, int silent, int default_val);

/* get_neg_int_arg: retrieves a negative integer argument passed to the program.

 * index: the argument number to retrieve, starting from 0.
 * silent: if silent is a positive integer, do not throw ER_ARGUMENT
   on failure. if silent <= 0, throw ER_ARGUMENT.
 * default_val: if silent is set and we fail to parse an argument,
   return default_val.
   
 * get_neg_int_arg is identical to get_int_arg, but only will parse
   a positive integer.
 */
int get_neg_int_arg(int index, int silent, int default_val);

/* get_float_arg: retrieves an floating point argument passed to the program.

 * index: the argument number to retrieve, starting from 0.
 * silent: if silent is a positive integer, do not throw ER_ARGUMENT
   on failure. if silent <= 0, throw ER_ARGUMENT.
 * default_val: if silent is set and we fail to parse an argument,
   return default_val.
   
 * get_float_arg returns an float equal to the floating point value passed
   to the program as the (index)th argument. In the event of failure,
   get_int_arg returns default_val or throws ER_ARGUMENT depending on
   the value of silent (as described above).
 */
float get_float_arg(int index, int silent, float default_val);

/* get_str_arg: retrieves an string argument passed to the program.

 * index: the argument number to retrieve, starting from 0.
 * silent: if silent is a positive integer, do not throw ER_ARGUMENT
   on failure. if silent <= 0, throw ER_ARGUMENT.
 * default_val: if silent is set and we fail to parse an argument,
   return default_val.
   
 * get_str_arg returns a const character pointer to the string argument
   passed to the program as the (index)th argument. In the event of failure,
   get_int_arg returns default_val or throws ER_ARGUMENT depending on
   the value of silent (as described above).
 */
const char* get_str_arg(int index, int silent, const char* default_val);

