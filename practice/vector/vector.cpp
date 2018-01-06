#include <iostream>
#include <stdexcept>
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
		cout<<e.what()<<endl;
	}
}
	
void vector::push(int number)
{
	if(size == capacity)
	{
		int* temp = arr;
		arr = new int[capacity*2];
		for(int i=0;i<capacity;i++)
		{
			arr[i] = temp[i];
		}
		delete temp;
		capacity *= 2;
	}
	arr[size] = number;
	size++;
}		

	
