#include<iostream>
using namespace std;

void checkP(long* pa, long py);
int main()
{
	long n, size, nSize, temp;
	long* arr;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> size;
		nSize = size;
		arr = new long[size + 1];

		for (int j = 0; j < size; j++) {
			cin >> arr[j];
			if (arr[j] > arr[(j - 1) / 2]) checkP(arr, j);
		}

		while (nSize > 1)
		{
			for (int y =0; y < nSize; y++) {
				if (arr[y] > arr[(y - 1) / 2]) checkP(arr, y);
			}
			for (int y = 0; y < nSize; y++)
			{
				cout << arr[y] << " ";
			}
			cout << "\n";
			temp = arr[0];
			arr[0] = arr[nSize - 1];
			arr[nSize - 1] = temp;
			nSize--;
		}
		for (int y = 0; y < size; y++)
		{
			cout << arr[y] << " ";
		}

		cout << "\n";
		delete[] arr;
	}
	return 0;
	}
	


void checkP(long* pa, long py)
{
	long temp;
	temp = pa[py];
	pa[py] = pa[(py - 1) / 2];
	pa[(py - 1) / 2] = temp;
	temp = (py - 1) / 2;
	if (pa[temp] > pa[(temp - 1) / 2]) checkP(pa, temp);
}