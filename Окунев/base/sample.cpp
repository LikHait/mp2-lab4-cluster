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
    cout << "������� ��������� �������� \n";
    cout << "����� ��������� ����� ������ (�� 0 �� 1). alpha = ";
    cin >> a; 
    cout << "���������� ����������� (�� 1 �� 64) : ";
    cin >> pr;
    cout << "������ ������ (�� 10) : ";
    cin >> t;
    cout << "������������ ������ ������� (�� ����� 25) : ";
    cin >> max;
    TCluster sample(a, pr, t, max);
    sample.Emulate();
    cout << "���������� �������� : ";
    sample.GetRes();
    int ad;
    cin >> ad;
	return 0;
}
