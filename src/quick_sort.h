/**	NIM:		13515065
	Nama:		Felix Limanta
	Tanggal:	24 Februari 2017
	File:		quick_sort.h
	Topik;		Divide and Conquer
	Deskripsi:	Definisi dan realisasi algoritma quick sort
  */

#ifndef __QUICK_SORT__
#define __QUICK_SORT__

#include <cstdlib>

/**	@brief	Partitioning process
	Partitions array such that every value on the left is less than every value on the right
	@param	data	array of data to be sorted
	@param	low		lower bound index of array
	@param	high	higher bound index of array
	@param	mid		index of partitioning point
	Every data on the left of partitioning point is less than data on the right
  */
template <class T>
void partition (T data[], size_t low, size_t high, size_t& mid) {
	// Set pivot as middle element
	int pivot = data[(low + high) / 2];
	
	int i = low, j = high;
	do {
		// Seek element left of pivot greater than pivot
		while (data[i] < pivot)
			i++;
		
		// Seek element right of pivot less than pivot
		while (data[j] > pivot)
			j--;
		
		// Swap if iterators haven't passed by each other
		if (i <= j) {
			int temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
		
		// Increment for next iteration
		i++;
		j--;		
	} while (i <= j);	// Stop if iterators have passed by each other
	mid = j;
}

/**	@brief	Quick Sort
	Sort array of data with quick sort	
	@param	data	data to be sorted
	@param	low		lower bound index of data
	@param	high	higher bound index of data
  */
template <class T>
void quick_sort (T data[], size_t low, size_t high) {
	if (low >= high) {	// Basis, 1 elmt
		// Do nothing, 1 elmt already sorted
	} else {	// Recurrence
		// Divide
		int mid;
		partition(data, low, high, mid);
		
		// Conquer
		quick_sort(data, low, mid);
		quick_sort(data, mid + 1, high);
		
		// Combine: do nothing
	}
}

/**	@brief	Quick Sort
	Sort array of data with quick sort	
	Wrapper for quick_sort(data,low,high)
	@param	data	data to be sorted
	@param	size	size of data to be sorted	
  */
template <class T>
void quick_sort (T data[], size_t size) {
	merge_sort(data, 0, size-1);
}

#endif