#include "queue.h"
#include "cluster.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <windows.h>

TCluster::TCluster(double a, unsigned int pr, unsigned int t, unsigned int max)
{
    if (pr > 64)
        throw("Wrong number of processors");
    TicksLeft = new int[pr];
    if (TicksLeft == nullptr)
        throw("Memory allocation error");
    LastResult = new int[4];
    if (LastResult == nullptr)
    {
        delete[] TicksLeft;
        throw("Memory allocation error");
    }
    for (int i = 0; i < 4; i++)
        LastResult[i] = 0;
    for (int i = 0; i < pr; i++)
        TicksLeft[i] = 1;
    T = t;
    processors = pr;
    alpha = a;
    ProcFree = 0;
    if (max == 0)
        MaxQueue = MAX_SIZE;
    else
        MaxQueue = max;
}

TCluster::~TCluster()
{
    delete[] TicksLeft;
    delete[] LastResult;
}

void TCluster::NewTask(TQueue<process>& qu)
{
    srand(time(0));
    Sleep(500);
    double talp = (double)(rand() % 100) / 100;
    std::cout << talp << ' ';
    if (talp > alpha)
    {
        if (!qu.IsFull())
        {
            process add;
            add.tacts = rand() % 10 + 1;
            Sleep(300);
            add.ProcNeed = rand() % processors + 1;
            qu.InsLast(add);
            LastResult[1]++;
            std::cout << "Новая задача: " << add.tacts << " тактов " << add.ProcNeed << " процессоров" << std::endl;
        }
        else
            LastResult[0]++;
    }
}

void TCluster::Emulate()
{
    TQueue<process> PrQu(MaxQueue);
    for (int t = 0; t < T; t++)
    {
        NewTask(PrQu);
        for (int i = 0; i < processors; i++)
        {
            TicksLeft[i] -= 1;
            if (TicksLeft[i] == 0)
                ProcFree++;
        }
        std::cout << ProcFree << std::endl;
        if (ProcFree > 0)
        {
            if (!PrQu.IsEmpty())
            {
                for (int i = 0; i < PrQu.GetCount(); i++)
                {
                    if (ProcFree >= PrQu.GetElement(i).ProcNeed)
                    {
                        ProcFree -= PrQu.GetElement(i).ProcNeed;
                        LastResult[2]++;
                        int j = 0;
                        while (PrQu.GetElement(i).ProcNeed != 0)
                        {
                            if (TicksLeft[j] <= 0)
                            {
                                LastResult[3] += TicksLeft[j];
                                TicksLeft[j] = PrQu.GetElement(i).tacts;
                                process tmp = PrQu.GetElement(i);
                                tmp.ProcNeed--;
                                PrQu.SetElement(tmp, i);
                            }
                            j++;
                        }
                        PrQu.Delete(i);
                        if (ProcFree == 0)
                            break;
                    }
                    else
                    {
                        PrQu.IncPriority(i);
                        if (PrQu.GetPriority(i) < 4)
                        {
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
    }
    int max = 0;
    for (int i = 0; i < processors; i++)
    {
        if (max < TicksLeft[i])
            max = TicksLeft[i];
        LastResult[3] += TicksLeft[i];
    }
    LastResult[3] = LastResult[3] - max * processors - processors;
    LastResult[3] = LastResult[3] - 2 * LastResult[3]; //меняем знак числа на положительный
}

void TCluster::GetRes()
{
    using namespace std;
    cout << "   Задач не было поставлено в очередь: " << LastResult[0] << endl;
    cout << "   Задач поставлено в очередь: " << LastResult[1] << endl;
    cout << "   Задач выполнено: " << LastResult[2] << endl;
    cout << "   Суммарно тактов простоя: " << LastResult[3] << endl;
}
