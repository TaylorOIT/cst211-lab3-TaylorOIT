# CST211-Lab3-Test
Oregon Institute of Technology
CST 211 Data Structures
Lab 3: 2D-Array 2


Lab 3
2D-Array Implementation 2
Description
Write a 2D-Array based on the UML below. Notice the T **.

UML

typename: T

Row (consider friending Array2D)

private:

* m_array2D: Array2D &
* m_row: int

public:

* Row (inout array2D:Array 2D &, in row:int)
* <<const>> operator [](in column:int): T &

typename: T

Array2D

private:
* m_array: T **
* m_rows: int
* m_columns: int

public:
* Array2D()
* Array2D(in rows:int, in columns:int)
* Array2D(in copy:const Array2D &)
* operator =(in rhs:const Array2D & ): Array2D &
* <<const>> getRows(): int
* <<const>> getColumns(): int
* setRows (in rows:int): void
* setColumns (in columns:int): void
* operator [](in row:int): Row
* <<const>> Select(in desired_row:int, in desired_column:int): T &


  Stipulations
1. Make sure the user never goes out of bounds. If they do, throw an exception.
2. Use your Exception class to throw if they do go out of bounds.
3. Modify the class so that the subscript operators can be called from const objects. Hint: You can only call const methods from const objects.
4. Don’t forget that because there is now dynamic memory allocation, you will need the move constructor and move operator =.


Deliverables
One file including:
* Your code
* Your test(s) similar to Lab1_test.cpp & Lab2_test.cpp and their results
