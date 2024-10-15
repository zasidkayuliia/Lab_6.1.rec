#include <iostream>
#include <iomanip> 
#include <time.h>

using namespace std;

void Create(int* c, const int size, const int Low, const int High, int i) // Формування масиву
{
    c[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(c, size, Low, High, i + 1);
}

void Print(int* c, const int size, int i) // Виведення масиву
{
    cout << setw(4) << c[i]; 
    if (i < size - 1) {
        Print(c, size, i + 1);
    }
    else {
        cout << endl;
    }
}

int Count(const int* c, const int size, int i, int N) // Кількість елементів, які задовольняють критерій
{
    if (c[i] % 2 != 0 && i % 13 != 0)
        N++;
    if (i < size - 1)
        return Count(c, size, i + 1, N);
    else
        return N;
}

int Sum(int* c, const int size, int i, int S) // Сума елементів, які задовольняють критерій
{
    if (c[i] % 2 != 0 && i % 13 != 0)
        S += c[i];
    if (i < size - 1)
        return Sum(c, size, i + 1, S);
    else
        return S;
}

void updateArray(int* c, const int size, int i) // Заміна елементів, які задовольняють критерій на 0
{
    if (i == size) return;
    if (c[i] % 2 != 0 && i % 13 != 0) {
        c[i] = 0;
    }
    updateArray(c, size, i + 1);
}

int main()
{
    srand((unsigned)time(NULL)); // Ініціалізація генератора випадкових чисел
    const int n = 21;
    int c[n];
    int Low = 15;
    int High = 85;

    Create(c, n, Low, High, 0);
    Print(c, n, 0);

    cout << "S = " << Sum(c, n, 0, 0) << endl; 
    cout << "N = " << Count(c, n, 0, 0) << endl; 

    updateArray(c, n, 0); 
    Print(c, n, 0);

    return 0;
}
