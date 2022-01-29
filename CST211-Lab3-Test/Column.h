#ifndef COLUMN_H
#define COLUMN_H

#include "Exception.h"	

template <typename T>
class Array2D;

template<typename T>
class Column {
private:
	T* arr = nullptr;
	friend class Array2D<T>;
public:
	Column(T* arr) : arr(arr) {}
	T& operator[](int index ) {
		if (index < 0 || index > CURRENT_COLUMN)
			throw(Exception("Column out of bounds! Please try again!"));
		return arr[index];
	};
};
#endif
