// A1_P1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "List.cpp"
using namespace std;
void menue()
{
    cout << "Enter Number Of Your Choice." << endl;
    cout << "1)Create Empty Linked List." << endl;
    cout << "2)Create Linked List With Initical size." << endl;
}
int main()
{
    int size = 0, initialValue = 0;
    string Input;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\tDoubly Linked List" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "Enter Number Of Your Choice." << endl;
    cout << "1)Create Empty Linked List." << endl;
    cout << "2)Create Linked List With Initical size." << endl;
    cout << "Your Choice Is:__";
    cin >> Input;
    while (!(Input == "1" || Input == "0"))
    {
        cout << "Error Invalid Choice Blease Enter Again." << endl;
        cin >> Input;
    }
    if (Input == "1")
    {
        cout << "Enter Initial Size:__";
        cin >> size;
        while (size<=0)
        {
            cout << "Error Invalid Choice Blease Enter Again." << endl;
            cin >> size;
        }
    }
    cout << "Enter Type Od DaTa [int, float, double, string, char]." << endl;
    while (Input!="int"|| Input != "float" || Input != "double" || Input != "string" || Input != "char")
    {
        cout << "Error Invalid Choice Blease Enter Again." << endl;
        cin >> Input;
    }
    if (Input == "int")
    {
        int value;
        List<int>list(value, size);
    }
    menue();
    cout << "-------------------------------------------------------------------------------" << endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
