#include <iostream>
#include <string>
#include <stdio.h>
#include "List.h"
using namespace std;

//////////////////////////////////Start Iterator//////////////////////////////////////
template<typename type>
List<type>::Iterator::Iterator()
{
	PointerToNode = NULL;
}

template<typename type>
List<type>::Iterator::Iterator(Node* pointer)
{
	PointerToNode = pointer;
}

template<typename type>
type& List<type>::Iterator::operator*()
{
	return PointerToNode->Value;
}

template<typename type>
bool List<type>::Iterator::operator==(const Iterator& it)
{
	return  this->PointerToNode == it.PointerToNode;
}
//////////////////////////////////End Iterator//////////////////////////////////////

//////////////////////////////////Start List///////////////////////////////////////
template<typename type>
List<type>::List()
{
	Node* NewNode = new Node;
	NewNode->Left = NewNode->Right = NULL;
	First = Last = EndNode = NewNode;
	Length = 0;
}

template<typename type>
List<type>::List(type value, int size)
{
	Node* NewNode = new Node;
	NewNode->Left = NewNode->Right = NULL;
	First = Last = EndNode = NewNode;
	Length = 0;
	for (int counter = 0; counter < size; counter++)
	{
		Node* NewNode = new Node;
		NewNode->Left = NULL;
		NewNode->Value = value;
		NewNode->Right = First;
		First->Left = NewNode;
		if (Last == EndNode)
		{
			Last = NewNode;
		}
		First = NewNode;
		Length++;
	}
}

template<typename type>
void List<type>::Print()
{
	try
	{
		if (First == Last)
		{
			string error = "Warning: List Is Empty.";
			throw error;
		}
		else
		{
			Node* temp = First;
			cout << "[ ";
			while (temp != EndNode)
			{
				cout << temp->Value << " ";
				temp = temp->Right;
			}
			cout << "]" << endl;
		}
	}
	catch (string error)
	{
		cout << error << endl;
	}
}

template<typename type>
void List<type>::PrintReverse()
{
	try
	{
		if (First == Last)
		{
			string error = "Warning: List Is Empty.";
			throw error;
		}
		else
		{
			Node* temp = Last;
			cout << "[ ";
			while (temp != NULL)
			{
				cout << temp->Value << " ";
				temp = temp->Left;
			}
			cout << "]" << endl;
		}
	}
	catch (string error)
	{
		cout << error << endl;
	}
}

template<typename type>
int List<type>::Size()
{
	return Length;
}

template<typename type>
bool List<type>::IsEmpty()
{
	return Length == 0;
}
//////////////////////////////////End List/////////////////////////////////////////
