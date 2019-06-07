#ifndef FIRST_HEAD_H
#define FIRST_HEAD_H

#include ""
struct WORKER {

    char fio[30];

    char dolgnost[15];

    int year;

    int salary;

};

void showelement(WORKER *man);

int compare(WORKER first, WORKER second, char key);

int test(WORKER mass[], int size, char key);

void search_record(WORKER mass[], int size, char choice);

void showmass(WORKER *mass, int size);

void SelectSort(WORKER mass[], int size, char key);

void ShellSort(WORKER mass[], int size, char key);

WORKER *linesearch(WORKER mass[], int size, char choice);

WORKER *binsearch(WORKER mass[], int size, char choice, int sort);
#endif //FIRST_HEAD_H
