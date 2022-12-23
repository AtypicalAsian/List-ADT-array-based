//========================================================
// Nicolas Nguyen
// List.h
// This file contains the List class declaration.  
//========================================================

#include <iostream>
#include <string>
using namespace std;

#ifndef LIST_H
#define LIST_H

#define DEFAULT_LIST_CAPACITY 10

template <class T> 
class List
{
public:
			List		( void );
			List		( const List<T> &mylist );
		   ~List		( void );
List<T>		operator=	( const List<T> &mylist );
string		to_string	( void ) const;	
void		append		( const T &item	);
T &			operator[]	( int index );
void		insert		( const T &item, int index );
void		remove		( int index );
List<T>		operator+	( const List<T> &mylist ) const;
int			length		( void ) const;
bool		isEmpty		( void ) const;
void		clear		( void );

friend ostream & operator<< ( ostream &os, List<T> &mylist )
{
	for ( int i = 0; i < mylist.size; i++ )
		os << mylist.list[i] << " ";
	return os;	
}

private:
	T	*list;			// the pointer for the dynamic array
	int capacity;		// the size of the array
	int size;			// the number of items in the list

	void	reallocate	( void )
	{
		capacity = capacity*2; 
		T *newlist = new T[capacity]; 
		for (int i=0; i<size; i++)
			*(newlist+i) = *(list+i);
		delete [] list;
		list = newlist;
	}
};


#include "List.cpp"

#endif


