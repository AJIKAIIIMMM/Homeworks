#include <iostream>

using namespace std;

// First task
template <typename T>
T div(T a, T b){
    a /= b;
    if(b == 0){
        throw "Second number can not be equal zero";
    }
    return a;
}

// Second task
class Ex{
    double m_x;
public:
    Ex(double x){
        m_x = x;
    }
    void print(){std::cout << m_x;}
};

class Bar{
    double m_y;
public:
    Bar(double y = 0){
        m_y = y;
    }

    void Set(double a){
        if((m_y + a) > 100){
            throw Ex((a*m_y));
        }else m_y = a;
    }
};

// Third task
class OffTheField{
    string m_error;

public:
    OffTheField(string error) : m_error(error)
    { }
    const char* getError() { return m_error.c_str(); }
};

class IllegalCommand{
    string m_error;
public:
    IllegalCommand(string error) : m_error(error)
    { }
    const char* getError() { return m_error.c_str(); }
};

class Robot{
    int x;
    int y;
public:
    Robot(int x = 0, int y = 0)
    :x(x), y(y){}

    Robot movements(){
            char ch;
            while(x < 10 || y < 10){
                std::cout << "Choose the direction: ";
                std::cin >> ch;
                switch (ch)
                {
                case 'L':
                    --x;
                    break;
                case 'R':
                    ++x;
                    break;
                case 'U':
                    ++y;
                    break;
                case 'D':
                    --y;
                    break;
                default:
                    throw IllegalCommand("You put wrong direction");
                    return -1;
                }
            }
            OffTheField("The robot is out of space");
            std::cout << x << ' ' << y << std::endl;
        }

};



int main(){
// First task
    std::cout << "Enter two number:";
    double a, b;
    std::cin >> a >> b;
    try {
        double d = div(a, b);
        cout << "The div of " << a << " and " << b << " is " << d << '\n';
    }
    catch (const char* exception){
        cerr << "Error: " << exception << endl;
    }
// Second task
    Bar bar;
    int n = 1;
    try{
        while(n != 0){
            std::cin >> n;
            bar.Set(n);
        }
    }
    catch(Ex &ex){
        cerr << "Error: ";
        ex.print();
    }
// Third task
    Robot robot;
    try{
        robot.movements();
    }
    catch(IllegalCommand &command){
        cerr << "Error:" << command.getError() << endl;
    }
    catch(OffTheField &field){
        cerr << "Error:" << field.getError() << endl;
    }

    return 0;
}
