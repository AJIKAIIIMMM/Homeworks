#include <iostream>
#include <time.h>
#include <stdlib.h>
#define AMOUNT 52

using namespace std;


//Third Task
int RulesForPlayer(int* Cards);
int RulesForDealer(int* Cards);

class Players{
protected:
    int m_money;
    int m_bet;
    int m_hand;
public:
    Players(int money = 1000, int bet = 0, int hand = 0)
    :m_money(money), m_bet(bet), m_hand(hand)
    {}

};

class Dealer:public Players{
public:
    Dealer(int money = 1000, int bet = 0, int hand = 0)
    :Players(money, bet, hand)
    {}
    void setValue(int bet){
        m_bet = bet;
        m_money = m_money - bet;
        std::cout << "Dealer's capital now: " << m_money << endl;
    }
    int getBet(){return m_bet;}
    void IncreaseMoney(int money){
        m_money = m_money + money;
        std::cout << "Dealer's capital is now:" << m_money;
    }
    int setNom(int nom){
        m_hand = m_hand + nom;
        return m_hand;
    }
    friend class BlackJack;
};

class Customer:public Players{
public:
    Customer(int money = 1000, int bet = 0, int hand = 0)
    :Players(money, bet, hand)
    {}
    void setValue(int bet){
        m_bet = bet;
        m_money = m_money - bet;
        std::cout << "Customer's capital now: " << m_money << endl;
    }
    int getBet(){return m_bet;}
    void IncreaseMoney(int money){
        m_money = m_money + money;
        std::cout << "Customer's capital is now:" << m_money;
    }
    int setNom(int nom){
        m_hand = m_hand + nom;
        return m_hand;
    }
    friend class BlackJack;
};

class BlackJack{
protected:
    int *m_Cards;
public:
    BlackJack()
    {m_Cards = new int[AMOUNT];}

    ~BlackJack(){
        delete[] m_Cards;
    }

    void SetValue(int* Cards){
        m_Cards = Cards;
    }
    int RandomCard(){
        int index = rand() % AMOUNT + 1;
        return index;
    }
};

int main()
{

// Third Task
    BlackJack Jack;
    Customer cust;
    int tempCust;
    int tempDeal;
    Dealer deal;
    unsigned bet = 0;
    int Cards[AMOUNT] = {
        2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,
        2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,
        2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,
        2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11
    };
    Jack.SetValue(Cards);
    std::cout << "Enter your bet:";
    std::cin >> bet;
    cust.setValue(bet);
    deal.setValue(bet);
    tempCust = Cards[Jack.RandomCard()];
    tempDeal = Cards[Jack.RandomCard()];
    RulesForPlayer(Cards);
    RulesForDealer(Cards);

    return 0;
}

int RulesForPlayer(int* Cards){
    BlackJack Jack;
    int a = Cards[Jack.RandomCard()];
    int b = Cards[Jack.RandomCard()];
    char c;
    std::cout << "Customer's cards " << a << " " << b << "" << "("
    << a + b << ")" << endl;
    if((a + b) > 21){
        std::cout << "You are lose";
        return 0;
    }
    else if(a == 11 || b == 11){
        std::cout << "Invert 11 to 1 or not? (y/n)";
        std::cin >> c;
        if(c = 'y' && a == 11) a = 1;
        else if(c = 'y' && b == 11) b = 1;
        else if(c = 'n' && a == 11) a = 11;
        else if(c = 'n' && b == 11) b = 11;
    }
    else if(a == 11 && b == 10 || a == 10 && b == 11){
        Customer cust;
        int price;
        std::cout << "You have BlakcJack" << endl;
        price = cust.getBet() * 1.5;
        cust.IncreaseMoney(price);
    }
}

int RulesForDealer(int* Cards){
    BlackJack Jack;
    int a = Cards[Jack.RandomCard()];
    int b = Cards[Jack.RandomCard()];
    char c;
    std::cout << "Dealer's cards " << a << " " << b << "" << "("
    << a + b << ")" << endl;
    if((a + b) > 21){
        std::cout << "You are lose";
        return 0;
    }
    else if(a == 11 || b == 11){
        std::cout << "Invert 11 to 1 or not? (y/n)";
        std::cin >> c;
        if(c = 'y' && a == 11) a = 1;
        else if(c = 'y' && b == 11) b = 1;
        else if(c = 'n' && a == 11) a = 11;
        else if(c = 'n' && b == 11) b = 11;
    }
    else if(a == 11 && b == 10 || a == 10 && b == 11){
        Dealer deal;
        int price;
        std::cout << "You have BlakcJack" << endl;
        price = deal.getBet() * 1.5;
        deal.IncreaseMoney(price);
    }
}

