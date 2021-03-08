#ifndef REPLACEFUN_H_INCLUDED
#define REPLACEFUN_H_INCLUDED
using namespace std;

namespace Homefunctions{
void ReplaceFun (int *Array, int n){
    bool direction;
    if (n < 0) {
        direction = false;
        n = -n;
    } else {
        direction = true;
    }
    n %= 10;
    int last = 10 - 1;
    for (int i = 0; i < n; i++) {
        int temp = (direction = true) ? Array[0] : Array[last];
        for (int j = 0; j < last; j++) {
            if (direction = true)
                Array[j] = Array[j + 1];
            else
                Array[last - j] = Array[last - j - 1];
        }
        if (direction = true)
            Array[last] = temp;
        else
            Array[0] = temp;
    }
    for (int i = 0; i < 10; i++){
        cout << Array[i] << " ";
    }
    cout << "\n";
}

}

#endif // REPLACEFUN_H_INCLUDED
