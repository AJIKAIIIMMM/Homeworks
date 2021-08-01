#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Card{
    enum suit{
        HEARTS,
        DIAMONDS,
        CLUBS,
        SPADES
    }SuitsField;
    enum Rank{
        TWO = 2,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK = 10,
        QUEEN = 10,
        KING = 10,
        ACE = 11
    }CardsRank;
    bool CardsPos;
public:
    Card(suit a, Rank b, bool CardsPos = 0)
    :SuitsField(a), CardsRank(b), CardsPos(CardsPos)
    {}
    void Flip(){
        if(CardsPos == 0){
            CardsPos = 1;
            std::cout << "The card was fliped" << std::endl;
        }else std::cout << "There is nothing to flip" << std::endl;
    }
    Rank GetValue()const {return CardsRank;}
};

class Hand{
    vector<Card*> m_inHand;
public:
    Hand(vector<Card*> inHand)
    :m_inHand(inHand){}

    void Add(Card* p){
        m_inHand.push_back(p);
    }

    void Clear(){
        m_inHand.clear();
        m_inHand.shrink_to_fit();
    }

    int GetValue()const{
        auto iter = m_inHand.begin();
        int sum = 0;
        while(iter != m_inHand.end()){
            int i = 0;
            sum = sum + (*iter)->GetValue();
            ++iter;
            if((*iter)->GetValue() == 11){
                ++i;
            }
            if(i > 0 && sum > 21){
                sum -= 10;
            }
        }
        return sum;}
    virtual void IsHitting(){
        char c;
        cout << "Do you need another one card? y/n";
        cin >> c;
        while(c == 'y') /*вызов функции с рандомайзером и добавление карты в функцию Add*/;
    }
};

class GenericPlayer:public Hand{
    string m_name;
public:
    GenericPlayer(vector<Card*> inHand, string name)
    :Hand (inHand), m_name(name)
    {}
    bool IsBoosted(){
        if(GetValue() > 21) return 1;
        else return 0;}
    void Bust(){
        if(IsBoosted() == true) cout << "The hand of " << m_name << "is overflowed" << endl;
    }
};

int main(){
    return 0;
}
