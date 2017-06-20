//
// Created by zzang on 2017-06-08.
//

#ifndef CONNECT_H
#define CONNECT_H
#include <iostream>
#include <string>

using namespace std;

class connect
{
public:
    connect();
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
    void systemchec();
    //ai//
    void placeAiPiece (int a, int b);
    void placeHumanPiece (int a, int b);

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
    string index; string right1; string right2; string right3; string left1; string left2; string left3; string up1; string up2; string up3; string down1; string down2; string down3;
    string crossupright1; string crossupright2; string crossupright3; string crossupleft1; string crossupleft2; string crossupleft3; string crossdownright1; string crossdownright2;
    string crossdownright3; string crossdownleft1; string crossdownleft2; string crossdownleft3;
    int ggwho;

    int system1; int system2; int system3; int system4; int system5; int system6; int system7; int system8;
    bool playerr;
    int winningp1=0; int winningp2=0; int winningp3=0; int winningp4=0; int winningp5=0; int winningp6=0; int winningp7=0; int winningp8=0;

    int runAi();
};

#endif // CONNECT_H

