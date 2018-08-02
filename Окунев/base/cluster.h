#ifndef __CLUSTER_H__
#define __CLUSTER_H__

#include "queue.h"

struct process
{
    unsigned int tacts; //число тактов 1-10
    unsigned int ProcNeed; //число требуемых процессоров
};

class TCluster
{
    unsigned int processors; //процессоров в кластере
    unsigned int ProcFree; //на данный момент свободно процессоров
    unsigned int MaxQueue; //максимальный размер очереди процессов
    int* TicksLeft; //осталось тиков выполнения(для каждого ядра)
    unsigned int T; //время работы эмуляции
    int* LastResult; //последний результат запуска эмуляции
    double alpha; //коэффициент появления новых задач
public:
    TCluster(double a, unsigned int pr, unsigned int t, unsigned int qu);
    ~TCluster();
    void NewTask(TQueue<process>& qu);
    void Emulate();
    void GetRes();
};

#endif
