#ifndef ARRAY2D_H
#define ARRAY2D_H
#include <iostream>

template<typename T>
class Array2D
{
private:
	T** m_array;
	int m_rows;
	int m_columns;
public:
	Array2D() : m_array(nullptr), m_rows(0), m_columns(0) {} // default ctor
	Array2D(const int rows, const int columns); // two param constructor
	Array2D(const Array2D& copy); // copy constructor
	Array2D& operator =(const Array2D& rhs); // copy assignment
	~Array2D(); // destructor

	int getRow() const; // getter function for rows
	int getColumns() const; // getter function for columns

	//void setColumns(int columns); // setter function for columns
	//void setRows(int rows); // setter function for rows
	//T& Select(const int desired_row, const int desired_column) const; // select for row and column

   //Row operator[](int index) { return Row(m_array[index]); }

	template<typename T>
	class Row {
	public:
		Row(T* arr) : arr(arr) {}
		T & operator[](int index) { return arr[index]; }
	private:
		T* arr = nullptr;
	};
	Row<T> & operator[](int index){ 
		Row<T> object(m_array[index]);
		return object;
	}
};



template<typename T>
inline Array2D<T>::Array2D(const int rows, const int columns)
{
	m_rows = rows;
	m_columns = columns;
	
	m_array = new T * [m_rows];
	for (int i = 0; i < m_rows; ++i) {
		m_array[i] = new T[m_columns];
	}
}

template<typename T>
inline Array2D<T>::Array2D(const Array2D& copy)
{
	m_rows = copy.m_rows;
	m_columns = copy.m_columns;

	m_array = new T * [m_rows];
	for (int i = 0; i < m_rows; ++i) {
		m_array[i] = new T[m_columns];
	}
	// initializes the object with the copied objects rows and columns
	
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_columns; j++)
		{
			m_array[i][j] = copy.m_array[i][j];
		}
	}
	// copies the values assigned to each of the 2D array elements

}

template <typename T>
Array2D<T>& Array2D<T>::operator = (const Array2D<T>& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < m_rows; ++i) {
			delete[] m_array[i];
		}
		delete[] m_array;
		m_array = nullptr;
		// delete the entire 2D array

		m_rows = rhs.m_rows;
		m_columns = rhs.m_columns;

		m_array = new T * [m_rows];
		for (int i = 0; i < m_rows; ++i) {
			m_array[i] = new T[m_columns];
		}
		// initializes the object with the copied objects rows and columns

		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_columns; j++)
			{
				m_array[i][j] = rhs.m_array[i][j];
			}
		}
		// copies the values assigned to each of the 2D array elements
	}
	return *this;
}

template<typename T>
inline Array2D<T>::~Array2D()
{
	for (int i = 0; i < m_rows; ++i) {
		delete[] m_array[i];
	}
	delete[] m_array;
	m_array = nullptr;
}

template<typename T>
inline int Array2D<T>::getRow() const
{
	return m_rows;
}

template<typename T>
inline int Array2D<T>::getColumns() const
{
	return m_columns;
}



#endif