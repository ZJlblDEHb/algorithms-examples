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


#include <limits.h>
#include "../lib/tools.h"

void merge(int *input_array, int start, int mid, int end) {
	int first_size, second_size, i, j, k, *first_half, *second_half;
	first_size = mid - start + 1;
	second_size = end - mid;
	
	first_half = malloc((first_size + 1) * sizeof(int));
	second_half = malloc((second_size + 1) * sizeof(int));
	
	for (i = 0; i < first_size; ++i) {
		first_half[i] = input_array[start + i];
	}
	
	for (j = 0; j < second_size; ++j) {
		second_half[j] = input_array[mid + j + 1];
	}	
	
	first_half[first_size] = INT_MAX;
	second_half[second_size] = INT_MAX;	
	
	i = 0;
	j = 0;
	for (k = start; k <= end; ++k) {
		if (first_half[i] <= second_half[j]) {
			input_array[k] = first_half[i];
			i += 1;
		}
		else {
			input_array[k] = second_half[j];
			j += 1;
		}
	}
	
	free(first_half);
	free(second_half);
}

void merge_without_sentinel(int *input_array, int start, int mid, int end) {
	int first_size, second_size, i, j, k, *first_half, *second_half;
	first_size = mid - start + 1;
	second_size = end - mid;
	
	first_half = malloc((first_size) * sizeof(int));
	second_half = malloc((second_size) * sizeof(int));
	
	for (i = 0; i < first_size; ++i) {
		first_half[i] = input_array[start + i];
	}
	
	for (j = 0; j < second_size; ++j) {
		second_half[j] = input_array[mid + j + 1];
	}	
	
	i = 0;
	j = 0;
	for (k = start; k <= end; ++k) {
		if ((j == second_size | first_half[i] <= second_half[j]) & i != first_size) {
			input_array[k] = first_half[i];
			i += 1;
		}
		else {
			input_array[k] = second_half[j];
			j += 1;
		}
	}
	
	free(first_half);
	free(second_half);
}

void merge_sort(int *input_array, int start, int end) {
	int mid;
	
	if (start < end) {
		mid = (start + end) / 2;		
		merge_sort(input_array, start, mid);
		merge_sort(input_array, mid + 1, end);
		merge_without_sentinel(input_array, start, mid, end);
	}
}

void sort_array(int array_size, int *input_array) {
	merge_sort(input_array, 0, array_size - 1);
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
