#include "application.h"


using namespace std;


Application::Application() {}


void Application::showMenu() {
    cout << "1. Создать массив\n";
    cout << "2. Заполнить массив\n";
    cout << "3. Изменить размерность массива\n";
    cout << "4. Вывести элементы массива\n";
    cout << "5. Посчитать среднее\n";
    cout << "6. Посчитать СКО\n";
    cout << "7. Отсортировать\n";
    cout << "8. Изменить элемент\n";
    cout << "0. Назад\n\n";
}


int Application::exec(){
    unsigned char choice, sortReverse;
    int len, newLen, index;
    number value;
    Array *array = new Array(0);

    while(true){
        showMenu();
        cout << "Выберите: "; cin >> choice;

        switch (choice){

            case '1':
                cout << "Введите длину массива: "; cin >> len;
                array = new Array(len);
                break;

            case '2':
                cout << "Введите " << array->getLength() << " элементов массива через пробел\n";
                array->fill();
                cout << "Массив заполнен\n";
                break;

            case '3':
                cout << "Введите новую длину массива: "; cin >> newLen;
                array->resize(newLen);
                break;

            case '4':
                array->printArray();
                break;

            case '5':
                cout << "Среднее значение: " << array->averageValue() << "\n";
                break;

            case '6':
                cout << "СКО:" << array->SKO() << "\n";
                break;

            case '7':
                cout << "Сортировка:\n";
                cout << "1. По возрастанию\n";
                cout << "2. По убыванию\n";
                cin >> sortReverse;
                switch (sortReverse) {
                    case '1':
                        array->shakerSort();
                        break;

                    case '2':
                        array->shakerSort(true);
                        break;
                }
                cout << "Сортировка завершена\n";
                break;

            case '8':
                cout << "Введите\n";
                cout << "Индекс элемента: "; cin >> index;
                cout << "Новое значение: "; cin >> value; cout << "\n";

                array->changeElement(index, value);
                cout << "Значение элемента заменено\n";
                break;

            case '0':
                return 0;

            default:
                cout << "Неверный номер\n";

        }
    }
}


void Application::mainMenu() {
    char choise;
    while(true){
        cout << "Меню программы:\n" <<
             "1) Действия с массивом\n" <<
             "2) Действия с полиномом\n" <<
             "3) Выход\n--> ";
        cin >> choise;
        switch (choise) {
            case '1':
                exec();
                break;
            case '2':
                polynomApp();
                break;
            case '3':
                return;
            default:
                cout << "\nНеверный ввод\n";
                return;
        }
    }
}


void Application::polynomMenu() {
    cout << "1) Создать полином\n" <<
    "2) Изменить коэффициент\n" <<
    "3) Изменить один из корней\n" <<
    "4) Вычислить значение в заданной точке\n" <<
    "5) Показать полином\n" <<
    "6) Назад\n--> ";
}


int Application::polynomApp() {
    Polynom* polynom = new Polynom;
    char choise;
    number leadingCoefficient;
    number root;
    number* roots = nullptr;
    int rootsCount = 0;

    while(true){
        polynomMenu();
        cin >> choise;
        switch (choise) {
            case '1':
                if(roots != nullptr) {
                    delete[] roots;
                    roots = nullptr;
                    rootsCount = 0;
                }
                cout << "\nВведите значение коэффициента an = ";
                cin >> leadingCoefficient;
                cout << "Ввести корни полинома - 1\nКорней нет - 0\n--> ";
                cin >> choise;
                if(choise != '0') {
                    cout << "Введите корни полинома:\n";
                    roots = new number[rootsCount];
                    while (cin >> root){
                        number  *rez = new number[rootsCount+1];
                        for (int i = 0; i < rootsCount; i++) {
                            rez[i] = roots[i];
                        }
                        rez[rootsCount] = root;
                        rootsCount++;
                        delete[] roots;
                        roots = rez;
                        if (cin.peek() == '\n') {
                            break;
                        }
                    }
                }
                delete polynom;
                polynom = polynom->fill(leadingCoefficient, roots, rootsCount + 1);
                break;

            case '2':
                cout << "\nВведите новый коэффициент: ";
                cin >> leadingCoefficient;
                delete polynom;
                polynom = polynom->fill(leadingCoefficient, roots, rootsCount + 1);
                break;

            case '3':
                int index;
                cout << "\nВведите индекс корня: ";
                cin >> index;
                if(rootsCount == 0) {
                    cout << "Корни полинома пусты\n";
                    break;
                }
                cout << "Введите новый корень: ";
                cin >> *(roots + index);
                delete polynom;
                polynom = polynom->fill(leadingCoefficient, roots, rootsCount + 1);
                break;

            case '4':
                int point;
                cout << "\nВведите точку\n" << "x = ";
                cin >> point;
                cout << "p(" << point << ") = " << polynom->valueAtPoint(point);
                break;

            case '5':
                cout << *polynom;
                break;

            case '6':
                delete polynom;
                polynom = nullptr;
                return 0;

            default:
                cout << "\nНеверный ввод";
                break;
        }
        cout << "\n";
    }
}