#include <iostream>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <conio.h>

using namespace std;

int main () {
   int Task = 0;
    while (1){
      std::cout << "Choose the task(1-4):" << std::endl;
      std::cin >> Task;
           switch (Task){
                case 1: {
                    int a, b, c, d;
                    std::cout << "Please enter four int numbers:";
                    std::cin >> a >> b >> c >> d;
                    float e = (a*(b+(static_cast<float>(c)/d)));
                    std::cout << e << std::endl;
                    std::cout << "Press enter to continue";
                    getch();
                    system("cls");
                    break;
                }
                case 2: {
                    int a = 21;
                    int b;
                    std::cout << "Please enter the number:" << " ";
                    std::cin >> b;
                    std::cout << (((b-a) > 0)? (b-a)*2 : b-a) << std::endl;
                    std::cout << "Press enter to continue";
                    getch();
                    system("cls");
                    break;
                }
                case 3: {
                    #include <SecondPartOfTheFile.h>
                    extern int a, b, c, d;
                    std::cout << "Please enter four int numbers:";
                    std::cin >> a >> b >> c >> d;
                    float e = (a*(b+(static_cast<float>(c)/d)));
                    std::cout << e << std::endl;
                    std::cout << "Press enter to continue";
                    getch();
                    system("cls");
                    break;
                }
                case 4: {
                    int x = 3;
                    int y = 3;
                    int z = 3;
                    int cube [2][2][2], *pt;
                    pt = &cube [0][0][0];
                    int val = 0;
                    for(int i = 0; i < x; ++i){
                            for(int j = 0; j < y; ++j){
                                for(int k = 0; k < z; ++k)
                                cube[i][j][k] = val++;
                            }
                    }
                    std::cout << "Here value of the cube [1][1][1]:" << " " << cube [1][1][1] << std::endl;
                    std::cout << "Here value of the pt:"<< " "  << *(pt+7) << std::endl;
                    std::cout << "Press enter to continue";
                    getch();
                    system("cls");
                    break;
                }
                 default: {
                    std::cout << "Please, write down correct option\n";
                    continue;
                    }
           }
    }
     return 0;
     }



