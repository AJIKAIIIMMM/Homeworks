#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

istream &endll(istream &stream){
    cout << '\n';
    cout << '\n';
    fflush (stdin);
    return stream;
}

int main(){
  int n = 0;
    while(true){
        cout << "Vvedite chislo: ";
        cin >> n;
        if(!cin)
        {
           cout << "ne verno vveli, povtorite vvod\n";
           cin.clear();
           while (cin.get() != '\n');
        }
        else break;
    }
    cout << n << endll;
    cout << n << endll;
    return 0;
}
