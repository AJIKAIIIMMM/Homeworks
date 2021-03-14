#include <iostream>
#include <fstream>
#include <stdio.h>
#include <io.h>
#include <string>
#include <FunctionJoin.h>

using namespace std;

void JoinerFunc ();

bool SearchingFunc(string Word, string File);

int main()
{
    string Word, File;
    ofstream FF1 ("FirstFile.txt");
    FF1 << "But I must explain to you how all this mistaken idea of denouncing pleasure and praising pain was born and I will give you a complete account of the system, ";
    FF1.close();
    ofstream FF2 ("SecondFile.txt");
    FF2 << "and expound the actual teachings of the great explorer of the truth, the master-builder of human happiness.";
    FF2.close();
    JoinerFunc();
    cout << "Enter the word:";
    cin >> Word;
    cout << "Enter the file name:";
    cin >> File;
    SearchingFunc(Word, File);
    return 0;
}

