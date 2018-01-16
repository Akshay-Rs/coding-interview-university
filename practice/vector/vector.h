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
	void insert(int, int);
	void prepend(int);
	int pop();
	void delete_at(int);
	void remove(int);
	int find(int);
 private:
	void resize();
};
