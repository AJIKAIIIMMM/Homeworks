#ifndef FILLARR_H_INCLUDED
#define FILLARR_H_INCLUDED
using namespace std;

namespace Homefunctions{
void FillArr (int *EmptyArr){
    int i;
    int j = 0;
    int b;
    for (i = 0; i <= 22; i++){
      if (i % 3 == 1){
            EmptyArr[j++] = i;
      }
    }
}
}

#endif // FILLARR_H_INCLUDED
