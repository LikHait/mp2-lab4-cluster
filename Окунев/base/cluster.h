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
    int* TicksLeft; //осталось тиков выполнени€(дл€ каждого €дра)
    unsigned int T; //врем€ работы эмул€ции
    int* LastResult; //последний результат запуска эмул€ции
    double alpha; //коэффициент по€влени€ новых задач
public:
    TCluster(double a, unsigned int pr, unsigned int t, unsigned int qu);
    void NewTask(TQueue<process>& qu);
    void Emulate();
    void GetRes();
};

#endif
