/*
 * tools.h
 * 
 * Copyright 2014 asergeev <asergeev@asergeev-xub>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>

#ifndef tools
#define tools

void print_array(int array_size, int *input_array) {
	int i = 0;
	printf("[");
	for (i = 0; i < array_size; ++i) {
		if (i != 0) {
			printf(", ");
		}
		printf("%d", input_array[i]);
	}
	printf("]\n");
}

void fill_array(int array_size, int *input_array) {
	int i = 0;
	// fill array with random numbers
	for (i = 0; i < array_size; ++i) {
		input_array[i] = rand() % 20;
	}
}

#endif
