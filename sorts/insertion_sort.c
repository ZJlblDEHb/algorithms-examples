/*
 * insertion_sort.c
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


#include "../lib/tools.h"

void sort_array(int array_size, int *input_array) {
	int i, j, key;
	
	for (j = 1; j < array_size; ++j) {
		key = input_array[j];
		
		i = j - 1;
		while ((i >= 0) & (input_array[i] > key)) {
			input_array[i+1] = input_array[i];
			i = i - 1;
		}
		input_array[i+1] = key;
	}
}

void sort_array_recursive(int array_size, int *input_array) {
	int i, key;
	
	if (array_size > 1) {
		key = input_array[array_size - 1];
		
		sort_array_recursive(array_size - 1, input_array);
		
		i = array_size - 2;
		while (i >= 0 & input_array[i] > key) {
			input_array[i+1] = input_array[i];
			i = i - 1;
		}
		input_array[i+1] = key;
	}
}

int main()
{
	int *input_array;
	int array_size = 10;
	input_array = malloc(array_size * sizeof(int));
	
	fill_array(array_size, input_array);
	
	print_array(array_size, input_array);
	
	sort_array_recursive(array_size, input_array);
	
	print_array(array_size, input_array);
	
	free(input_array);
	
	return 0;
}
