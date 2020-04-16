
#include <iostream>
using namespace std;
template<class t>
class Queue {
	int rear, front, length, max_size = 20;
	t *arr;
public:
	Queue()
	{
		front = 0;
		rear = max_size - 1;
		length = 0;
		arr = new t[max_size];
	}
	Queue(t value, int size)
	{
		
		if (size > 0)
		{
			max_size = size;
		}
		front = 0;
		rear = max_size - 1;
		length = 0;
		arr = new t[max_size];
		for (int i = 0; i < size; i++)
		{
			push(value);
		}
	}
	~Queue()
	{
		delete arr;
	}
	int size()
	{
		return length;
	}
	bool isEmpty()
	{
		return length == 0;
	}
	void resize()
	{
		int i;
		max_size += 10;
		t* new_arr = new t[max_size];
		for ( i = 0; i !=rear;  i=(i + 1) % max_size)
		{
			new_arr[i] = arr[front + i];
		}
		new_arr[ i] = arr[rear];
		arr = new_arr;
		front = 0;
		rear = length - 1;

	}
	bool isFull()
	{
		return length == max_size;
	}
	 
	void push(t value)
	{
		if (isFull())
		{
			resize();
			cout << "the queue is full" << endl;
		}
		 
			 
			rear = (rear + 1) % max_size;
			arr[rear] = value;
			length++;
		

	}
	void  pop() 
	{
		if (isEmpty())
		{
			cout << "the queue is empty" << endl;
		}
		else
		{
			front = (front + 1) % max_size;
			length--;
		}

	}
	t& frontqueue()
	{
		return arr[front];
	}
	t &rearqueue()
	{
		return arr[rear];
	}
	void print()
	{
		for (int i = front; i != rear; i = (i + 1) % max_size)
		{
			cout << arr[i] << endl;
		}
		cout << arr[rear] << endl;
	}

};
int main()
{
	Queue<int> u1(0,1);
	u1.push(1);
	u1.push(2);
	u1.push(3);
	u1.push(4);
	u1.push(5);
	u1.push(6);
	u1.push(7);
	u1.push(8);
	u1.push(9);
	u1.push(10);
	u1.print();
	u1.pop();
	u1.pop();
	u1.print();
	u1.push(150);
	u1.print();
	 
	return 0;
}
 