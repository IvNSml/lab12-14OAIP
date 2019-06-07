#include <iostream>
#include <fstream>
#include <cstring>
#include "head.h"

struct List {

    WORKER content;

    List *next;

};
using namespace std;

int main() {
    List *top = nullptr;

    int counter = 0;

    ifstream file("/home/ivan/CLionProjects/12lab/first/7.dat", ios::binary);

    while (true) {

        List *temp = new List;

        file.read((char *) &temp->content, sizeof(WORKER));

        if (file.eof()) {
            delete temp;
            break;
        }

        counter++;

        temp->next = top;

        top = temp;
    }

    file.close();

    auto *mass = new WORKER[counter];

for (int i(0); i < counter; i++) {

        mass[i] = top->content;

        top = top->next;
    }

    auto *cmass = new WORKER[counter];

    copy(mass, mass + counter, cmass);

    char met, key, choice;

    while (true) {

        cout << "Выберите действие:" << endl << "1 - вывести первоначальный массив" << endl
             << "2 - отсортировать массив" << endl << "3 - поиск элемента в массиве" << endl << "Выбор:";

        cin >> choice;

        cin.ignore(1000, '\n');

        switch (choice) {

            case '1':

                showmass(mass, counter);

                break;

            case '2':

                copy(mass, mass + counter, cmass);

                cout << "Выберите метод сортировки сортировки:" << endl;

                cout << "1 - сортировка выбором" << endl << "2 - сортировка Шелла" << endl;

                cin >> met;

                cout << "Выберите ключ для сортировки:" << endl;

                cout << "1 - по фамилии (по возрастанию)" << endl << "2 - по окладу (по убыванию)" << endl;

                cin >> key;

                switch (met) {

                    case '1':

                        ShellSort(cmass, counter, key);

                        break;

                    case '2':

                        ShellSort(cmass, counter, key);

                        break;
                }
                break;

            case '3':

                cout << "Выберите ключ поиска:" << endl << "1 - ФИО" << endl << "2 - должность" << endl
                     << "3 - год поступления на работу" << endl << "4 - оклад" << endl << "Выбор:";

                cin >> key;

                cin.ignore(1000, '\n');

                search_record(cmass, counter, key);


                break;

            default:

                cout << "Выбрано неверное действие";

                break;

        }

    }

}