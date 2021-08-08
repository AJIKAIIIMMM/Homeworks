#include <iostream>
#include <memory>

using namespace std;

class Date{
    int m_day;
    int m_month;
    int m_year;
public:
    Date(int day, int month, int year)
    :m_day(day), m_month(month), m_year(year){}
    int GetDay(){return m_day;}
    int GetMonth(){return m_month;}
    int GetYear(){return m_year;}
    friend ostream& operator<<(ostream& out, const Date& date);
    friend Date CompareDates(const Date& date1, const Date& date2);
    friend Date SwapDates(const Date& date1, const Date& date2);
};

ostream& operator<<(ostream& out, const Date& date){
    out << date.m_day << "/" << date.m_month << "/" << date.m_year << std::endl;
    return out;
}


Date CompareDates(const Date& date1, const Date& date2){
     if(date1.m_year > date2.m_year){
            if(date1.m_month > date2.m_month){
                if(date1.m_day > date2.m_day){
                    return date1;
                }else return date2;
            }else return date2;
        }else return date2;
}

Date SwapDates(std::unique_ptr<Date> date1, std::unique_ptr<Date> date2){
    date1.swap(date2);
}

int main(){
    std::unique_ptr<Date> today(new Date(6, 8, 2021));
    today->GetDay();
    today->GetMonth();
    today->GetYear();
    std::cout << *today;
    std::unique_ptr<Date> date(today.release());
    if(today == nullptr) std::cout << "Pointer today is NULL";
    else if(date == nullptr) std::cout << "Pointer date is NULL";
    std::unique_ptr<Date> date1(new Date(6, 8, 2021));
    std::unique_ptr<Date> date2(new Date(5, 8, 2021));
    CompareDates(*date1, *date2);
    SwapDates(std::move(date1),std::move(date2));
    return 0;
}
