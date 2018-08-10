#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    unsigned long int n;
    cout << "Числа Фибоначи\n";
    cout << "Введите размер массива: ";
    //считывание размера массива
    cin >> n;
    //контроируемый код
    try
    {
        vector<int> fibs(n,1);
        cout << fibs[0] << " " << fibs[1];
        for(unsigned long int k = 2; k < n; k++)
        {
            fibs[k] = fibs[k-1] + fibs[k-2];
            cout << " " << fibs[k];
        }
    }
    catch (...)
    {
        cout << "Произошла ошибка!";
    }
    cout << "\nПрограмма завершила выполнение!\n";
}
