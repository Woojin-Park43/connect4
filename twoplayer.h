//
// Created by zzang on 2017-06-14.
//

#ifndef SCHOOL_TWOPLAYER_H
#define SCHOOL_TWOPLAYER_H
#include <iostream>
using namespace std;

class twoplayer {
public:
    twoplayer();
    void mov(int a);
    void checker(int b);
    void row(int c);
    void getridofrow(int c);
    void AI(int c);
    void Validmove();
    void check3(int c, int d);
    void endgame();
    bool stop=true;
    bool gg=true;
private:
    string player1="o"; string player2="x";
    string board[8][8]={{" "," "," "," "," "," "," ", " "},
                        {" "," "," "," "," "," "," ", " "},
                        {" "," "," "," "," "," "," ", " "},
                        {" "," "," "," "," "," "," ", " "},
                        {" "," "," "," "," "," "," ", " "},
                        {" "," "," "," "," "," "," ", " "},
                        {" "," "," "," "," "," "," ", " "},
                        {" "," "," "," "," "," "," ", " "}};
    bool valid=true;
    int firstcolumn=8; int secondcolumn=8; int thirdcolumn=8; int fourthcolumn=8; int fifthcolumn=8; int sixthcolumn=8; int seventhcolumn=8; int eightcolumn=8;
    int setrow;
    int AImove;
    int check3move;
    string player; bool playerr=true;
    string index; string right1; string right2; string right3; string left1; string left2; string left3; string down1; string down2; string down3;
    string crossupright1; string crossupright2; string crossupright3; string crossupleft1; string crossupleft2; string crossupleft3; string crossdownright1; string crossdownright2;
    string crossdownright3; string crossdownleft1; string crossdownleft2; string crossdownleft3;
    int ggwho;
};


#endif //SCHOOL_TWOPLAYER_H
