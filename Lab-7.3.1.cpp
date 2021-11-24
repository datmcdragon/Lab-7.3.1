#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Input(int** a, const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
		cout << endl;
	}
}

void Print(int** a, const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

int Zero(int** a, const int k, const int j)
{
	int s = 0;
	for (int i = 0; i < k; i++)
	{
		if (a[i][j] == 0)
			s++;
	}
	return s;
}

int Calck(int** a, const int k, const int n)
{
	int s = 0;
	for (int j = 0; j < n; j++)
	{
		if (Zero(a, k, j) > 0)
			s++;
	}
	return n - s;
}

int Chart(int** a, const int n, const int i)
{
	int sum = 0;
	for (int j = 0; j < n; j++)
	{
		if (a[i][j] > 0 && a[i][j] % 2 == 0)
			sum += a[i][j];
	}
	return sum;
}

void Change(int** a, const int row1, const int row2, const int colCount)
{
	int tmp;
	for (int j = 0; j < colCount; j++)
	{
		tmp = a[row1][j];
		a[row1][j] = a[row2][j];
		a[row2][j] = tmp;
	}
}

void Replace(int** a, const int k, const int n, const int j)
{
	for (int i1 = 0; i1 < k; i1++)
		for (int i2 = 0; i2 < k; i2++)
			if ((Chart(a, n, i1)) < (Chart(a, n, i2)))
				Change(a, i1, i2, n);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned)time(NULL));

	int Low = -20;
	int High = 20;
	int k, n;

	cout << "rowCount = "; cin >> k;
	cout << "colCount = "; cin >> n;

	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];

	Create(a, k, n, Low, High);
	Input(a, k, n);

	cout << "a[" << k << "][" << n << "] = " << endl;

	Print(a, k, n);

	cout << "Number of matrices without zeros: " << Calck(a, k, n) << endl;

	Replace(a, k, n, n);

	cout << "Matrix arranged according to the growth of characteristics: " << endl;
	cout << "a[" << k << "][" << n << "] = " << endl;

	Print(a, k, n);

	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
