#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
	cout << "[ ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "]" << endl;
}

int partition(int arr[], int begin, int last)
{
	//pivot is the last element in array
	int pivot = arr[last];
	//the index of last element smaller than pivot "element in the correct position"
	int lastSmallIndex = begin - 1;
	for (int counter = begin; counter < last; counter++)
	{
		if (arr[counter] < pivot)
		{
			lastSmallIndex++;
			swap(arr[lastSmallIndex], arr[counter]);
		}
	}
	lastSmallIndex++;
	swap(arr[lastSmallIndex], arr[last]);
	return lastSmallIndex;
}

void quickSort(int arr[], int begin, int last)
{
	if (begin < last)
	{
		int piv = partition(arr, begin, last);
		quickSort(arr, begin, piv - 1);
		quickSort(arr, piv + 1, last);
	}
}

void Swab(int& num1, int& num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void spicialSort(int defSortArray[], int sizeDefArr, int spicialArray[], int sizespicArr)
{	
	quickSort(defSortArray, 0, sizeDefArr - 1);
	int sorted = 0;
	for (int counterSpic = 0; counterSpic < sizespicArr; counterSpic++)
	{
		for (int counter = sorted;counter < sizeDefArr; counter++)
		{
			if (defSortArray[counter] == spicialArray[counterSpic])
			{
				if (counter != sorted)
				{
					swap(defSortArray[counter], defSortArray[sorted]);
				}
				sorted++;
			}
		}
	}
}


int main()
{
	int original[] = { 2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8 };
	int special[] = { 8, 1, 7, 3 };
	int sizeOriginal = 11, sizeSpicial = 4;
	spicialSort(original, sizeOriginal,special,sizeSpicial);
	printArray(original, sizeOriginal);
	return 0;
}