/**	NIM:		13515065
	Nama:		Felix Limanta
	Tanggal:	24 Februari 2017
	File:		merge_sort.h
	Topik;		Divide and Conquer
	Deskripsi:	Definisi dan realisasi algoritma merge sort
  */

#ifndef __MERGE_SORT__
#define __MERGE_SORT__

#include <array>
#include <cstdlib>

/**	@brief	Merging process
	Consolidates data from two subarrays to one sorted array
	@param	data	array of data to be sorted
	@param	low		lower bound index of first subarray
	@param	mid		higher bound index of first subarray
	@param	high	higher bound index of second subarray
	Lower bound index of second subarray assumed to be mid + 1
  */
template <class T>
void merge (T data[], size_t low, size_t mid, size_t high) {
	size_t l1 = low, l2 = mid + 1, i, j;
	T* temp = new T[high - low + 1];
	
	// Consolidate both arrays
	for (i = 0; l1 <= mid && l2 <= high; ++i) {
		if (data[l1] <= data[l2])
			temp[i] = data[l1++];
		else
			temp[i] = data[l2++];
	}
	
	// Move remaining elmt of 1st array
	while (l1 <= mid)
		temp[i++] = data[l1++];
	
	// Move remaining elmt of 2nd array
	while (l2 <= high)
		temp[i++] = data[l2++];
	
	// Copy data fron temp array to actual array
	for (i = low, j = 0; i <= high; ++i, ++j)
		data[i] = temp[j];
	
	delete [] temp;
}

/**	@brief	Merge Sort
	Sort array of data with merge sort	
	@param	data	data to be sorted
	@param	low		lower bound index of data
	@param	high	higher bound index of data
  */
template <class T>
void merge_sort (T data[], size_t low, size_t high) {
	if (low >= high) {	// Basis, 1 elmt
		// Do nothing, 1 elmt already sorted
	} else {	// Recurrence
		// Divide
		int mid = (low + high) / 2;
		
		// Conquer
		merge_sort(data, low , mid);
		merge_sort(data, mid + 1, high);
		
		// Combine
		merge(data, low, mid, high);
	}
}

/**	@brief	Merge Sort
	Sort array of data with merge sort	
	Wrapper for merge_sort(data,low,high)
	@param	data	data to be sorted
	@param	size	size of data to be sorted	
  */
template <class T>
void merge_sort (T data[], size_t size) {
	merge_sort(data, 0, size-1);
}

#endif