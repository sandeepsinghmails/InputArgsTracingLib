**InputArgsTracingLib**
========================

This Library provides Pretty Printing of the Values of Input Parameters of A Function.

It can easily provide pretty-printed Multilevel Complex Structures which are passed as Input Parameters for the concerned functions.


**What Changes are required in your Source Code for Integration with InputArgsTracingLib ?**

Very small Changes are required to Integrate InputArgsTracingLib with your Source Code.

Suppose you have a Function func() - whose Input Parameters need to be printed.

At the Beginning of the Function, just include a single statement (preferably under some customized UT Flags for your code):

call_input_args_tracing_lib (
					 3, 				/* No. of I/P Parameters 	*/

					 pval,				/* Address   of Param-1 */
					 "int_t",			/* Data Type of Param-1 */

					 &p_array,			/* Address   of Param-2 */
					 "char_t*",			/* Data Type of Param-2 */

					 p_sample_var,		/* Address   of Param-3 */
					 "struct sample"	/* Data Type of Param-3 */
					 );

You can Pass ANY Number of Input Parameters for printing with InputArgsTracingLib.

Please make sure that your process is running without GDB.


**How To Compile InputArgsTracingLib ?**

$make clean

$make

**How To Link InputArgsTracingLib To Your Source Code ?**

In your Project, you must be creating some final executable by Linking .o (object) Files.

To Integrate InputArgsTracingLib with your Source Code, you just need to add it to the list of Static Libraries while creating your Final Executable.

Example:

*gcc -g -c -ansi -Wall -pedantic -DUSE_IP_ARGS_TRACING_LIB sample_test_stub.c*

*gcc sample_test_stub.o -L lib/ -lInputArgsTracing -o test_executable*


**InputArgsTracingLib Logs**

Once you have Integrated this Library with your executable, a Log-File named: *InputArgsTracingLogs.txt* will be generated at 
the same path from where you are executing your executable.

**Screenshots:**

**Complex Structures as Input Parameters:**

![Complex Structures ](https://raw.github.com/sandeepsinghmails/InputArgsTracingLib/master/Images/InputArgsTracingLib_Sample_Usage_1.jpeg)

![Complex Structures ](https://raw.github.com/sandeepsinghmails/InputArgsTracingLib/master/Images/InputArgsTracingLib_Sample_Usage_2.jpeg)

**Output Generated by InputArgsTracingLib**

![Output](https://raw.github.com/sandeepsinghmails/InputArgsTracingLib/master/Images/InputArgsTracingLib_Sample_Usage_3.jpeg)


**Comments/Feedback**

Feedback/ Comments on the InputArgsTracingLib are always Welcome.

If you would like to share any feedback/comments on this Utility, please feel free to mail me at sandeepsinghmails@gmail.com

