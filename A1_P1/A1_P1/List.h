#pragma once
#include <iostream>
#include <string>
using namespace std;
template<typename type>
class List
{
private:
	struct Node
	{
		Node* Left;
		Node* Right;
		type Value;
	};
	Node* First;
	Node* Last;
	Node* EndNode;
	int Length;
public:
	class Iterator
	{
	private:
		Node* PointerToNode;
	public:
		Iterator();
		Iterator(Node* pointer);
		Iterator operator++()
		{
			try
			{
				if (PointerToNode == NULL)
				{
					string error = "Error: Iterator Is Undefined.";
					throw error;
				}
				else if (PointerToNode->Right == NULL)
				{
					string error = "Error: Out Of Range.";
					throw error;
				}
				else
				{
					PointerToNode = PointerToNode->Right;
				}
			}
			catch (string error)
			{
				cout << error << endl;
				exit(1);
			}
			return *this;
		}
		Iterator operator--()
		{
			try
			{
				if (PointerToNode == NULL)
				{
					string error = "Error: Iterator Is Undefined.";
					throw error;
				}
				else if (PointerToNode->Left == NULL)
				{
					string error = "Error: Out Of Range.";
					throw error;
				}
				else
				{
					PointerToNode = PointerToNode->Left;
				}
			}
			catch (string error)
			{
				cout << error << endl;
				exit(1);
			}
			return *this;
		}
		Iterator operator++(int)
		{
			Iterator temp = *this;
;			try
			{
				if (PointerToNode == NULL)
				{
					string error = "Error: Iterator Is Undefined.";
					throw error;
				}
				else if (PointerToNode->Right == NULL)
				{
					string error = "Error: Out Of Range.";
					throw error;
				}
				else
				{
					PointerToNode = PointerToNode->Right;
				}
			}
			catch (string error)
			{
				cout << error << endl;
				exit(1);
			}
			return temp;
		}
		Iterator operator--(int)
		{
			Iterator temp = *this;
			try
			{
				if (PointerToNode == NULL)
				{
					string error = "Error: Iterator Is Undefined.";
					throw error;
				}
				else if (PointerToNode->Left == NULL)
				{
					string error = "Error: Out Of Range.";
					throw error;
				}
				else
				{
					PointerToNode = PointerToNode->Left;
				}
			}
			catch (string error)
			{
				cout << error << endl;
				exit(1);
			}
			return temp;
		}
		type& operator*();
		bool operator==(const Iterator& it);
	};
	List();
	List(type Value, int size);
	void Print();
	void PrintReverse();
	int Size();
	bool IsEmpty();
	Iterator Insert(type value, Iterator position)
	{
		Node* CurNode = First;
		Node* NewNode = new Node;
		Iterator IndexIter(CurNode);
		NewNode->Value = value;
		if (position == IndexIter)
		{
			NewNode->Left = NULL;
			NewNode->Right = First;
			First->Left = NewNode;
			First = NewNode;
		}
		else
		{
			Node* PrevNode = First;
			while (!(position == IndexIter))
			{
				PrevNode = CurNode;
				CurNode = CurNode->Right;
				++IndexIter;
			}
			NewNode->Right = CurNode;
			NewNode->Left = PrevNode;
			PrevNode->Right = NewNode;
			CurNode->Left = NewNode;
		}
		Length++;
		Iterator it(NewNode);
		return it;
	}
	Iterator Erase(Iterator position)
	{
		try
		{	
			Node* temp = First;
			Length--;
			Iterator it(First);
			if (position == it)
			{
				First = First->Right;
				First->Left = NULL;
			}
			else
			{
				while (!(position == it))
				{
					temp = temp->Right;
					it++;
				}
				if (temp->Right == NULL)
				{
					string error = "Out Of Range.";
					throw error;
				}
				Node* Next = temp->Right;
				Node* Prev = temp->Left;
				Next->Left = Prev;
				Prev->Right = Next;
			}
			it++;
			delete temp;
			return it;
		}
		catch (string error)
		{
			cout << error << endl;
			exit(1);
		}
		return position;
	}

	List<type>& operator= (const List<type>& OriginalList)
	{
		Node* temp = OriginalList.First;
		while (temp != OriginalList.EndNode)
		{
			this->Insert(temp->Value, this->End());
			temp = temp->Right;
		}
		return *this;
	}
	Iterator EraseBegin()
	{
		return this->Erase(this->Begin());
	}
	Iterator EraseEnd()
	{
		return this->Erase(--this->End());
	}
	Iterator InsertBegin(type Value)
	{
		return this->Insert(Value, this->Begin());
	}
	Iterator InsertEnd(type Value)
	{
		return this->Insert(Value, this->End());
	}
	Iterator Begin()
	{
		Iterator it(First);
		return it;
	}
	Iterator End()
	{
		Iterator it(EndNode);
		return it;
	}
	void Clear();
	~List();
};
