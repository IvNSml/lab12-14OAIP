#include "head.h"

void showelement(WORKER *man) {

    if (!man) {

        cout << endl << "Человек не найден!" << endl;

    } else {

        cout << endl << "ФИО:" << man->fio << endl;

        cout << "Должность:" << man->dolgnost << endl;

        cout << "Год поступления на работу:" << man->year;

        cout << endl << "Оклад:" << man->salary << endl;

    }

}

int compare(WORKER first, WORKER second, char key) {

    switch (key) {

        case '1':

            if (strncmp(first.fio, second.fio, 30) > 0) {

                return 1;//возрастает

            } else if (strncmp(first.fio, second.fio, 30) < 0) {

                return 2;//убывает

            }

            break;

        case '2':

            if (strncmp(first.dolgnost, second.dolgnost, 15) <= 0) {

                return 1;//возрастает

            } else if (strncmp(first.dolgnost, second.dolgnost, 15) > 0) {

                return 2;//убывает

            }

            break;

        case '3':

            if (first.year <= second.year) {

                return 1;//возрастает

            } else if (first.year > second.year) {

                return 2;//убывает

            }

            break;

        case '4':

            if (first.salary < second.salary) {

                return 1;//возрастает

            } else if (first.salary > second.salary) {

                return 2;//убывает

            }

            break;
    }
    return 0;//never get to there
}

int test(WORKER mass[], int size, char key) {

    int issorted = compare(mass[0], mass[1], key);

    int fil;

    for (int i(1); i < size - 2; i++) {

        fil = compare(mass[i], mass[i + 1], key);

        if (issorted == fil) {

            continue;

        } else {
            return 0;
        }

    }

    return issorted;

}

WORKER *linesearch(WORKER mass[], int size, char choice) {

    switch (choice) {

        case '1': {

            char name[30];

            cout << endl << "Введите ФИО:";

            cin >> name;

            for (int i(0); i < size; i++) {

                if (!strncmp(mass[i].fio, name, 30)) {

                    return &mass[i];
                }
            }
            break;

        }

        case '2': {

            char num[15];

            cout << endl << "Введите должность:";

            cin >> num;

            for (int i(0); i < size; i++) {

                if (!strncmp(mass[i].dolgnost, num, 15)) {

                    return &mass[i];

                }

            }

            break;

        }

        case '3': {

            int y;

            cout << "Введите год поступления на работу: ";

            cin >> y;

            for (int i(0); i < size; i++) {

                if (mass[i].year == y) {

                    return &mass[i];

                }

            }

            break;

        }

        case '4': {

            int sal;

            cout << endl << "Введите оклад:";

            cin >> sal;

            for (int i(0); i < size; i++) {

                if (mass[i].salary == sal) {

                    return &mass[i];

                }

            }

            break;

        }

    }
    return nullptr;
}

