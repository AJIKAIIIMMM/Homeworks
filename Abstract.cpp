#include <iostream>
#include <math.h>

using namespace std;
// First Task
class Figure{
public:
    virtual ~Figure(){}
    virtual double area() = 0;
};

class Parallelogram : public Figure{
    double m_h;
    double m_a;
public:
    Parallelogram(double h, double a)
    :m_h(h), m_a(a)
    {}
    double area(){return (m_h * m_a);}
};

class Circle : public Figure{
    double m_r;
public:
    Circle(double r)
    :m_r(r)
    {}
    double area(){return (pow(m_r,2) * 3.14);}
};

class Rectangle : public Parallelogram{
public:
    Rectangle(double a, double b)
    :Parallelogram(a, b)
    {}
};

class Square : public Parallelogram {
public:
    Square(double a, double b)
    :Parallelogram(a, b)
    {}
};

class Rhombus : public Parallelogram{
public:
    Rhombus(double h, double a)
    :Parallelogram(h, a)
    {}
};
// Second Task
class Car{
    std::string m_company;
    std::string m_model;
public:
    Car(std::string company, std::string model)
    :m_company(company), m_model(model)
    {
        std::cout << "This  " << company << " makes " << model << std::endl;
    }
    virtual ~Car(){}
};

class PassengerCar : virtual public Car{
public:
    PassengerCar(std::string company, std::string model, std::string company1, std::string model1)
    :Car(company, model)
    {
        std::cout << "This  " << company1 << " makes " << model1 << std::endl;
    }
};

class Bus : virtual public Car{
public:
    Bus(std::string company, std::string model, std::string company2, std::string model2)
    :Car(company, model)
    {
        std::cout << "This  " << company2 << " makes " << model2 << std::endl;
    }
};

class Minivan : public PassengerCar, public Bus{
public:
    Minivan(std::string company, std::string model, std::string company1, std::string model1,
            std::string company2, std::string model2, std::string company3, std::string model3)
    :PassengerCar(company, model, company1, model1), Bus(company, model, company2, model2), Car(company, model)
    {
        std::cout << "This  " << company3 << " makes " << model3 << std::endl;
    }
};
// Third Task
class Fraction{
    int x;
    int y;
public:
    Fraction(int x = 0, int y = 1)
    :x(x), y(y)
    {}

    Fraction& operator *=(const Fraction&);
    Fraction& operator +=(const Fraction&);
    Fraction& operator -=(const Fraction&);
    Fraction& operator /=(const Fraction&);
    Fraction operator- () const
    {
        return Fraction(-x, -y);
    }

    Fraction(const Fraction & obj)
    {
        x = this->x;
        y= this->y;
    }

    bool operator>=(Fraction& z)
    {
        if (1.*(this->x / this->y)>=1.*(z.x / z.y))
            return true;
        else
            return false;
    }

    bool operator<(Fraction& z)
    {
        if (1.*(this->x / this->y)<1.*(z.x / z.y))
            return true;
        else
            return false;
    }

    bool operator<=(Fraction& z)
    {
        if (1.*(this->x / this->y)>=1.*(z.x / z.y))
            return true;
        else
            return false;
    }

    bool operator>(Fraction& z)
    {
        return (1.*(this->x / this->y)>1.*(z.x / z.y)) ? true : false;
    }

    bool operator == (Fraction& z)
    {
        return (1.*(this->x / this->y) == 1.*(z.x / z.y)) ? true : false;
    }

    bool operator !=(Fraction& z)
    {
        return (1.*(this->x / this->y) != 1.*(z.x / z.y)) ? true : false;
    }

    void setValue (int a, int b) {x = a; y = b;}
    void showFrac() const;
};

Fraction& Fraction::operator *=(const Fraction& f)
{
    x *= f.x;
    y *= f.y;
    return *this;
}
Fraction& Fraction::operator +=(const Fraction& f)
{
    x = x * f.y + y * f.x;
    y *= f.y;
    return *this;
}
Fraction& Fraction::operator -=(const Fraction& f)
{
    x = x * f.y - y * f.x;
    y *= f.y;
    return *this;
}
Fraction& Fraction::operator /=(const Fraction& f)
{
    x *= f.y;
    y *= f.x;
    return *this;
}

void Fraction::showFrac()  const
{
    cout << x << "/" << y;
}

Fraction operator *(Fraction& f1, const Fraction& f2)
{ return f1 *= f2; }
Fraction operator +(Fraction& f1, const Fraction& f2)
{ return f1 += f2; }
Fraction operator -(Fraction& f1, const Fraction& f2)
{ return f1 -= f2; }
Fraction operator /(Fraction& f1, const Fraction& f2)
{ return f1 /= f2; }

int main(){
// First Task
    Parallelogram para(5, 8);
    Circle circ(5);
    Rectangle rect(6, 4);
    Square sq(5, 5);
    Rhombus rhomb(4, 8);
    Figure *figure1 = &para;
    Figure *figure2 = &circ;
    Figure *figure3 = &rect;
    Figure *figure4 = &sq;
    Figure *figure5 = &rhomb;
    std::cout << figure1 -> area() << std::endl;
    std::cout << figure2 -> area() << std::endl;
    std::cout << figure3 -> area() << std::endl;
    std::cout << figure4 -> area() << std::endl;
    std::cout << figure5 -> area() << std::endl;
// Second Task
    Car car("Ford company", "Tiguan model");
    PassengerCar pascar("Ford company", "Tiguan model", "Porche company", "Carrera model");
    Bus bus("Ford company", "Tiguan model", "KAMAZ company", "NEFAZ model");
    Minivan mini("Ford company", "Tiguan model", "Porche company", "Carrera model",
                 "KAMAZ company", "NEFAZ model", "Gazel company", "NEXT model");
// Third Task
    Fraction a, b, c;
    a.setValue(5, 7);
    b.setValue(6, 5);
    c = a * b;
    c.showFrac();
    std::cout << std::endl;
    a.setValue(5, 7);
    b.setValue(6, 5);
    c = a + b;
    c.showFrac();
    std::cout << std::endl;
    a.setValue(6, 4);
    b.setValue(6, 5);
    c = a - b;
    c.showFrac();
    std::cout << std::endl;
    a.setValue(5, 7);
    b.setValue(6, 5);
    c = a / b;
    c.showFrac();
    std::cout << std::endl;
    a.setValue(-5, -7);
    a.showFrac();
    std::cout << std::endl;
    a.setValue(5, 7);
    b.setValue(6, 5);
    if (a == b)
    {
        a.showFrac();
        cout << "==";
        b.showFrac();
    }

    if (a != b)
    {
        a.showFrac();
        cout << "!=";
        b.showFrac();
    }

    if (a <= b)
    {
        a.showFrac();
        cout << "<=";
        b.showFrac();
    }

    if (a > b)
    {
        a.showFrac();
        cout << ">";
        b.showFrac();
    }

    if (a >= b)
    {
        a.showFrac();
        cout << ">=";
        b.showFrac();
    }

    if (a < b)
    {
        a.showFrac();
        cout << "<";
        b.showFrac();
    }
    return 0;
}
