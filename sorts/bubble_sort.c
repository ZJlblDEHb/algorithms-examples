/*
 * bubble_sort.c
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


#include <limits.h>
#include "../lib/tools.h"

void bubble_sort(int array_size, int *input_array) {
	int i, j, temp;
	
	for (i = 0; i < array_size - 1; ++i) {
		for (j = array_size - 1; j > i; --j) {
			if (input_array[j] < input_array[j - 1]) {
				temp = input_array[j];
				input_array[j] = input_array[j - 1];
				input_array[j - 1] = temp;
			}
		}
	}
}

int main()
{
	int *input_array;
	int array_size = 20;
	input_array = malloc(array_size * sizeof(int));
	
	fill_array(array_size, input_array);
	
	print_array(array_size, input_array);
	
	bubble_sort(array_size, input_array);
	
	print_array(array_size, input_array);
	
	free(input_array);
	
	return 0;
}

