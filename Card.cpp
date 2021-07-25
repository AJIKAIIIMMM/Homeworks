#include <iostream>

using namespace std;

class Card{
    enum suit{
        HEARTS,
        DIAMONDS,
        CLUBS,
        SPADES
    }SuitsField;
    enum cards{
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
        ACE = 1
    }CardsField;
    bool CardsPos;
public:
    Card(suit a, cards b, bool CardsPos = 0)
    :SuitsField(a), CardsField(b), CardsPos(CardsPos)
    {}
    void Flip(bool Pos){
        if(Pos == 0){
            Pos = 1;
            std::cout << "The card was fliped" << std::endl;
        }else std::cout << "There is nothing to flip" << std::endl;
    }
    cards GetValue()const {while(ACE == 1) return CardsField;}
};

int main(){
    return 0;
}
