#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "vector.h"
using namespace std;

vector::vector()
{
	arr = new int[1];
	size = 0;
	capacity = 1;
}


int vector::current_size()
{
	return size;
}
	
int vector::current_capacity()
{
	return capacity;
}

bool vector::is_empty()
{
	return (size == 0);
}

int vector::at(int index)
{
	try
	{
		if(size == 0) 
		{
			throw std::range_error("Empty vector!");
		}
		if(index > capacity)
		{
			throw std::range_error("Index too high!");
		} 
		return arr[index];
	}
	catch(exception& e)
	{
		cout<<e.what()<<" Exiting!!"<<endl;
		exit(EXIT_FAILURE);
	}
}
	
void vector::push(int number)
{
	if(size == capacity)
	{
		resize();
	}
	arr[size] = number;
	size++;
}		

void vector::resize()
{
	if(size==capacity)
	{
		int* temp = arr;
		arr = new int[capacity*2];
		for(int i=0;i<capacity;i++)
		{
			arr[i] = temp[i];
		}
		delete temp;
		temp = NULL;
		capacity *= 2;
	}
	else if(size==capacity/4 && capacity != 1)
	{
		int* temp = arr;
		arr = new int[capacity/2];
		for(int i=0;i<size;i++)
		{
			arr[i] = temp[i];
		}
		delete temp;
		temp = NULL;
		capacity /= 2;
	}
}

void vector::insert(int index, int number)
{
	resize();
	int last=arr[size-1];
	for(int i=size-2;i>=index;i--)
	{
		arr[i+1] = arr[i];
	}	
	arr[size] = last;
	arr[index] = number;
	size++;
}	

void vector::prepend(int number)
{
	insert(0,number);
}

int vector::pop()
{
	try
	{
		if(size == 0) 
		{
			throw std::range_error("Empty vector!");
		}
		resize();
		int last = arr[size-1];
		size--;
		return last;
	}
	catch(exception& e)
	{
		cout<<e.what()<<" Exiting!!"<<endl;
		exit(EXIT_FAILURE);
	}
}

void vector::delete_at(int index)
{
	resize();
	for(int i=index;i<size-1;i++)
	{
		arr[i] = arr[i+1];
	}	
	size--;
}
	
void vector::remove(int number)
{
	int occurrences=0;
	for(int i=0;i<current_size();i++)
	{
		if(arr[i] == number)
		{
			delete_at(i);
		}	
	}
}

int vector::find(int number)
{
	for(int i=0;i<size;i++)
	{
		if(arr[i] == number)
		{
			return i;
		}
	}
	
	return -1;	
}
