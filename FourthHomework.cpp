#include <iostream>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <conio.h>

using namespace std;

int main() {
    int Task = 0;
    while (1){
      std::cout << "Choose the task(1-4):" << std::endl;
      std::cin >> Task;
           switch (Task){
                case 1: {
                    char* a;
                    int b;
                    int c;
                    std::cout << "Please enter two numbers:";
                    std::cin >> b >> c;
                    if ((c+b) >= 10 && (c+b) <= 20) {
                            a = "true";
                        std::cout << a << std::endl;
                    }
                    else {
                        a = "false";
                        std::cout << a << std::endl;}
                    std::cout << "Press enter to continue";
                    getch();
                    system("cls");
                    break;
                }
                case 2: {
                    int a;
                    std::cout << "Please enter the number and we will check it:";
                    std::cin >> a;
                    if (a == 1 || a % 2 == 0 && a / 2 != 0 && a != 2 ){
                        std::cout << "The number is not prime " << std::endl;
                    }
                    else{
                        std::cout << "The number is prime" << std::endl;
                    }
                    std::cout << "Press enter to continue";
                    getch();
                    system("cls");
                    break;
                }
                case 3: {
                    int a;
                    int b;
                    std::cout << "Please enter the numbers :";
                    std::cin >> a >> b;
                    if (a + b == 10 || a == 10 && b == 10) {
                    std::cout << "True" << std::endl;
                    }
                    else {
                    std::cout << "False" << std::endl;
                    }
                    std::cout << "Press enter to continue";
                    getch();
                    system("cls");
                    break;
                }
                case 4:{
                    int i;
                    for (int i = 0; i <= 2021; i++) {
                        if (i % 4 == 0 || i % 400 == 0){
                            std::cout << i << " ";
                        }
                    }
                    std::cout << "\nPress enter to continue";
                    getch();
                    system("cls");
                    break;
                }
            }
    }

    return 0;
}
