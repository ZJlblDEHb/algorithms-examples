/*
 * linear_search.c
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
#include "../lib/tools.h"

int search(int *input_array, int array_size, int element) {
	int i;
	for (i = 0; i < array_size; ++i) {
		if (element == input_array[i]) {
			return i;
		}
	}
	return -1;
}

int main(int argc, char **argv)
{
	int *input_array, result;
	int array_size = 10;
	int element = 17;
	input_array = malloc(array_size * sizeof(int));
	
	fill_array(array_size, input_array);
	
	print_array(array_size, input_array);
	
	result = search(input_array, array_size, element);
	
	if (result != -1) {
		printf("element found at position %d\n", result);
	}
	else {
		printf("element not found!\n");
	}
	
	free(input_array);
	
	return 0;
}

