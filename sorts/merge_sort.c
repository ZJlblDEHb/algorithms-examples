/*
 * merge_sort.c
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


#include "tools.h"

void merge(int input_array, int start, int mid, int end) {
	int first_size, second_size, i, j, *first_half, *second_half;
	first_size = mid - start + 1;
	second_size = end - mid;
	
	first_half = malloc(first_size * sizeof(int));
	second_half = malloc(second_size * sizeof(int));
	
	for (i = 0; i < first_size; ++i) {
		first_half = input_array[start + i - 1];
	}
	
	for (i = 0; i < second_size; ++i) {
		second_half = input_array[mid + i];
	}
	
	i = 0;
	j = 0;
	
}

void sort_array(int array_size, int *input_array) {
	int i, j, key, temp;
	
	for (j = 0; j < array_size - 1; ++j) {
		key = j;
		
		for (i = j + 1; i < array_size; ++i) {
			if (input_array[key] > input_array[i]) {
				key = i;
			}
		}
		
		temp = input_array[j];
		input_array[j] = input_array[key];
		input_array[key] = temp;
	}
}

int main()
{
	int *input_array;
	int array_size = 10;
	input_array = malloc(array_size * sizeof(int));
	
	fill_array(array_size, input_array);
	
	print_array(array_size, input_array);
	
	sort_array(array_size, input_array);
	
	print_array(array_size, input_array);
	
	free(input_array);
	
	return 0;
}
