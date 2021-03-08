#ifndef SWAPARRVALUE_H_INCLUDED
#define SWAPARRVALUE_H_INCLUDED
using namespace std;

namespace Homefunctions{
void swaparrvalue (int *arrZeroOne){
    int i;
    arrZeroOne[0] = 1;
    arrZeroOne[1] = 0;
    arrZeroOne[2] = 0;
    arrZeroOne[3] = 1;
    arrZeroOne[4] = 1;
    arrZeroOne[5] = 0;
    arrZeroOne[6] = 1;
    arrZeroOne[7] = 1;
    arrZeroOne[8] = 0;
    arrZeroOne[9] = 0;
    cout << "\nThe values were changed:" << " " << endl;
    for (i == 0; i < 10; i++){
        cout << arrZeroOne [i] << " ";
    }
    cout << "\n";
}
}


#endif // SWAPARRVALUE_H_INCLUDED
