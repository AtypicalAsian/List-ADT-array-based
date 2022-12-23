//=================================================
// Nicolas Nguyen
// List.cpp 
// This file contains the class implementation for the List ADT
//=================================================
#include <iomanip>
#include <math.h>
#include <sstream>
//#include "List.h"


//======================================================
// Default Constructor 
// - Creates an empty List
// PARAMETERS: none
// RETURN: none but performs these operations:
//	1) sets capacity to the default size, 
//	2) sets size to 0 
//	3) initialize an array with the default size, capacity
// 	   and have the pointer point to the first spot 
//======================================================
template <class T>
	List<T>::List	(void)
{
	capacity = DEFAULT_LIST_CAPACITY;
	list = new T[DEFAULT_LIST_CAPACITY];
	size = 0; 
}


//======================================================
// Destructor
// PARAMETERS: none
// RETURN: none but returns the array to the free store
//======================================================
template <class T>
	List<T>::~List		( void )
{
	delete [] list; 
}


//=================================================
// to_string
// PARAMETERS: none
// RETURN VALUE:
// values in the list separated by a space in between 
//=================================================

template <class T>
string	List<T>::to_string ( void ) const
{
	stringstream stream;
	for (int i=0; i<size; i++) 
		stream << *(list+i) << " ";
	stream << " size: " << size << " cap: " << capacity; 
	return stream.str(); 
} 


//======================================================
// append
// - appends a new item to the end of the list 
// PARAMETERS: const reference to item of type T 
// RETURN: none but adds new item to the last spot in
//	   list and increment size by 1
//======================================================
template <class T>
void	List<T>::append		( const T &item)
{
	if (size==capacity)
	{
		reallocate(); 
	}
	*(list+size) = item; 
	size++; 
}

//======================================================
// Copy Constructor 
// - performs deep copy 
// PARAMETERS: const reference to mylist 
// RETURN: none but copies the size, capacity and values
//	   of the parameter to the caller of the function 
//======================================================
template <class T>
	List<T>::List	( const List<T> &mylist )
{
	capacity = mylist.capacity; 
	size = mylist.size; 
	list = new T[mylist.capacity]; 
	for (int i=0; i<mylist.size; i++)
		*(list+i) = *(mylist.list+i);

}


//======================================================
// operator=
// list1 = list2
// PARAMETERS: const reference to mylist 
// RETURN: capacity, size and every value in mylist is 
//	   assigned to *this. Then *this is returned
//======================================================
template <class T>
List<T> List<T>::operator=	( const List<T> &mylist )
{
	delete [] list; 
	capacity = mylist.capacity; 
	size = mylist.size; 
	list = new T[mylist.capacity]; 
	for (int i=0; i<mylist.size; i++) 
		*(list+i) = *(mylist.list+i); 
	return *this; 
}


//======================================================
// isEmpty
// PARAMETERS: none
// RETURN: true of the list is empty, false otherwise 
//======================================================
template <class T>
bool	List<T>::isEmpty		( void ) const
{
	return (size==0);
}


//======================================================
// length
// PARAMETERS: none
// RETURN: size of the list as an integer
//======================================================
template <class T>
int	List<T>::length		( void ) const
{
	return size; 

}


//======================================================
// clear
// PARAMETERS: none
// RETURN: none but deletes the existing list and 
// 	   creates a new one with the same capacity and
//	   size set to 0 
//======================================================
template <class T>
void	List<T>::clear		( void )
{
	size=0; 
	delete [] list; 
	list = new T[capacity];
		
}

//======================================================
// operator+
// list1 = list2 + list3
// PARAMETERS: const reference to mylist 
// RETURN: a list object whose size and capacity is the
//		   sum of its addends. The new list contains values
//		   from the first addend followed by the second
//======================================================
template <class T>
List<T> List<T>::operator+	( const List<T> &mylist ) const
{
	List<T> result; 
	result.capacity = capacity + mylist.capacity; 
	result.size = 0; 
	result.list = new T [result.capacity]; 
	for (int i=0; i<size; i++) 
	{
		//cout<< *(list+i) << ","; 
		result.append(*(list+i));
	} 
	for (int j=0; j<mylist.size; j++)
	{
		//cout<< *(mylist.list+j) << ","; 
		result.append(*(mylist.list + j));
	}
	return result; 
	
}


//======================================================
// insert
// PARAMETERS: const reference to item & int index 
// RETURN: none, but inserts item into the correct position
//		   and shifts the items that comes after (int index)
//		   one unit to the right 
//======================================================
template <class T>
void	List<T>::insert		( const T &item, int index )
{
	if (index <0 || index>size) throw std::invalid_argument( "Invalid index" );
	size++; 
	if (size==capacity) reallocate(); 
	for (int i=size-1; i>index; i--) 
		*(list+i) = *(list+i-1);
	*(list+index) = item; 
	
}


//======================================================
// remove
// PARAMETERS: const reference to index 
// RETURN: none, but removes the item at specified index
//		   then shift the items after index position 
//		   one unit to the left 
//======================================================
template <class T>
void	List<T>::remove		( int index )
{
	if (index <0 || index>size-1) throw std::invalid_argument( "Invalid index" );
	size--; 
	for(int i=index; i<size; i++) 
		*(list+i) = *(list+i+1);
	 
}

//======================================================
// operator[]
// PARAMETERS: const reference to index 
// RETURN: none, but returns value at specified index
// Raises error if the index is invalid (out of bounds)
//======================================================
template <class T>
T &	List<T>::operator[]	( int index )
{
	if (index <0 || index>size-1) throw std::invalid_argument( "Invalid index" ); 
	return*(list+index); 

} 

