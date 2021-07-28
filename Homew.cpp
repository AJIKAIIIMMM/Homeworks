#include <iostream>
#include "ARRAYINT.h"
#include <vector>

using namespace std;



void printarr(vector<int> &a){
    cout << "The length is: " << a.size() << '\n';
    for(int i = 0; i < a.size(); i++){
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

void Compare(vector<int> &a){
    int counter1, counter2 = 0;
    for(int j = 0; j < a.size(); j++){
        for(int i = 0; i < a.size();i++){
            if(i != j){
                if(a[j] == a[i]){
                    counter1 = 0;
                    break;
                }else counter1++;
            }
        }
        if(counter1 > 0){
            counter2++;
        }
    }
    std::cout << counter2 << std::endl;
}




int main(){
    vector<int> arr { 10, 8, 6, 4, 2, 1, 8, 10 };
    printarr(arr);
    Compare(arr);
    return 0;
}
