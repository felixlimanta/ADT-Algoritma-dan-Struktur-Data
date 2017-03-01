/**	NIM:		13515065
	Nama:		Felix Limanta
	Tanggal:	24 Februari 2017
	File:		selection_sort.h
	Topik;		Divide and Conquer
	Deskripsi:	Definisi dan realisasi algoritma selection sort
  */

#ifndef __SELECTION_SORT__
#define __SELECTION_SORT__

#include <cstdlib>

/**	@brief	Find index of minimum value
	Uses divide and conquer mixed with regular traversal to find minimum value index
	@param	data	data to be searched
	@param	low		lower bound index of data to be searched
	@param	high	higher bound index of data to be searched
	@param	delta	minimum size of division before resorting to traversal
	From experiment, best value of delta is found to be around 5000
	@return	Index of minimum value in array
  */
template <class T>
size_t findmin (T data[], size_t low, size_t high, size_t delta) {
	if (high - low <= delta) {	// Basis, traverse to find minimum
		size_t min = low;
		for (size_t i = low + 1; i <= high; ++i)
			if (data[i] < data[min])
				min = i;
		return min;	
	} else {	// Recurrence
		// Divide
		size_t mid = (low + high) / 2;
		
		// Conquer
		size_t min1 = findmin(data,low,mid,delta);
		size_t min2 = findmin(data,mid+1,high,delta);
		
		// Combine
		return (data[min1] <= data[min2]) ? min1 : min2;
	}
}

/**	@brief	Selection Sort
	Sort array of data with selection sort	
	@param	data	data to be sorted
	@param	size	size of data to be sorted	
  */
template <class T>
void selection_sort (T data[], size_t size) {
	if (size > 1) {
		// Divide: isolate element by element
		for (size_t i = 0; i < size - 1; ++i) {
			// Conquer
			// Find min value			
			size_t i_min = findmin(data,i,size-1,5000);
			
			// Switch values to sort
			int temp = data[i];
			data[i] = data[i_min];
			data[i_min] = temp;
		}
		// Combine: do nothing
	}
}

#endif