#include <iostream>
#include <stack>
using namespace std;

bool check_close(char frist, char second)
{
	if (frist == '(' && second == ')')
	{
		return true;
	}
	else if (frist == '{' && second == '}')
	{
		return true;
	}
	else if (frist == '[' && second == ']')
	{
		return true;
	}
	return false;
}
bool are_balanced(string word)
{
	stack<char>my_stack;
	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] == '{' || word[i] == '(' || word[i] == '[')
		{
			my_stack.push(word[i]);
		}
		else if (word[i] == '}' || word[i] == ')' || word[i] == ']')
		{
			if (my_stack.empty() || !check_close(my_stack.top(), word[i]))
			{
				cout << "false" << endl;
				return false;
			}
			else
				my_stack.pop();

		}
	}
	if (my_stack.empty()) 
	{
		cout << "true" << endl;
		return true;
	}
	else
	{
		cout << "false" << endl;
		return false;
	}

}
int main()
{
	are_balanced("{()}[][{()()}()]");
	are_balanced("{(])");
} 