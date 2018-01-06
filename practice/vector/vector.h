class vector
{
 public:
	int* arr;
	int size;
	int capacity;

	vector();
	int current_size();
	int current_capacity();
	bool is_empty();
	int at(int);
	void push(int);
};
