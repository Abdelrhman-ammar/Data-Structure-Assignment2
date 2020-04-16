#include <iostream>
 
using namespace std;
template <class t>
class stack {
private:
	 
	t *my_stack;
	int capacity;
	int current_size;
public:
	stack()
	{
		capacity = 5;
		current_size = 0;
		my_stack = new t[capacity];
	}
	stack(t value, int intial_size)
	{
		capacity = 3;
		if (intial_size > 0)
		{
			capacity = intial_size;
			current_size = intial_size;
			my_stack = new t[capacity];
			for (int i = 0; i < intial_size; i++)
			{
				my_stack[i] = value;

			}
		}
		else
		{
			my_stack = new t[capacity];
			cout << "you enterd a wrong value" << endl << "your stack size is " << capacity << " and have no elements" << endl;
		}
		
		

	}
	~stack()
	{
		 
		delete my_stack;
	}
	void resize()
	{
		t* my_new_stack;
		my_new_stack = new t[capacity + 50];
		for (int i = 0; i < current_size; i++)
		{
			my_new_stack[i] = my_stack[i];
		}
		my_stack = my_new_stack;
		capacity += 50;
	}
	void push(t element)
	{
		if (current_size == capacity - 1)
		{
			resize();
		}
		
		my_stack[current_size] = element;
		current_size++;
	}
	bool isEmpty()
	{
		return current_size == 0;
	}
	t & top()
	{
		if (isEmpty())
		{
			cout << "empty" << endl;
		}
		else
		{
			return my_stack[current_size - 1];
		}
	}
	void pop()
	{
		if (isEmpty())
		{
			cout << "the stack is empty" << endl;
		}
		else
		{
			current_size--;
		}
	}
	void print()
	{
		if (isEmpty())
		{
			cout << "stack is empty" << endl;
		}
		else
		{
			for (int i = 0; i < current_size; i++)
			{
				cout << my_stack[i] << endl;
			}
		}
		
	}
	int size() {
		return current_size;
	}
		
};
 
int main()
{
	stack<string> s("fouad",0);
	s.print();

	system("pause");
	return 0;
}