WORKER *binsearch(WORKER mass[], int size, char choice, int sort) {

    int left = 0, right = size - 1, mid;

    switch (choice) {

        case '1': {

            char name[30];

            cout << endl << "Введите ФИО:";

            cin >> name;

            while (true) {

                mid = left + (right - left) / 2;

                if (!strncmp(mass[mid].fio, name, 30)) {
                    return &mass[mid];
                } else if (strncmp(mass[mid].fio, name, 30) > 0) {

                    if (sort == 1) {

                        left = mid;

                    } else {
                        right = mid;
                    }

                } else if (strncmp(mass[mid].fio, name, 30) < 0) {

                    if (sort == 1) {

                        right = mid;

                    } else {

                        left = mid;

                    }

                }

                if (right - left == 1) { break; }

            }

            break;

        }

        case '2': {

            char num[15];

            cout << endl << "Введите дожность:";

            cin >> num;

            while (true) {

                mid = left + (right - left) / 2;

                if (!strncmp(mass[mid].dolgnost, num, 15)) {

                    return &mass[mid];

                } else if (strncmp(mass[mid].dolgnost, num, 15) > 0) {

                    if (sort == 1) {

                        left = mid;

                    } else {

                        right = mid;

                    }

                } else if (strncmp(mass[mid].dolgnost, num, 15) < 0) {

                    if (sort == 1) {

                        right = mid;

                    } else {

                        left = mid;

                    }

                }

                if (right - left == 1) { break; }

            }

            break;

        }

        case '3': {

            int y;

            cout << endl << "Введите год поступления на работу:";

            cin >> y;

            while (true) {

                mid = left + (right - left) / 2;

                if (mass[mid].year == y) {

                    return &mass[mid];

                } else if (mass[mid].year > y) {

                    if (sort == 2) {

                        left = mid;

                    } else {

                        right = mid;

                    }

                } else if (mass[mid].year < y) {

                    if (sort == 2) {

                        right = mid;

                    } else {

                        left = mid;

                    }

                }

                if (right - left == 1) { break; }

            }

            break;

        }

        case '4': {

            int sal;

            cout << endl << "Введите оклад:";

            cin >> sal;

            while (true) {

                mid = left + (right - left) / 2;

                if (mass[mid].salary == sal) {

                    return &mass[mid];

                } else if (mass[mid].salary > sal) {

                    if (sort == 2) {

                        left = mid;

                    } else {

                        right = mid;

                    }

                } else if (mass[mid].salary < sal) {

                    if (sort == 2) {

                        right = mid;

                    } else {

                        left = mid;

                    }

                }

                if (right - left == 1) { break; }

            }

            break;

        }

    }

    return nullptr;

}

void search_record(WORKER mass[], int size, char choice) {

    WORKER *element = nullptr;

    int sort = test(mass, size, choice);

    if (sort == 0) {

        element = linesearch(mass, size, choice);

    } else {

        element = binsearch(mass, size, choice, sort);

    }

    showelement(element);

}

void showmass(WORKER *mass, int size) {

    for (int j(0); j < size; j++) {

        cout << endl << "ФИО:" << mass[j].fio << endl;

        cout << "Должность:" << mass[j].dolgnost << endl;

        cout << "Год поступления на работу: " << mass[j].year << endl;

        cout << "Оклад:" << mass[j].salary << endl << endl;

    }

}

void SelectSort(WORKER mass[], int size, char key) {

    int k, counterc(0), countert(0);

    WORKER temp;

    for (int i(0); i < size; i++) {

        k = i;

        temp = mass[i];

        for (int j = i + 1; j < size; j++) {

            if (key == '2') {

                if (mass[j].salary > temp.salary) {

                    k = j;

                    temp = mass[j];

                }

            } else if (key == '1') {

                if (strncmp(temp.fio, mass[j].fio, 30) > 0) {

                    k = j;

                    temp = mass[j];

                }

            }
            counterc++;
        }

        mass[k] = mass[i];

        mass[i] = temp;

        countert++;

    }

    showmass(mass, size);

    cout << "Количество сравнений - " << counterc << endl << "Количество перестановок - " << countert << endl;

}

void ShellSort(WORKER mass[], int size, char key) {

    int i, j, step, counterc(0), countert(0);

    WORKER temp;

    for (step = size / 2; step > 0; step /= 2) {

        for (i = step; i < size; i++) {

            temp = mass[i];

            for (j = i; j >= step; j -= step) {

                if (key == '1') {

                    counterc++;

                    if (strncmp(temp.fio, mass[j - step].fio, 30) < 0) {

                        countert++;

                        mass[j] = mass[j - step];

                    } else {

                        break;

                    }

                } else if (key == '2') {

                    counterc++;

                    if (temp.salary > mass[j - step].salary) {

                        countert++;

                        mass[j] = mass[j - step];

                    } else {

                        break;

                    }

                }

            }

            mass[j] = temp;

        }

    }
    showmass(mass, size);
}