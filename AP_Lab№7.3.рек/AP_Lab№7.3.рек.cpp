#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void CreateRow(int** a, const int n, const int Low, const int High, int rowNo, int colNo);
void CreateRows(int** a, const int n, const int Low, const int High, int rowNo);
void InputRow(int** a, const int n, int rowNo, int colNo);
void InputRows(int** a, const int n, int rowNo);
void PrintRow(int** a, const int n, int rowNo, int colNo);
void PrintRows(int** a, const int n, int rowNo);
bool CheckRowColEqual(int** a, const int n, int k, int i);
void Part1_FindK_Recursive(int** a, const int n, int k);
bool HasNegativeInRow(int** a, const int n, int rowNo, int colNo);
int SumRow(int** a, const int n, int rowNo, int colNo);
int Part2_SumNegativeRows_Recursive(int** a, const int n, int rowNo);

int main()
{
    srand((unsigned)time(NULL));
    int Low = -17;
    int High = 15;
    int n;
    cout << "n = "; cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    CreateRows(a, n, Low, High, 0);

    //InputRows(a, n, 0);

    PrintRows(a, n, 0);

    cout << "k values where row k equals column k:" << endl;
    Part1_FindK_Recursive(a, n, 0);
    cout << endl;

    int sum = Part2_SumNegativeRows_Recursive(a, n, 0);
    cout << "Sum of rows with negative elements: " << sum << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

void CreateRow(int** a, const int n, const int Low, const int High, int rowNo, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < n - 1)
        CreateRow(a, n, Low, High, rowNo, colNo + 1);
}

void CreateRows(int** a, const int n, const int Low, const int High, int rowNo)
{
    CreateRow(a, n, Low, High, rowNo, 0);
    if (rowNo < n - 1)
        CreateRows(a, n, Low, High, rowNo + 1);
}

void InputRow(int** a, const int n, int rowNo, int colNo)
{
    cout << "a[" << rowNo << "][" << colNo << "] = ";
    cin >> a[rowNo][colNo];
    if (colNo < n - 1)
        InputRow(a, n, rowNo, colNo + 1);
    else
        cout << endl;
}

void InputRows(int** a, const int n, int rowNo)
{
    InputRow(a, n, rowNo, 0);
    if (rowNo < n - 1)
        InputRows(a, n, rowNo + 1);
    else
        cout << endl;
}

void PrintRow(int** a, const int n, int rowNo, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < n - 1)
        PrintRow(a, n, rowNo, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int n, int rowNo)
{
    PrintRow(a, n, rowNo, 0);
    if (rowNo < n - 1)
        PrintRows(a, n, rowNo + 1);
    else
        cout << endl;
}

bool CheckRowColEqual(int** a, const int n, int k, int i)
{
    if (i == n)
        return true;
    if (a[k][i] != a[i][k])
        return false;
    return CheckRowColEqual(a, n, k, i + 1);
}

void Part1_FindK_Recursive(int** a, const int n, int k)
{
    if (k == n)
        return;

    if (CheckRowColEqual(a, n, k, 0))
        cout << k << " ";

    Part1_FindK_Recursive(a, n, k + 1);
}

bool HasNegativeInRow(int** a, const int n, int rowNo, int colNo)
{
    if (colNo == n)
        return false;
    if (a[rowNo][colNo] < 0)
        return true;
    return HasNegativeInRow(a, n, rowNo, colNo + 1);
}

int SumRow(int** a, const int n, int rowNo, int colNo)
{
    if (colNo == n)
        return 0;
    return a[rowNo][colNo] + SumRow(a, n, rowNo, colNo + 1);
}

int Part2_SumNegativeRows_Recursive(int** a, const int n, int rowNo)
{
    if (rowNo == n)
        return 0;

    int sum = Part2_SumNegativeRows_Recursive(a, n, rowNo + 1);
    if (HasNegativeInRow(a, n, rowNo, 0))
        sum += SumRow(a, n, rowNo, 0);

    return sum;
}
