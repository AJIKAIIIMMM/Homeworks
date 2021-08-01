#include <iostream>
#include <string>

using namespace std;

template <class T>
class Pair1{
    T a, b;
public:
    Pair1(const T a, const T b)
    :a(a), b(b)
    {}

    T first()const{return a;}
    T second()const{return b;}
};

template <class U, class C>
class Pair{
    U a;
    C b;
public:
    Pair(U a, C b)
    :a(a), b(b)
    {}

    const U first()const{return a;}
    U first(){return a;}
    const C second()const{return b;}
    C second(){return b;}
};




template <class C>
class StringValuePair: public Pair<string, C>{
public:
    StringValuePair(const string& k,const C b)
    :Pair<string, C>(k, b){}
};

int main(){
    Pair1<int> p1(6, 9);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << std::endl;
    const Pair1<double> p2(3.4, 7.8);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << std::endl;

    Pair<int, double> p3(6, 7.8);
    cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';
    const Pair<double, int> p4(3.4, 5);
    cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';


    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}
