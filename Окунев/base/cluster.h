#ifndef __CLUSTER_H__
#define __CLUSTER_H__

#include "queue.h"

struct process
{
    unsigned int tacts; //����� ������ 1-10
    unsigned int ProcNeed; //����� ��������� �����������
};

class TCluster
{
    unsigned int processors; //����������� � ��������
    unsigned int ProcFree; //�� ������ ������ �������� �����������
    unsigned int MaxQueue; //������������ ������ ������� ���������
    int* TicksLeft; //�������� ����� ����������(��� ������� ����)
    unsigned int T; //����� ������ ��������
    int* LastResult; //��������� ��������� ������� ��������
    double alpha; //����������� ��������� ����� �����
public:
    TCluster(double a, unsigned int pr, unsigned int t, unsigned int qu);
    void NewTask(TQueue<process>& qu);
    void Emulate();
    void GetRes();
};

#endif
