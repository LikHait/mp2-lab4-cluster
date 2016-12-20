#include "cluster.h"
#include <iostream>
using namespace std;

int main()
{
    double a;
    unsigned int pr;
    unsigned int t;
    unsigned int max;
    setlocale(LC_ALL, "Russian");
    cout << "Введите параметры имитируемого сервера \n";
    cout << "Порог появления новой задачи (от 0 до 1). alpha = ";
    cin >> a; 
    cout << "Количество процессоров (от 1 до 64) : ";
    cin >> pr;
    cout << "Тактов работы (min 10 тактов) : ";
    cin >> t;
    cout << "Максимальный размер очереди, 0 - без ограничений: ";
    cin >> max;
    TCluster sample(a, pr, t, max);
    sample.Emulate();
    cout << "Результаты имитации работы : ";
    sample.GetRes();
    int ad;
    cin >> ad;
	return 0;
}
