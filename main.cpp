#include <iostream>

#include "Tests.h"
#include "Menu.h"

int main()
{
    int choice;

    do
    {
        std::cout << "\n===== LAB 3 =====\n";
        std::cout << "1. Run tests\n";
        std::cout << "2. Queue menu (int)\n";
        std::cout << "3. Queue menu (std::string)\n";
        std::cout << "0. Exit\n";

        choice = ReadInt();

        switch(choice)
        {
            case 1:
                RunAllTests();
                PerformanceTest();
                break;

            case 2:
                RunMenu();
                break;

            case 3:
                RunStringMenu();
                break;
        }

    } while(choice != 0);

    return 0;
}

