#include <iostream>
#include <string>
using namespace std;
class students {
	string name;
	int id;
	float gpa;
public:
	students()
	{
		name = "no name";
		id = 0;
		gpa = 0;
	}
	students(string _name, int _id, float _gpa)
	{
		name = _name;
		id = _id;
		gpa = _gpa;
	}
	void display()
	{
		cout << "name: " << name << endl;
		cout << "id: " << id << endl;
		cout<<"gpa: "<< gpa << endl;
		cout << endl;
	}
	int get_id()
	{
		return id;
	}
};
class StudentList {
	
	struct node 
	{
		students item;
		node* next;
	};
	int length ;
	node* first, * last;
public:
	StudentList()
	{
		length = 0;
		first = last = NULL;
		
	}
	void searsh(int id)
	{ 
		bool founded = false;
		node* curr = first;
		while (curr->next != NULL)
		{
			if (curr->item.get_id() == id)
			{
				curr->item.display();
				founded = true;
				break;
			}
			curr = curr->next;
		}
		if (founded == false)
		{
			cout << "id not founded" << endl;
		}
	}
	void delete_(int id)
	{
		node* curr = new node;
		node* pre_curr = new node;
		bool founded = false;
		if (first->item.get_id() == id)
		{
			curr = first;
			first = first->next;
			delete curr;
			length--;
			founded = true;

		}
		else
		{
			curr = first;
			while (curr->next != NULL)
			{
				 
				if (curr->item.get_id() == id)
				{
					pre_curr->next = curr->next;
					delete curr;
					length--;
					founded = true;
					break;
				}
				pre_curr = curr;
				curr = curr->next;
			}
			if (last->item.get_id() == id)
			{
				founded = true;
				last = pre_curr;
				last->next = NULL;
				delete curr;
				length--;
			}
			 
		}
		if (founded == true)
		{
			cout << "deleted" << endl;
		}
		else
		{
			cout << "id not found" << endl;
		}

	}
	void Insertion(students s)
	{
		if (isempty())
		{
			first = new node;
			first->item = s;
			first->next = NULL;
			last = first;
			 
		}
		else if (length == 1)
		{
			 
			node* new_node = new node;
			new_node->item = s;
			if (first->item.get_id() <= s.get_id())
			{
				first->next = new_node;
				last = new_node;
				last->next = NULL;
			}
			else
			{
				new_node->next = first;
				first = new_node;
			}
		}
		else
		{
			 
			node* new_node = new node;
			new_node->item = s;
			if (first->item.get_id() > s.get_id())
			{
				new_node->next = first;
				first = new_node;
			}
			else if (last->item.get_id() < s.get_id())
			{
				last->next = new_node;
				last = new_node;
				last->next = NULL;
			}
			else
			{
				node* current = first;
				node* next_current = current->next;
				while (current->next != NULL)
				{

					
					if (current->item.get_id() <= s.get_id() && next_current->item.get_id() >= s.get_id())
					{
						current->next = new_node;
						new_node->next = next_current;
						break;
					}

					current = current->next;
					next_current = current->next;
				}

			}
			
		}
		length++;
    }
	void print()
	{
		node* current = new node;
		current = first;
		while (current != NULL)
		{
			current->item.display();
			current = current->next;
		}
	}
	bool isempty()
	{
		return (length == 0) ? true : false;
	}

};
 
int main()
{
	students s1("fouad",20180198, 2.75);
	students s2("mohamed",20180199,2.5);
	students s3("ammar", 20180164, 3.1);
	students s4("ahmed", 20180160, 3.1);

	StudentList ss; 
	ss.Insertion(s3);
	ss.Insertion(s4);
	ss.Insertion(s1);
	ss.Insertion(s2);
	
	ss.print();
	ss.delete_(20180160);
	ss.print();
	 

	 
	 
}
 