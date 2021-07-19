#include <iostream>
#include <string>
#define SZ 100
#define AMOUNT 52

using namespace std;

// First Task
class Person{
    std::string m_name;
    unsigned m_age;
    std::string m_gender;
    unsigned m_weight;
public:
    Person(const std::string name = "", unsigned age = 0,const std::string gender = "", unsigned weight = 0)
    :m_name(name), m_age(age), m_gender(gender), m_weight(weight)
    {}

    const std::string getName() const {return m_name;}
    unsigned getAge() const {return m_age;}
    const std::string getGender() const {return m_gender;}
    unsigned getWeight() const {return m_weight;}
};

class Student: public Person{
    unsigned m_year = 0;
    unsigned m_counter = 0;
public:
    Student(const string name = "", unsigned age = 0,const string gender = "", unsigned weight = 0, unsigned year = 0, unsigned counter = 0)
    :Person(name, age, gender, weight), m_year(year), m_counter(++counter)
    {}

    unsigned getYear() const {return m_year;}
    unsigned getCount() const {return m_counter;}
};

void ShowInfo(int index, Student* arr){
    std::cout << arr[index].getName();
    std::cout << " ";
    std::cout << arr[index].getAge();
    std::cout << " ";
    std::cout << arr[index].getGender();
    std::cout << " ";
    std::cout << arr[index].getWeight();
    std::cout << " ";
    std::cout << arr[index].getYear();
    std::cout << "\n";
}
//Second Task
class Fruit{
protected:
    std::string m_name;
    std::string m_colour;
public:
    Fruit(const std::string name = "", const std::string colour = "")
    :m_name(name), m_colour(colour)
    {}
};

class Apple: public Fruit{
public:
    Apple(const std::string name = "Apple", const std::string colour = "")
    :Fruit(name, colour)
    {}
    const std::string getName(){ return m_name;}
    const std::string getColour() { return m_colour;}
};

class Banana: public Fruit{
public:
    Banana(const std::string name = "Banana", const std::string colour = "Yellow")
    :Fruit(name, colour)
    {}
    const std::string getName(){ return m_name;}
    const std::string getColour() { return m_colour;}
};

class GrannySmith: public Apple{
public:
    GrannySmith(const std::string name = "GrannySmith", const std::string colour = "Green")
    :Apple(name, colour)
    {}
    const std::string getName(){ return m_name;}
    const std::string getColour() { return m_colour;}
};



int main(){
// First Task
    int tempind = 0;
    int counter = 0;
    Student arr[SZ] = {
        Student(),
        Student("Vasya", 18, "male", 75, 2020),
        Student("Olga", 19, "female", 60, 2019)
    };
    for(int i = 0; i < SZ; i++){
        if(arr[i].getAge() > 0) counter++;
    }
    std::cout << "There are " << counter << " students" << endl;
    std::cout << "Enter  student's number from the list:";
    std::cin >> tempind;
    ShowInfo(tempind, arr);

    return 0;
}

