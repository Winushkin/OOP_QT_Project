#include "array.h"
#include "number.h"
#include "polynom.h"


#ifndef OOPPRACTICE_APPLICATION_H
#define OOPPRACTICE_APPLICATION_H


class Application{

public:
    Application();

    void showMenu();

    void mainMenu();

    int exec();

    int polynomApp();

    void polynomMenu();
};

#endif //OOPPRACTICE_APPLICATION_H
