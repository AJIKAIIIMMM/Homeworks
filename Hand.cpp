#include <iostream>
#include <vector>

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
    void Flip(bool Pos){
        if(Pos == 0){
            Pos = 1;
            std::cout << "The card was fliped" << std::endl;
        }else std::cout << "There is nothing to flip" << std::endl;
    }
    Rank GetValue()const {while(ACE == 1) return CardsRank;}
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
    }

    Hand GetValue()const{
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
    }
};

int main(){
    return 0;
}
