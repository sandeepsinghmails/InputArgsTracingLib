/*
* Author: Sandeep Singh
* Date  : July 13, 2013
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
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

extern const char *__progname;

void call_input_args_tracing_lib (int num_params, ...)
{

	int 		arg_index=0;
	void		*p_var;
	char		*data_type;
	va_list 	ap;
    char 		buffer[200];

	va_start(ap, num_params);
	
	sprintf (buffer, "echo 'set print pretty on' > gdbcmds");
    system(buffer);
	
	sprintf(buffer, "echo 'fr 3' >> gdbcmds");
    system(buffer);

    for(arg_index =  1; 
		arg_index <= num_params; 
		arg_index++) 
	{
		p_var 	   = va_arg (ap, void*);
		data_type  = va_arg (ap, char*);
		
		if ('@'==data_type[1])
		{
			sprintf(buffer, "echo 'p *(%s*)%p@%c' >> gdbcmds", data_type+2, p_var, data_type[0]);			
		}
		else
		{
    			sprintf(buffer, "echo 'p *(%s*)%p' >> gdbcmds", data_type, p_var);
		}
    	system(buffer);
    }
    va_end(ap);

    sprintf(
	buffer, 
	"echo 'where\ndetach' | gdb -batch --command=gdbcmds %s %d >> InputArgsTracingLogs.txt", 
	__progname, 
	getpid()  );
    system(buffer);

    sprintf(buffer, "cat InputArgsTracingLogs.txt");
    system(buffer);
}
