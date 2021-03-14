#ifndef FUNCTIONJOIN_H_INCLUDED
#define FUNCTIONJOIN_H_INCLUDED

using namespace std;

void JoinerFunc (){
    string *firstpart = new string;
    string *secondpart = new string;
    fstream Check("MainFile.txt");
    if (Check.peek() == EOF){
        ifstream fp ("FirstFile.txt");
        while(getline(fp, *firstpart)){
            cout << *firstpart << endl;
        }
        fp.close();
        ifstream sp ("SecondFile.txt");
        while(getline(sp, *secondpart)){
            cout << *secondpart << endl;
        }
        sp.close();
        ofstream FF3 ("MainFile.txt", ofstream::app);
        FF3 << *firstpart << *secondpart;
        FF3.close();
    } else {
        cout << "File is fill" << endl;
    }
}

bool SearchingFunc (string Word, string File){
    string Line;
    int p;
    ifstream Search (File);
    while(!Search.eof()){
        getline (Search, Line);
    }
    Line.find(Word);
    p = Line.find(Word);
    cout << p;
    if(p >= 0){
        cout << "The word is inside.";
    } else {
        cout << "There is nothing.";
    }
    Search.close();
}
#endif // FUNCTIONJOIN_H_INCLUDED
