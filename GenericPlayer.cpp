#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;




class Card{
public:
    enum suit{
        HEARTS,
        DIAMONDS,
        CLUBS,
        SPADES
    };
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
    };
    Card(suit a, Rank b, bool CardsPos = 0)
    :m_Suit(a), m_Rank(b), CardsPos(CardsPos)
    {}
    void Flip(){
    CardsPos = !(CardsPos);
    }

    int GetValue() const{
        int value = 0;
        if (CardsPos){
            value = m_Rank;
            if (value > 10){
                value = 10;
            }
        }
        return value;
    }
    friend ostream& operator<<(ostream& os, const Card& aCard);
private:
    suit m_Suit;
    Rank m_Rank;
    bool CardsPos;
};

class Hand{
protected:
    vector<Card*> m_inHand;
public:
    Hand(vector<Card*> inHand)
    :m_inHand(inHand){}

    virtual ~Hand();
    void Add(Card* p){
        m_inHand.push_back(p);
    }

    void Clear(){
        m_inHand.clear();
        m_inHand.shrink_to_fit();
    }

    int GetTotal()const{
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
    friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);
public:
    GenericPlayer(const string& name = "");

    virtual ~GenericPlayer();

    virtual bool IsHitting() const = 0;

    bool IsBoosted()const{
        if(GetTotal() > 21) return 1;
        else return 0;}

    void Bust()const{
        if(IsBoosted() == true) cout << m_name << " busts.\n";
    }
    string m_name;
};

ostream& operator<<(ostream& os, const Card& aCard)
{
    const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
    const string SUITS[] = { "c", "d", "h", "s" };

    if (aCard.CardsPos)
    {
        os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
    }
    else
    {
        os << "XX";
    }

    return os;
}

ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer)
{
    os << aGenericPlayer.m_name << ":\t";

    vector<Card*>::const_iterator pCard;
    if (!aGenericPlayer.m_inHand.empty())
    {
        for (pCard = aGenericPlayer.m_inHand.begin();
             pCard != aGenericPlayer.m_inHand.end();
             ++pCard)
        {
            os << *(*pCard) << "\t";
        }


        if (aGenericPlayer.GetTotal() != 0)
        {
            cout << "(" << aGenericPlayer.GetTotal() << ")";
        }
    }
    else
    {
        os << "<empty>";
    }

    return os;
}

class Player : public GenericPlayer
{
public:
    Player(const string& name = "");

    virtual ~Player();

    virtual bool IsHitting() const{
        cout << m_name << ", do you want a hit? (Y/N): ";
        char response;
        cin >> response;
        return (response == 'y' || response == 'Y');
    }
    void Win() const{
        cout << m_name << " wins.\n";
    }
    void Lose() const{
        cout << m_name << " loses.\n";
    }
    void Push() const{
        cout << m_name << " pushes.\n";
    }
};

class House : public GenericPlayer
{
public:
    House(const string& name = "House");

    virtual ~House();

    virtual bool IsHitting() const{
        return (GetTotal() <= 16);
    }
    void FlipFirstCard(){
        if (!(m_inHand.empty()))
        {
            m_inHand[0]->Flip();
        }
        else
        {
            cout << "No card to flip!\n";
        }
    }
};



int main(){
    return 0;
}
