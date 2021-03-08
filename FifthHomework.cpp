#include <iostream>
#include <conio.h>
#include <stdarg.h>
#include <stdio.h>
#include <swaparrvalue.h>
#include <CheckingBalance.h>
#include <ReplaceFun.h>
#include <Argument.h>
#include <FillArr.h>

using namespace std;
using namespace Homefunctions;

int main(){
    int Task = 0;
    while (1){
        cout <<"Choose the task(1-4):";
        cin >> Task;
        switch (Task){
            case 1:{
                int i;
                int arrZeroOne [] = {0, 1, 1, 0, 0, 1, 0, 0, 1, 1};
                cout << "Present values:" << " " << endl;
                for (i == 0; i < 10; i++){
                    cout << arrZeroOne [i] << " ";
                }
                swaparrvalue(arrZeroOne);
                Argument(10, arrZeroOne[0], arrZeroOne[1], arrZeroOne[2], arrZeroOne[3], arrZeroOne[4],
                         arrZeroOne[5], arrZeroOne[6], arrZeroOne[7], arrZeroOne[8], arrZeroOne[9]);
                cout << "Press enter to continue";
                getch();
                system("cls");
                break;
            }
            case 2: {
                int i;
                int EmptyArr [7];
                int* FilledArr;
                FillArr(EmptyArr);
                for (i = 0; i <= 7; i++){
                    cout << EmptyArr[i] << " ";
                }
                cout << "Press enter to continue";
                getch();
                system("cls");
                break;
            }
            case 3: {
                int Arr[4];
                int i;
                cout << "Fill the array:";
                for (i == 0; i <= 4; i++){
                    cin >> Arr[i];
                }
                CheckingBalance(Arr);
                cout << CheckingBalance(Arr);
                cout << "\n";
                cout << "Press enter to continue";
                getch();
                system("cls");
                break;
            }
            case 4:{
                int Array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
                int n;
                cin >> n;
                ReplaceFun(Array, n);
                cout << "Press enter to continue";
                getch();
                system("cls");
                break;
            }
        }
    }
    return 0;
}







