// A1_P1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "List.cpp"
using namespace std;
void menue()
{

    cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\tList Created Successfuly" << endl;
    cout << "-------------------------------------------------------------------------------" << endl << endl;
    cout << "Enter Number Of Your Choice." << endl;
    cout << "1) Insert Front." << endl;
    cout << "2) Insert Back." << endl;
    cout << "3) Insert In Certain Position." << endl;
    cout << "4) Delete Front." << endl;
    cout << "5) Delete Back." << endl;
    cout << "6) Delete In Certain Position." << endl;
    cout << "7) Get Front." << endl;
    cout << "8) Get Back." << endl;
    cout << "9) Get Value In Certain Position." << endl;
    cout << "10) Update Front." << endl;
    cout << "11) Update Back." << endl;
    cout << "12) Update Value In Certain Position." << endl;
    cout << "13) Clear All List." << endl;
    cout << "14) Print All List." << endl;
    cout << "15) Print All List Revarse." << endl;
    cout << "0) Exit." << endl;
    cout << "-------------------------------------------------------------------------------" << endl << endl;
}
void listOperation(List<int>list)
{
    string input;
    int position;
    int value;
    List<int>::Iterator it;
    cout << "Enter The Number Of Operation:__";
    cin >> input;
    if (input == "1")
    {
        cout << "Enter The Value:__";
        cin >> value;
        list.InsertBegin(value);
    }
    else if (input == "2")
    {
        cout << "Enter The Value:__";
        cin >> value;
        list.InsertEnd(value);
    }
    else if (input == "3")
    {
        cout << "Enter Position:__";
        cin >> position;
        while (position < 1)
        {
            cout << "Invalid Choice, Please Enter Again:__";
            cin >> position;
        }
        cout << "Enter The Value:__";
        cin >> value; 
        it = list.Begin();
        for (int counter = 1; counter < position; counter++)
        {
            it++;
        }
        list.Insert(value, it);
    }
    else if (input == "4")
    {
        list.EraseBegin();
    }
    else if (input == "5")
    {
        list.EraseEnd();
    }
    else if (input == "6")
    {
        cout << "Enter Position:__";
        cin >> position;
        while (position < 1)
        {
            cout << "Invalid Choice, Please Enter Again:__";
            cin >> position;
        }
        cout << "Enter The Value:__";
        cin >> value;
        it = list.Begin();
        for (int counter = 1; counter < position; counter++)
        {
            it++;
        }
        list.Erase(it);
    }
    else if (input == "7")
    {
        it = list.Begin();
        cout << *it << endl;
    }
    else if (input == "8")
    {
        it = list.End();
        cout << *it << endl;
    }
    else if (input == "9")
    {
        cout << "Enter Position:__";
        cin >> position;
        while (position < 1)
        {
            cout << "Invalid Choice, Please Enter Again:__";
            cin >> position;
        }
        cout << "Enter The Value:__";
        cin >> value;
        it = list.Begin();
        for (int counter = 1; counter < position; counter++)
        {
            it++;
        }
        cout << *it << endl;
    }
    else if (input == "10")
    {
        cout << "Enter The Value:__";
        cin >> value;
        it = list.Begin();
        *it = value;
    }
    else if (input == "11")
    {
        cout << "Enter The Value:__";
        cin >> value;
        it = list.End();
        *it = value;
    }
    else if (input == "12")
    {
        cout << "Enter The Value:__";
        cin >> value;
        cout << "Enter Position:__";
        cin >> position;
        while (position < 1)
        {
            cout << "Invalid Choice, Please Enter Again:__";
            cin >> position;
        }
        cout << "Enter The Value:__";
        cin >> value;
        it = list.Begin();
        for (int counter = 1; counter < position; counter++)
        {
            it++;
        }
        *it = value;
    }
    else if (input == "13")
    {
        list.Clear();
    }
    else if (input == "14")
    {
        list.Print();
    }
    else if (input == "15")
    {
        list.PrintReverse();
    }
    else if (input == "0")
    {
    return;
    }
    else
    {
        cout << "Invalid input, Enter Again:__";
        listOperation(list);
    }
    list.Print();
    listOperation(list);
}
int main()
{
    string Input;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\tDoubly Linked List" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    int size = 0, initialValue = 0;
    cout << "Enter Size:__";
    cin >> size;
    while (size < 0)
    {
        cout << "Invalid Value, Please Enter Again:__";
        cin >> size;
    }
    if (size != 0)
    {
        cout << "Enter Enitial Value:__";
        cin >> initialValue;
    }
    List<int>list(initialValue, size);
    menue();
    listOperation(list);
    cout << "-------------------------------------------------------------------------------" << endl;
    return 0;
}
/*
    cout << "Enter Number Of Your Choice." << endl;
    cout << "1) Integer." << endl;
    cout << "2) Float." << endl;
    cout << "3) Double." << endl;
    cout << "4) Char." << endl;
    cout << "5) String." << endl;
    cout << "Your Choice Is:__";
    cin >> Input;
if (Input == "1")
        {
            int size = 0, initialValue = 0;
            cout << "Enter Size:__";
            cin >> size;
            if (size != 0)
            {
                cout << "Enter Enitial Value:__";
                cin >> initialValue;
            }
            List<int>list(initialValue,size);
            menue();
            listOperation(list);
        }
        else if (Input == "2")
        {
            int size = 0;
            float initialValue = 0.0;
            cout << "Enter Size:__";
            cin >> size;
            if (size != 0)
            {
                cout << "Enter Enitial Value:__";
                cin >> initialValue;
            }
            List<float>list(initialValue, size);
            menue();
            listOperation(list);
        }
        else if (Input == "3")
        {
            int size = 0;
            double initialValue = 0.0;
            cout << "Enter Size:__";
            cin >> size;
            if (size != 0)
            {
                cout << "Enter Enitial Value:__";
                cin >> initialValue;
            }
            List<double>list(initialValue, size);
            menue();
            listOperation(list);
        }
        else if (Input == "4")
        {
            int size = 0;
            char initialValue = ' ';
            cout << "Enter Size:__";
            cin >> size;
            if (size != 0)
            {
                cout << "Enter Enitial Value:__";
                cin >> initialValue;
            }
            List<char>list(initialValue, size);
            menue();
            listOperation(list);
        }
        else if (Input == "5")
        {
            int size = 0;
            string initialValue = " ";
            cout << "Enter Size:__";
            cin >> size;
            if (size != 0)
            {
                cout << "Enter Enitial Value:__";
                cin >> initialValue;
            }
            List<string>list(initialValue, size);
            menue();
            listOperation(list);
        }
        else
        {
            cout << "Invalid input, Enter Again:__";
            cin >> Input;
        }
*/