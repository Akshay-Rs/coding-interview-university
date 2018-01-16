#include <iostream>
#include <cstdlib>
#include "vector.h"
using namespace std;
void print_array(vector v)
{
	for(int j=0;j<v.current_size();j++)
	{
		cout<<v.arr[j]<<" ";
	}
	cout<<endl;	
	cout<<"Current size is "<<v.current_size()<<endl;
	cout<<"Current capacity is "<<v.current_capacity()<<endl;
}
int main()
{
	vector vec;
	cout<<"Constructed object"<<endl;
	for(int i=0;i<10;i++)
	{
		vec.push(rand() % 10);
		print_array(vec);
	}
	for(int i=0;i<2;i++)
	{
		int last = vec.pop();
		cout<<"Popped "<<last<<endl;
		print_array(vec);
	}	
	for(int i=0;i<5;i++)
	{
		vec.delete_at(rand()%vec.current_size());
		print_array(vec);
	}	
	for(int i=0;i<10;i++)
	{
		vec.push(rand() % 10);
	}
	print_array(vec);
	vec.remove(2);
	print_array(vec);
	int index = vec.find(3);
	cout<<index<<endl;
	index = vec.find(1121);
	cout<<index<<endl;	
	return 0;
}
