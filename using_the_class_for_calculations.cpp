#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class MyMoney
{
private:
    string name;
    double money, rate;
    int time;
    double getMoney()
    {
        double s = money;
        for(int k = 1; k <= time; k++)
        {
            s*=(1+rate/100);
        }
        return s;
    }
public:
    void showAll()
    {
        cout << "Имя : " << name << endl;
        cout << "Вклад : " << money << endl;
        cout << "Ставка (%) : " << rate << endl;
        cout << "Период (лет) : " << time << endl;
        cout << "Итоговая сумма : " << getMoney() << endl;
    }

void setAll(string n, double m, double r, int t)
{
    name = n;
    money = m;
    rate = r;
    time = t;
}

void setAll(string n)
{
    name = n;
}

void setAll(int t)
{
    time = t;
}

void setAll(double m, double r)
{
    money = m;
    rate = r;
}

void setAll(double x, bool s = true)
{
    if(s)
    {
        money = x;
    }
    else
    {
        rate = x;
    }
}
};

int main()
{
    MyMoney obj;
    //заполнения полей
    obj.setAll("Дмитрий Дмитреевич Дима", 1000, 5, 2);
    obj.showAll();
    cout << endl;
    //меняем имя
    obj.setAll("Иван Дмитрий Петрович");
    obj.showAll();
    cout << endl;
    //меняем время
    obj.setAll(14);
    obj.showAll();
    cout << endl;
    //меняем начальную суммы
    obj.setAll(1200.0);
    obj.showAll();
    cout << endl;
    //изменение начальной суммы
    obj.setAll(1500,true);
    obj.showAll();
    cout << endl;
    //изменение процентов
    obj.setAll(3,false);
    obj.showAll();
    cout << endl;
    //обратно возращаем старые данные
    obj.setAll("дмитрий",1000.0, 5.0, 5);
    obj.showAll();
    cout << endl;
    return 0;
}
