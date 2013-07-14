/*
* Author: Sandeep Singh
* Date  : July 13, 2013
*
* File  : sample_test_stub.c
*
* Description: This File contains Sample Functions - to demonstrate the Use
*              of InputArgsTracingLib
*
* Copyright 2013 Sandeep Singh (sandeepsinghmails@gmail.com)
*
* This file is part of InputArgsTracingLib.
* InputArgsTracingLib is free software: you can redistribute it
* and/or modify it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* InputArgsTracingLib is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.

* You should have received a copy of the GNU General Public License
* along with InputArgsTracingLib. If not, see <http://www.gnu.org/licenses/>.
*
* Compile as follows:
* gcc -g -c -ansi -Wall -pedantic -DUSE_IP_ARGS_TRACING_LIB sample_test_stub.c
* gcc sample_test_stub.o -L lib/ -lInputArgsTracing -o test_executable
*
*/
#include <stdio.h>
#include <string.h>

/* Basic Data Types */
typedef	int			int_t;
typedef char		char_t;

/* Complex Structure */
typedef struct
{
	char_t			s4_1 [15];
	int_t			s4_2;
} struct4_st;

typedef struct
{
	char_t			s3_1 [15];
	int_t 			s3_2;
} struct3_st;

typedef struct
{
	struct3_st		s2_1;
	struct4_st		s2_2;
} struct2_st;


typedef struct
{
	int_t	 		s1_1;
	char_t	 		s1_2;
	struct2_st  	s1_3;
} struct1_st;

struct sample
{
    int_t 			sample1;
    int_t 			sample2;
	char_t 			sample3[20];
	struct1_st 		sample4;
};

void driver_function1 (int_t  			*pval,
					   char_t 			*p_array,
					   struct sample 	*p_sample_var)
{
	/* To Get the I/P Parameter Trace, Just Add this Function Call at the 
	 * Beginning of Each Function
	 */
	#ifdef USE_IP_ARGS_TRACING_LIB
	call_input_args_tracing_lib (
					 3, 				/* No. of Parameters 	*/

					 pval,				/* Address   of Param-1 */
					 "int_t",			/* Data Type of Param-1 */

					 &p_array,			/* Address   of Param-2 */
					 "char_t*",			/* Data Type of Param-2 */

					 p_sample_var,		/* Address   of Param-3 */
					 "struct sample"	/* Data Type of Param-3 */
					 );
	#endif

	/* Done with Tracing, Now Get Back To Your Work :) */
}

void driver_function2 (int_t   val2,
					   char_t* string2)
{
	#ifdef USE_IP_ARGS_TRACING_LIB
	call_input_args_tracing_lib (
					2,					/* No. of Parameters 	*/
					 
					&val2,				/* Address   of Param-1 */
					"int_t",			/* Data Type of Param-1 */
					 
					&string2,			/* Address   of Param-2 */
					"char_t*");			/* Data Type of Param-2 */
	#endif
	
	/* Done with Tracing, Now Get Back To Your Work :) */
}

int main ()
{
	struct sample 				sample_var;
	int_t val 					= 47;
	char_t			string[10] 	= "Main";

	char_t			string2[10] = "Driver2";
	int_t			val2 		= 21;

	/* Fill the Complex Structure */
	sample_var.sample1 = 47;
	sample_var.sample2 = 79;
	strncpy (sample_var.sample3, "Sample Structure", sizeof("Sample Structure"));
	sample_var.sample4.s1_1 = 97;
	sample_var.sample4.s1_2 = 'y';
	strncpy (sample_var.sample4.s1_3.s2_1.s3_1, 
			"Structure3", 
			sizeof("Structure3"));
	sample_var.sample4.s1_3.s2_1.s3_2 = 32;

	strncpy (sample_var.sample4.s1_3.s2_2.s4_1, "Structure4", 
			 sizeof("Structure4"));

	sample_var.sample4.s1_3.s2_2.s4_2 = 89;

	driver_function1 (&val, 
		  			  string,
		  			  &sample_var);

	driver_function2 (val2,
					  string2);
	
	return 0;
}

