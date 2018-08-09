#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

mutex m;
//функция создания протоколов
void mythread(string name, int time, int steps)
{
    for(int k = 1; k <= steps; k++)
    {
        this_thread::sleep_for(chrono::seconds(time));
        m.lock();
        cout << "поток " << name << ":\tсщщбщение " << k << endl;
        m.unlock();
    }
}
//главная функция программы
int main()
{
    int n=5;
    cout << "Запускаются потоки...\n";
    thread A(mythread,"Alpha",4,n);
    thread B(mythread,"Bravo",3,n);
    mythread("main",2,n);
    if(A.joinable())
    {
        A.join();
    }
    if(B.joinable())
    {
        B.join();
    }
    cout << "Выполнение программы\n";
    return 0;
}
