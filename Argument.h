#ifndef ARGUMENT_H_INCLUDED
#define ARGUMENT_H_INCLUDED
using namespace std;

namespace Homefunctions{
int Argument(int n, ...){
    int a;
    int Indo [10];
    va_list Arr;
    va_start(Arr, n);
    for (int i = 0; i < n; i++){
        if (va_arg(Arr, int) == 0){
           Indo[i] = 1;
        } else {
           Indo[i] = 0;
        }
    }
    cout << "\nThe values were changed:" << " " << endl;
    for (int i = 0; i < 10; i++){
        cout << Indo [i] << " ";
    }
    cout << "\n";
    va_end(Arr);
}

}

#endif // ARGUMENT_H_INCLUDED
