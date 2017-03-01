/**	NIM:		13515065
	Nama:		Felix Limanta
	Tanggal:	24 Februari 2017
	File:		insertion_sort.h
	Topik;		Divide and Conquer
	Deskripsi:	Definisi dan realisasi algoritma insertion sort
  */

#ifndef __INSERTION_SORT__
#define __INSERTION_SORT__

#include <cstdlib>

/**	@brief	Insertion Sort
	Sort array of data with insertion sort	
	@param	data	data to be sorted
	@param	size	size of data to be sorted	
  */
template <class T>
void insertion_sort (T data[], size_t size) {
	if (size > 1) {
		for (size_t i = 1; i < size; ++i) {
			// Divide: Store inserted data
			int temp = data[i];
			
			// Conquer: search for place to insert while shifting the rest
			int j;
			for (j = i - 1; j > 0 && temp < data[j]; --j)
				data[j+1] = data[j];
			
			// Combine: insert data
			if (temp >= data[j])	// Insert
				data[j+1] = temp;
			else {	// Insert as 1st elmt
				data[j+1] = data[j];
				data[j] = temp;
			}
		}
	}
}

#endif