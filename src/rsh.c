/*
 * rsh.c
 *
 * Copyright (C) 2022  Leonard Steinhoff
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>


void usage_map(FILE* dest)
{
	fprintf(dest, "Usage: rsh [options]\n");
	fprintf(dest, "  -v    Shows active version of RSH\n");
	fprintf(dest, "  -h    Prints usage map\n");
	fprintf(dest, "  -e    Login as effective user\n");
	fprintf(dest, "	 -d    Spawn shell in specific directory\n"); 
}

int parse_args(int argc, char* argv[])
{
	int i;
	while (i < argc)
	{
		if (argv[i+1][0] == '-')
		{
			switch (argv[i][1])
			{
			case 'e':
				/*
				 * Login as effective user
				*/
				setuid(geteuid());	
				break;
			case 'h':
				/*
				 * Prints the usage map
				*/
				usage_map(stdout);
				break;
			default:
				/*
				 * Invalid arg
				*/
				perror("Invalid argument!");
				usage_map(stderr);
				break;
			}
		} 
		else 
		{
			perror("Invalid argument!");
		}
		i++;
	}
}

int main(int argc, char* argv[])
{
	if (!parse_args( argc, argv ))
		return 1;

	return 0;
}


