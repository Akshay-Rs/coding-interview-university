#include <iostream>
#include <cstdlib>
#include "vector.h"
using namespace std;

int main()
{
	vector vec;
	cout<<"Constructed object"<<endl;
	cout<<vec.current_size()<<endl;
	cout<<vec.current_capacity()<<endl;
	cout<<vec.is_empty()<<endl;
	for(int i=0;i<10;i++)
	{
		vec.push(rand() % 10);
		for(int j=0;j<vec.current_size();j++)
		{
			cout<<vec.arr[j]<<" ";
		}	
		cout<<"Current size is "<<vec.current_size();
		cout<<"Current capacity is "<<vec.current_capacity()<<endl;
	}	
	return 0;
}
