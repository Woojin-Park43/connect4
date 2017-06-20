//3

// Created by zzang on 2017-06-08.
//
#define _GLIBCXX_DEBUG
#include <iostream>
using namespace std;
#include "connect.h"
#include "easy.h"
#include "medium.h"
#include "leaderboard.h"
#include "twoplayer.h"
#include <fstream>
#include <string>
#include "Account.h"

int main (void) {

    //player's option
    int hard;
    int playerturn;
    int aiorplayer;
    string name;
    bool game = true;
    int twoplayer123=0;
    bool which=true;
    string endgame = "q";
    string veryfirst;
    string entiregame;
    string playername1;
    string playername2;

    while (entiregame!= endgame) {
        cout << endl;
        cout << "Welcome users this is a connect four game in 8 by 8 board" << endl;
        cout << "The way you play this game is press number between 1 to 8 when the board appears" << endl;
        cout << "press 1 if you want to play with a player and press 2 to see the leaderboard and press any other  number key if you want to play with AI" << endl;

        cin >> aiorplayer;
        if (aiorplayer == 1) {
            twoplayer ob5;
            while (game) {
                if (which) {
                    cin >> playerturn;
                    ob5.mov(playerturn);
                    if (ob5.gg == false) {
                        game = false;
                        twoplayer123 = 1;
                    }
                } else {
                    cin >> playerturn;
                    ob5.mov(playerturn);
                    if (ob5.gg == false) {
                        game = false;
                        twoplayer123 = 2;
                    }
                }

                which = !which;

                cout << endl;
                if (twoplayer123 == 1)
                    cout << "player 1 win" << endl;
                else if (twoplayer123 == 2)
                    cout << "player 2 win" << endl;
            }

            twoplayer123 = 0;
            game = true;
            which = true;
        }
            else if (aiorplayer==2) {
            //creates a file object
            fstream file;
            file.open("accountsAndScore.txt");
            while(!file){
                if(!file){
                    std::ofstream blank_file("accountsAndScore.txt", ios::out|ios::binary);
                    blank_file.close();
                    std::fstream blank_file2("accountsAndScore.txt", ios::out|ios::in|ios::binary);
                    fileCreator(blank_file2);
                }
                file.open("accountsAndScore.txt");
            }

        }
        else {

            cout << "enter your name" << endl;
            cin >> name;
            cout << "press any keys if you want to continue and press q if you want to exit the game" << endl;
            cin >> veryfirst;

            while (veryfirst != endgame) {

                cout << endl;
                cout << "Choose your level" << endl;
                cout << "3---hard" << endl;
                cout << "2---medium" << endl;
                cout << "1---easy" << endl;
                cin >> hard;

                if (hard == 3) {
                    connect ob1;
                    while (game) {
                        cin >> playerturn;
                        ob1.mov(playerturn);
                        if (ob1.gg == false)
                            game = false;
                    }
                } else if (hard == 2) {
                    medium ob2;
                    while (game) {
                        cin >> playerturn;
                        ob2.mov(playerturn);
                        if (ob2.gg == false)
                            game = false;
                    }
                } else {
                    easy ob3;
                    while (game) {
                        cin >> playerturn;
                        ob3.mov(playerturn);
                        if (ob3.gg == false)
                            game = false;
                    }
                }
                cout << "type in q if you want to exit the game type l if you want to play again" << endl;
                cin >> veryfirst;
                game = true;
            }
            cout << "click q to end the entire game and press any keys to play the game again!!!" << endl;
            cin >> entiregame;
        }
    }
}