#include <iostream>
#include <cstdint>

using namespace std;

class Power{
private:
    int a;
    int b;
public:
    void setin(){
        a = 2;
        b = 5;
    }
    void calculate(){
        int result;
        for(int i = 1; i <= b; i++){
            if (i == 1) result = a * 1;
            else result = result * a;
        }
        std::cout << result << endl;
    }
};

class RGBA{
private:
    std::uint8_t m_red = 0;
    std::uint8_t m_green = 0;
    std::uint8_t m_blue = 0;
    std::uint8_t m_alpha = 255;
public:
    RGBA()
    {
    }
    RGBA(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha)
    : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
    {
    }
    void print(){
        std::cout << "Red:" << m_red << " " << "Green:" << m_green << " "
        << "Blue:" << m_blue << " " << "Alpha:" << m_alpha << endl;
    }
};

class Stack{
private:
    int arr[10];
    int length;
public:
    void reset(){
        for(int i = 0; i < 10; i++){
            arr[i] = 0;
        }
        length = -1;
    }

    bool push(int data){
        if(length < 10){
            arr[++length] = data;
            return true;
        }else{
            std::cout << "Stack overflow" << endl;
            return false;
        }
    }
    int pop(){
        if(length != -1){
            return arr[length--] = 0;
        }else{
            std::cout << "Stack is empty" << endl;
            return -1;
        }
    }
    void print(){
        int length1 = length;
        std::cout << "(";
        while(length1 != -1){
            std::cout << arr[length1--];
        }
        std::cout << ")" << endl;
    }
};

int main(){
    Power def;
    def.setin();
    def.calculate();

    RGBA one;
    one.print();
    RGBA two(25, 36, 45, 244);
    two.print();

    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    return 0;
}
