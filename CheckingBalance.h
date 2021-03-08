#ifndef CHECKINGBALANCE_H_INCLUDED
#define CHECKINGBALANCE_H_INCLUDED
using namespace std;

namespace Homefunctions{
bool CheckingBalance (int *Arr){
    int leftSum = 0;
    for(int i = 0; i < 5; i++){
            leftSum += Arr[i];
            int rightSum = 0;
            for (int j = 0; j < 5; j++){
                rightSum += (j > i)? Arr[j] : 0;
            }
            if(leftSum == rightSum){
                return true;
            }
        }
        return false;
   }

}

#endif // CHECKINGBALANCE_H_INCLUDED
