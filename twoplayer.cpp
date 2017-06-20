//
// Created by zzang on 2017-06-14.
//

#include "twoplayer.h"

//
// Created by zzang on 2017-06-08.
//

using namespace std;

//display the maze at the beginning of the game
twoplayer::twoplayer() {
    for (int a=0; a<8; a++) {
        cout<< "|";
        for (int b = 0; b < 8; b++)
            cout << board[b][a] << "|";
        cout << endl;
    }
    cout << endl;
}

//check if the move is valid
void twoplayer::checker(int b) {
    if (b>8)
        valid=false;
    else if(b<1)
        valid=false;
    else if(b==1&&firstcolumn==0)
        valid=false;
    else if(b==2&&secondcolumn==0)
        valid=false;
    else if(b==3&&thirdcolumn==0)
        valid=false;
    else if(b==4&&fourthcolumn==0)
        valid=false;
    else if(b==5&&fifthcolumn==0)
        valid=false;
    else if(b==6&&sixthcolumn==0)
        valid=false;
    else if(b==7&&seventhcolumn==0)
        valid=false;
    else if(b==8&& eightcolumn==0)
        valid= false;
    else
        valid=true;
}

//identify which row the player is in
void twoplayer::row(int c) {
    switch (c) {
        case 1 : { setrow=firstcolumn; } break;
        case 2 : { setrow=secondcolumn; } break;
        case 3 : { setrow=thirdcolumn; } break;
        case 4 : { setrow=fourthcolumn; } break;
        case 5 : { setrow=fifthcolumn; } break;
        case 6 : { setrow=sixthcolumn; } break;
        case 7 : { setrow=seventhcolumn; } break;
        case 8 : {setrow=eightcolumn;} break;
    }
}

//getrid of the row every time the player make a move
void twoplayer::getridofrow(int c) {
    switch (c) {
        case 1 : { firstcolumn--; } break;
        case 2 : { secondcolumn--; } break;
        case 3 : { thirdcolumn--; } break;
        case 4 : { fourthcolumn--; } break;
        case 5 : { fifthcolumn--; } break;
        case 6 : { sixthcolumn--; } break;
        case 7 : { seventhcolumn--; } break;
        case 8 : { eightcolumn--;} break;
    }
}

void twoplayer::mov(int a) {
    if (gg) {
        checker(a);
        //player 1 turn
        if (valid) {

            if (playerr)
                player= "o";
            else
                player="x";

            row(a);
            board[a - 1][setrow - 1] = player;
            check3(a, setrow);
            endgame();
            getridofrow(a);
            ggwho = 1;
            index = " ";
            right1 = " ";
            right2 = " ";
            right3 = " ";
            left1 = " ";
            left2 = " ";
            left3 = " ";
            down1 = " ";
            down2 = " ";
            down3 = " ";
            crossupright1 = " ";
            crossupright2 = " ";
            crossupright3 = " ";
            crossupleft1 = " ";
            crossupleft2 = " ";
            crossupleft3 = " ";
            crossdownright1 = " ";
            crossdownright2 = " ";
            crossdownright3 = " ";
            crossdownleft1 = " ";
            crossdownleft2 = " ";
            crossdownleft3 = " ";


            for (int w = 0; w < 8; w++) {
                cout << "|";
                for (int e = 0; e < 8; e++)
                    cout << board[e][w] << "|";
                cout << endl;

            }
            playerr= !playerr;
        }
    }
}

//checks if the game end
void twoplayer::endgame() {
    if (index==right1&&index==right2&&index==right3) {
        gg = false;
        stop = false;
    }
    else if (index==right1&&index==right2&&index==left1) {
        gg = false;
        stop = false;
    }
    else if (index==right1&&index==left2&&index==left1) {
        gg = false;
        stop = false;
    }
    else if (index==left1&&index==left2&&index==left3) {
        gg = false;
        stop = false;
    }
    else if (index==crossupright1&&index==crossupright2&&index==crossupright3) {
        gg = false;
        stop = false;
    }
    else if (index==crossupright1&&index==crossupright2&&index==crossdownleft1) {
        gg = false;
        stop = false;
    }
    else if (index==crossupright1&&index==crossdownleft2&&index==crossdownleft1) {
        gg = false;
        stop = false;
    }
    else if (index==crossupleft1&&index==crossupleft2&&index==crossupleft3) {
        gg = false;
        stop = false;
    }
    else if (index==crossdownleft1&&index==crossdownleft2&&index==crossdownleft3) {
        gg = false;
        stop = false;
    }
    else if (index==crossupleft1&&index==crossupleft2&&index==crossupleft3) {
        gg = false;
        stop = false;
    }
    else if (index==crossupleft1&&index==crossupleft2&&index==crossdownright1) {
        gg = false;
        stop = false;
    }
    else if (index==crossupleft1&&index==crossdownright1&&index==crossdownright2) {
        gg = false;
        stop = false;
    }
    else if (index==crossdownright3&&index==crossdownright1&&index==crossdownright2) {
        gg = false;
        stop = false;
    }
    else if (index==down1&&index==down2&&index==down3) {
        gg = false;
        stop = false;
    }
    else {
        gg = true;
    }
}

//AI move
void twoplayer::AI(int c) {
    AImove=c;
}

//check if the three pices are the same
void twoplayer::check3(int c, int d) {
    index = board[c - 1][d - 1];
    //first 9 columns and rows on the left side
    if (c == 1 && d > 7) {
        right1 = board[c][7];
        right2 = board[c + 1][7];
        right3 = board[c + 2][7];
        crossupright1 = board[c][6];
        crossupright2 = board[c + 1][5];
        crossupright3 = board[c + 2][4];
    } else if (c == 1 && d > 6) {
        right1 = board[c][6];
        right2 = board[c + 1][6];
        right3 = board[c + 2][6];
        crossupright1 = board[c][5];
        crossupright2 = board[c + 1][4];
        crossupright3 = board[c + 2][3];
    } else if (c == 1 && d > 5) {
        right1 = board[c][5];
        right2 = board[c + 1][5];
        right3 = board[c + 2][5];
        crossupright1 = board[c][4];
        crossupright2 = board[c + 1][3];
        crossupright3 = board[c + 2][2];
    } else if (c == 2 && d > 7) {
        right1 = board[c][7];
        right2 = board[c + 1][7];
        right3 = board[c + 2][7];
        left1 = board[c - 2][7];
        crossupright1 = board[c][6];
        crossupright2 = board[c + 1][5];
        crossupright3 = board[c + 2][4];
    } else if (c == 2 && d > 6) {
        right1 = board[c][6];
        right2 = board[c + 1][6];
        right3 = board[c + 2][6];
        left1 = board[c - 2][6];
        crossupright1 = board[c][5];
        crossupright2 = board[c + 1][4];
        crossupright3 = board[c + 2][3];
        crossdownleft1 = board[c - 2][7];
    } else if (c == 2 && d > 5) {
        right1 = board[c][5];
        right2 = board[c + 1][5];
        right3 = board[c + 2][5];
        left1 = board[c - 2][5];
        crossupright1 = board[c][4];
        crossupright2 = board[c + 1][3];
        crossupright3 = board[c + 2][2];
        crossdownleft1 = board[c - 2][6];
    } else if (c == 3 && d > 7) {
        right1 = board[c][7];
        right2 = board[c + 1][7];
        right3 = board[c + 2][7];
        left1 = board[c - 2][7];
        left2 = board[c - 3][7];
        crossupright1 = board[c][6];
        crossupright2 = board[c + 1][5];
        crossupright3 = board[c + 2][4];
    } else if (c == 3 && d > 6) {
        right1 = board[c][6];
        right2 = board[c + 1][6];
        right3 = board[c + 2][6];
        left1 = board[c - 2][6];
        left2 = board[c - 3][6];
        crossupright1 = board[c][5];
        crossupright2 = board[c + 1][4];
        crossupright3 = board[c + 2][3];
        crossdownleft1 = board[c - 2][7];
    } else if (c == 3 && d > 5) {
        right1 = board[c][5];
        right2 = board[c + 1][5];
        right3 = board[c + 2][5];
        left1 = board[c - 2][5];
        left2 = board[c - 3][5];
        crossupright1 = board[c][4];
        crossupright2 = board[c + 1][3];
        crossupright3 = board[c + 2][2];
        crossdownleft1 = board[c - 2][6];
        crossdownleft2 = board[c - 3][7];
    } else if (c == 4 && d > 7) {
        right1 = board[c][7];
        right2 = board[c + 1][7];
        right3 = board[c + 2][7];
        left1 = board[c - 2][7];
        left2 = board[c - 3][7];
        left3 = board[c - 4][7];
        crossupright1 = board[c][6];
        crossupright2 = board[c + 1][5];
        crossupright3 = board[c + 2][4];
        crossupleft1 = board[c - 2][6];
        crossupleft2 = board[c - 3][5];
        crossupleft3 = board[c - 4][4];
    } else if (c == 4 && d > 6) {
        right1 = board[c][6];
        right2 = board[c + 1][6];
        right3 = board[c + 2][6];
        left1 = board[c - 2][6];
        left2 = board[c - 3][6];
        left3 = board[c - 4][6];
        crossupright1 = board[c][5];
        crossupright2 = board[c + 1][4];
        crossupright3 = board[c + 2][3];
        crossupleft1 = board[c - 2][5];
        crossupleft2 = board[c - 3][4];
        crossupleft3 = board[c - 4][3];
        crossdownleft1 = board[c - 2][7];
        crossdownright1 = board[c][7];
    } else if (c == 4 && d > 5) {
        right1 = board[c][5];
        right2 = board[c + 1][5];
        right3 = board[c + 2][5];
        left1 = board[c - 2][5];
        left2 = board[c - 3][5];
        left3 = board[c - 4][5];
        crossupright1 = board[c][4];
        crossupright2 = board[c + 1][3];
        crossupright3 = board[c + 2][2];
        crossupleft1 = board[c - 2][4];
        crossupleft2 = board[c - 3][3];
        crossupleft3 = board[c - 4][2];
        crossdownleft1 = board[c - 2][6];
        crossdownleft2 = board[c - 3][7];
        crossdownright1 = board[c][6];
        crossdownright2 = board[c + 1][7];
    } else if (c == 5 && d > 7) {
        right1 = board[c][7];
        right2 = board[c + 1][7];
        right3 = board[c + 2][7];
        left1 = board[c - 2][7];
        left2 = board[c - 3][7];
        left3 = board[c - 4][7];
        crossupright1 = board[c][6];
        crossupright2 = board[c + 1][5];
        crossupright3 = board[c + 2][4];
        crossupleft1 = board[c - 2][6];
        crossupleft2 = board[c - 3][5];
        crossupleft3 = board[c - 4][4];
    } else if (c == 5 && d > 6) {
        right1 = board[c][6];
        right2 = board[c + 1][6];
        right3 = board[c + 2][6];
        left1 = board[c - 2][6];
        left2 = board[c - 3][6];
        left3 = board[c - 4][6];
        crossupright1 = board[c][5];
        crossupright2 = board[c + 1][4];
        crossupright3 = board[c + 2][3];
        crossupleft1 = board[c - 2][5];
        crossupleft2 = board[c - 3][4];
        crossupleft3 = board[c - 4][3];
        crossdownleft1 = board[c - 2][7];
        crossdownright1 = board[c][7];
    } else if (c == 5 && d > 5) {
        right1 = board[c][5];
        right2 = board[c + 1][5];
        right3 = board[c + 2][5];
        left1 = board[c - 2][5];
        left2 = board[c - 3][5];
        left3 = board[c - 4][5];
        crossupright1 = board[c][4];
        crossupright2 = board[c + 1][3];
        crossupright3 = board[c + 2][2];
        crossupleft1 = board[c - 2][4];
        crossupleft2 = board[c - 3][3];
        crossupleft3 = board[c - 4][2];
        crossdownleft1 = board[c - 2][6];
        crossdownleft2 = board[c - 3][7];
        crossdownright1 = board[c][6];
        crossdownright2 = board[c + 1][7];
    } else if (c == 6 && d > 7) {
        right1 = board[c][7];
        right2 = board[c + 1][7];
        left1 = board[c - 2][7];
        left2 = board[c - 3][7];
        left3 = board[c - 4][7];
        crossupleft1 = board[c - 2][6];
        crossupleft2 = board[c - 3][5];
        crossupleft3 = board[c - 4][4];
    } else if (c == 6 && d > 6) {
        right1 = board[c][6];
        right2 = board[c + 1][6];
        left1 = board[c - 2][6];
        left2 = board[c - 3][6];
        left3 = board[c - 4][6];
        crossupleft1 = board[c - 2][5];
        crossupleft2 = board[c - 3][4];
        crossupleft3 = board[c - 4][3];
        crossdownleft1 = board[c - 2][7];
        crossdownright1 = board[c][7];
    } else if (c == 6 && d > 5) {
        right1 = board[c][5];
        right2 = board[c + 1][5];
        left1 = board[c - 2][5];
        left2 = board[c - 3][5];
        left3 = board[c - 4][5];
        crossupleft1 = board[c - 2][4];
        crossupleft2 = board[c - 3][3];
        crossupleft3 = board[c - 4][2];
        crossdownleft1 = board[c - 2][6];
        crossdownleft2 = board[c - 3][7];
        crossdownright1 = board[c][6];
        crossdownright2 = board[c + 1][7];
    } else if (c == 7 && d > 7) {
        right1 = board[c][7];
        left1 = board[c - 2][7];
        left2 = board[c - 3][7];
        left3 = board[c - 4][7];
        crossupleft1 = board[c - 2][6];
        crossupleft2 = board[c - 3][5];
        crossupleft3 = board[c - 4][4];
    } else if (c == 7 && d > 6) {
        right1 = board[c][6];
        left1 = board[c - 2][6];
        left2 = board[c - 3][6];
        left3 = board[c - 4][6];
        crossupleft1 = board[c - 2][5];
        crossupleft2 = board[c - 3][4];
        crossupleft3 = board[c - 4][3];
        crossdownright1 = board[c][6];
    } else if (c == 7 && d > 5) {
        right1 = board[c][5];
        left1 = board[c - 2][5];
        left2 = board[c - 3][5];
        left3 = board[c - 4][5];
        crossupleft1 = board[c - 2][4];
        crossupleft2 = board[c - 3][3];
        crossupleft3 = board[c - 4][2];
        crossdownleft1 = board[c - 2][6];
        crossdownleft2 = board[c - 3][7];
        crossdownright1 = board[c][6];
    } else if (c == 8 && d > 7) {
        left1 = board[c - 2][7];
        left2 = board[c - 3][7];
        left3 = board[c - 4][7];
        crossupleft1 = board[c - 2][6];
        crossupleft2 = board[c - 3][5];
        crossupleft3 = board[c - 4][4];
    } else if (c == 8 && d > 6) {
        left1 = board[c - 2][6];
        left2 = board[c - 3][6];
        left3 = board[c - 4][6];
        crossupleft1 = board[c - 2][5];
        crossupleft2 = board[c - 3][4];
        crossupleft3 = board[c - 4][3];
    } else if (c == 8 && d > 5) {
        left1 = board[c - 2][5];
        left2 = board[c - 3][5];
        left3 = board[c - 4][5];
        crossupleft1 = board[c - 2][4];
        crossupleft2 = board[c - 3][3];
        crossupleft3 = board[c - 4][2];
    }

        //The 5th and the 4th column
    else if (c == 1 && d > 4) {
        right1 = board[c][4];
        right2 = board[c + 1][4];
        right3 = board[c + 2][4];
        down1 = board[c - 1][5];
        down2 = board[c - 1][6];
        down3 = board[c - 1][7];
        crossupright1 = board[c][3];
        crossupright2 = board[c + 1][2];
        crossupright3 = board[c + 2][1];
        crossdownright1 = board[c][5];
        crossdownright2 = board[c + 1][6];
        crossdownright3 = board[c + 2][7];
    } else if (c == 1 && d > 3) {
        right1 = board[c][3];
        right2 = board[c + 1][3];
        right3 = board[c + 2][3];
        down1 = board[c - 1][4];
        down2 = board[c - 1][5];
        down3 = board[c - 1][6];
        crossupright1 = board[c][2];
        crossupright2 = board[c + 1][1];
        crossupright3 = board[c + 2][0];
        crossdownright1 = board[c][4];
        crossdownright2 = board[c + 1][5];
        crossdownright3 = board[c + 2][6];
    } else if (c == 2 && d > 4) {
        right1 = board[c][4];
        right2 = board[c + 1][4];
        right3 = board[c + 2][4];
        left1 = board[c - 2][4];
        down1 = board[c - 1][5];
        down2 = board[c - 1][6];
        down3 = board[c - 1][7];
        crossupright1 = board[c][3];
        crossupright2 = board[c + 1][2];
        crossupright3 = board[c + 2][1];
        crossdownright1 = board[c][5];
        crossdownright2 = board[c + 1][6];
        crossdownright3 = board[c + 2][7];
    } else if (c == 2 && d > 3) {
        right1 = board[c][3];
        right2 = board[c + 1][3];
        right3 = board[c + 2][3];
        left1 = board[c - 2][3];
        down1 = board[c - 1][4];
        down2 = board[c - 1][5];
        down3 = board[c - 1][6];
        crossupright1 = board[c][2];
        crossupright2 = board[c + 1][1];
        crossupright3 = board[c + 2][0];
        crossdownright1 = board[c][4];
        crossdownright2 = board[c + 1][5];
        crossdownright3 = board[c + 2][6];
    } else if (c == 3 && d > 4) {
        right1 = board[c][4];
        right2 = board[c + 1][4];
        right3 = board[c + 2][4];
        left1 = board[c - 2][4];
        left2 = board[c - 3][4];
        down1 = board[c - 1][5];
        down2 = board[c - 1][6];
        down3 = board[c - 1][7];
        crossupright1 = board[c][3];
        crossupright2 = board[c + 1][2];
        crossupright3 = board[c + 2][1];
        crossdownright1 = board[c][5];
        crossdownright2 = board[c + 1][6];
        crossdownright3 = board[c + 2][7];
    } else if (c == 3 && d > 3) {
        right1 = board[c][3];
        right2 = board[c + 1][3];
        right3 = board[c + 2][3];
        left1 = board[c - 2][3];
        left2 = board[c - 3][3];
        down1 = board[c - 1][4];
        down2 = board[c - 1][5];
        down3 = board[c - 1][6];
        crossupright1 = board[c][2];
        crossupright2 = board[c + 1][1];
        crossupright3 = board[c + 2][0];
        crossdownright1 = board[c][4];
        crossdownright2 = board[c + 1][5];
        crossdownright3 = board[c + 2][6];
    } else if (c == 4 && d > 4) {
        right1 = board[c][4];
        right2 = board[c + 1][4];
        right3 = board[c + 2][4];
        left1 = board[c - 2][4];
        left2 = board[c - 3][4];
        left3 = board[c - 4][4];
        down1 = board[c - 1][5];
        down2 = board[c - 1][6];
        down3 = board[c - 1][7];
        crossupright1 = board[c][3];
        crossupright2 = board[c + 1][2];
        crossupright3 = board[c + 2][1];
        crossdownright1 = board[c][5];
        crossdownright2 = board[c + 1][6];
        crossdownright3 = board[c + 2][7];
        crossupleft1 = board[c - 2][3];
        crossupleft2 = board[c - 3][2];
        crossupleft3 = board[c - 4][1];
        crossdownleft1 = board[c - 2][5];
        crossdownleft2 = board[c - 3][6];
        crossdownleft3 = board[c - 4][7];
    } else if (c == 4 && d > 3) {
        right1 = board[c][3];
        right2 = board[c + 1][3];
        right3 = board[c + 2][3];
        left1 = board[c - 2][3];
        left2 = board[c - 3][3];
        left3 = board[c - 4][3];
        down1 = board[c - 1][4];
        down2 = board[c - 1][5];
        down3 = board[c - 1][6];
        crossupright1 = board[c][2];
        crossupright2 = board[c + 1][1];
        crossupright3 = board[c + 2][0];
        crossdownright1 = board[c][4];
        crossdownright2 = board[c + 1][5];
        crossdownright3 = board[c + 2][6];
        crossupleft1 = board[c - 2][2];
        crossupleft2 = board[c - 3][1];
        crossupleft3 = board[c - 4][0];
        crossdownleft1 = board[c - 2][4];
        crossdownleft2 = board[c - 3][5];
        crossdownleft3 = board[c - 4][6];
    } else if (c == 5 && d > 4) {
        right1 = board[c][4];
        right2 = board[c + 1][4];
        right3 = board[c + 2][4];
        left1 = board[c - 2][4];
        left2 = board[c - 3][4];
        left3 = board[c - 4][4];
        down1 = board[c - 1][5];
        down2 = board[c - 1][6];
        down3 = board[c - 1][7];
        crossupright1 = board[c][3];
        crossupright2 = board[c + 1][2];
        crossupright3 = board[c + 2][1];
        crossdownright1 = board[c][5];
        crossdownright2 = board[c + 1][6];
        crossdownright3 = board[c + 2][7];
        crossupleft1 = board[c - 2][3];
        crossupleft2 = board[c - 3][2];
        crossupleft3 = board[c - 4][1];
        crossdownleft1 = board[c - 2][5];
        crossdownleft2 = board[c - 3][6];
        crossdownleft3 = board[c - 4][7];
    } else if (c == 5 && d > 3) {
        right1 = board[c][3];
        right2 = board[c + 1][3];
        right3 = board[c + 2][3];
        left1 = board[c - 2][3];
        left2 = board[c - 3][3];
        left3 = board[c - 4][3];
        down1 = board[c - 1][4];
        down2 = board[c - 1][5];
        down3 = board[c - 1][6];
        crossupright1 = board[c][2];
        crossupright2 = board[c + 1][1];
        crossupright3 = board[c + 2][0];
        crossdownright1 = board[c][4];
        crossdownright2 = board[c + 1][5];
        crossdownright3 = board[c + 2][6];
        crossupleft1 = board[c - 2][2];
        crossupleft2 = board[c - 3][1];
        crossupleft3 = board[c - 4][0];
        crossdownleft1 = board[c - 2][4];
        crossdownleft2 = board[c - 3][5];
        crossdownleft3 = board[c - 4][6];
    } else if (c == 6 && d > 4) {
        right1 = board[c][4];
        right2 = board[c + 1][4];
        left1 = board[c - 2][4];
        left2 = board[c - 3][4];
        left3 = board[c - 4][4];
        down1 = board[c - 1][5];
        down2 = board[c - 1][6];
        down3 = board[c - 1][7];
        crossupleft1 = board[c - 2][3];
        crossupleft2 = board[c - 3][2];
        crossupleft3 = board[c - 4][1];
        crossdownleft1 = board[c - 2][5];
        crossdownleft2 = board[c - 3][6];
        crossdownleft3 = board[c - 4][7];
    } else if (c == 6 && d > 3) {
        right1 = board[c][3];
        right2 = board[c + 1][3];
        left1 = board[c - 2][3];
        left2 = board[c - 3][3];
        left3 = board[c - 4][3];
        down1 = board[c - 1][4];
        down2 = board[c - 1][5];
        down3 = board[c - 1][6];
        crossupleft1 = board[c - 2][2];
        crossupleft2 = board[c - 3][1];
        crossupleft3 = board[c - 4][0];
        crossdownleft1 = board[c - 2][4];
        crossdownleft2 = board[c - 3][5];
        crossdownleft3 = board[c - 4][6];
    } else if (c == 7 && d > 4) {
        right1 = board[c][4];
        right2 = board[c + 1][4];
        down1 = board[c - 1][5];
        down2 = board[c - 1][6];
        down3 = board[c - 1][7];
        crossupright1 = board[c][3];
        crossupright2 = board[c + 1][2];
        crossupright3 = board[c + 2][1];
        crossdownright1 = board[c][5];
        crossdownright2 = board[c + 1][6];
        crossdownright3 = board[c + 2][7];
    } else if (c == 7 && d > 3) {
        right1 = board[c][3];
        right2 = board[c + 1][3];
        down1 = board[c - 1][4];
        down2 = board[c - 1][5];
        down3 = board[c - 1][6];
        crossupright1 = board[c][2];
        crossupright2 = board[c + 1][1];
        crossupright3 = board[c + 2][0];
        crossdownright1 = board[c][4];
        crossdownright2 = board[c + 1][5];
        crossdownright3 = board[c + 2][6];
    } else if (c == 8 && d > 4) {
        right1 = board[c][4];
        down1 = board[c - 1][5];
        down2 = board[c - 1][6];
        down3 = board[c - 1][7];
        crossupright1 = board[c][3];
        crossupright2 = board[c + 1][2];
        crossupright3 = board[c + 2][1];
        crossdownright1 = board[c][5];
        crossdownright2 = board[c + 1][6];
        crossdownright3 = board[c + 2][7];
    } else if (c == 8 && d > 3) {
        right1 = board[c][3];
        down1 = board[c - 1][4];
        down2 = board[c - 1][5];
        down3 = board[c - 1][6];
        crossupright1 = board[c][2];
        crossupright2 = board[c + 1][1];
        crossupright3 = board[c + 2][0];
        crossdownright1 = board[c][4];
        crossdownright2 = board[c + 1][5];
        crossdownright3 = board[c + 2][6];
    }

        //row 3, 2, 1 ultra delux
    else if (c == 1 && d > 2) {
        right1 = board[c][2];
        right2 = board[c + 1][2];
        right3 = board[c + 2][2];
        down1 = board[c - 1][3];
        down2 = board[c - 1][4];
        down3 = board[c - 1][5];
        crossdownright1 = board[c][3];
        crossdownright2 = board[c + 1][4];
        crossdownright3 = board[c + 2][5];
    } else if (c == 1 && d > 1) {
        right1 = board[c][1];
        right2 = board[c + 1][1];
        right3 = board[c + 2][1];
        down1 = board[c - 1][2];
        down2 = board[c - 1][3];
        down3 = board[c - 1][4];
        crossdownright1 = board[c][2];
        crossdownright2 = board[c + 1][3];
        crossdownright3 = board[c + 2][4];
    } else if (c == 1 && d > 0) {
        right1 = board[c][0];
        right2 = board[c + 1][0];
        right3 = board[c + 2][0];
        down1 = board[c - 1][1];
        down2 = board[c - 1][2];
        down3 = board[c - 1][3];
        crossdownright1 = board[c][1];
        crossdownright2 = board[c + 1][2];
        crossdownright3 = board[c + 2][3];
    } else if (c == 2 && d > 2) {
        right1 = board[c][2];
        right2 = board[c + 1][2];
        right3 = board[c + 2][2];
        left1 = board[c - 2][2];
        down1 = board[c - 1][3];
        down2 = board[c - 1][4];
        down3 = board[c - 1][5];
        crossdownright1 = board[c][3];
        crossdownright2 = board[c + 1][4];
        crossdownright3 = board[c + 2][5];
    } else if (c == 2 && d > 1) {
        right1 = board[c][1];
        right2 = board[c + 1][1];
        right3 = board[c + 2][1];
        left1 = board[c - 2][1];
        down1 = board[c - 1][2];
        down2 = board[c - 1][3];
        down3 = board[c - 1][4];
        crossdownright1 = board[c][2];
        crossdownright2 = board[c + 1][3];
        crossdownright3 = board[c + 2][4];
    } else if (c == 2 && d > 0) {
        right1 = board[c][0];
        right2 = board[c + 1][0];
        right3 = board[c + 2][0];
        left1 = board[c - 2][0];
        down1 = board[c - 1][1];
        down2 = board[c - 1][2];
        down3 = board[c - 1][3];
        crossdownright1 = board[c][1];
        crossdownright2 = board[c + 1][2];
        crossdownright3 = board[c + 2][3];
    } else if (c == 3 && d > 2) {
        right1 = board[c][2];
        right2 = board[c + 1][2];
        right3 = board[c + 2][2];
        left1 = board[c - 2][2];
        left2 = board[c - 3][2];
        down1 = board[c - 1][3];
        down2 = board[c - 1][4];
        down3 = board[c - 1][5];
        crossdownright1 = board[c][3];
        crossdownright2 = board[c + 1][4];
        crossdownright3 = board[c + 2][5];
    } else if (c == 3 && d > 1) {
        right1 = board[c][1];
        right2 = board[c + 1][1];
        right3 = board[c + 2][1];
        left1 = board[c - 2][1];
        left2 = board[c - 3][1];
        down1 = board[c - 1][2];
        down2 = board[c - 1][3];
        down3 = board[c - 1][4];
        crossdownright1 = board[c][2];
        crossdownright2 = board[c + 1][3];
        crossdownright3 = board[c + 2][4];
    } else if (c == 3 && d > 0) {
        right1 = board[c][0];
        right2 = board[c + 1][0];
        right3 = board[c + 2][0];
        left1 = board[c - 2][0];
        left2 = board[c - 3][0];
        down1 = board[c - 1][1];
        down2 = board[c - 1][2];
        down3 = board[c - 1][3];
        crossdownright1 = board[c][1];
        crossdownright2 = board[c + 1][2];
        crossdownright3 = board[c + 2][3];
    } else if (c == 4 && d > 2) {
        right1 = board[c][2];
        right2 = board[c + 1][2];
        right3 = board[c + 2][2];
        left1 = board[c - 2][2];
        left2 = board[c - 3][2];
        left3 = board[c - 4][2];
        down1 = board[c - 1][3];
        down2 = board[c - 1][4];
        down3 = board[c - 1][5];
        crossdownleft1 = board[c - 2][3];
        crossdownleft2 = board[c - 3][4];
        crossdownleft3 = board[c - 4][5];
        crossdownright1 = board[c][3];
        crossdownright2 = board[c + 1][4];
        crossdownright3 = board[c + 2][5];
    } else if (c == 4 && d > 1) {
        right1 = board[c][1];
        right2 = board[c + 1][1];
        right3 = board[c + 2][1];
        left1 = board[c - 2][1];
        left2 = board[c - 3][1];
        left3 = board[c - 4][1];
        down1 = board[c - 1][2];
        down2 = board[c - 1][3];
        down3 = board[c - 1][4];
        crossdownleft1 = board[c - 2][2];
        crossdownleft2 = board[c - 3][3];
        crossdownleft3 = board[c - 4][4];
        crossdownright1 = board[c][2];
        crossdownright2 = board[c + 1][3];
        crossdownright3 = board[c + 2][4];
    } else if (c == 4 && d > 0) {
        right1 = board[c][0];
        right2 = board[c + 1][0];
        right3 = board[c + 2][0];
        left1 = board[c - 2][0];
        left2 = board[c - 3][0];
        left3 = board[c - 4][0];
        down1 = board[c - 1][1];
        down2 = board[c - 1][2];
        down3 = board[c - 1][3];
        crossdownleft1 = board[c - 2][1];
        crossdownleft2 = board[c - 3][2];
        crossdownleft3 = board[c - 4][3];
        crossdownright1 = board[c][1];
        crossdownright2 = board[c + 1][2];
        crossdownright3 = board[c + 2][3];
    } else if (c == 5 && d > 2) {
        right1 = board[c][2];
        right2 = board[c + 1][2];
        right3 = board[c + 2][2];
        left1 = board[c - 2][2];
        left2 = board[c - 3][2];
        left3 = board[c - 4][2];
        down1 = board[c - 1][3];
        down2 = board[c - 1][4];
        down3 = board[c - 1][5];
        crossdownleft1 = board[c - 2][3];
        crossdownleft2 = board[c - 3][4];
        crossdownleft3 = board[c - 4][5];
        crossdownright1 = board[c][3];
        crossdownright2 = board[c + 1][4];
        crossdownright3 = board[c + 2][5];
    } else if (c == 5 && d > 1) {
        right1 = board[c][1];
        right2 = board[c + 1][1];
        right3 = board[c + 2][1];
        left1 = board[c - 2][1];
        left2 = board[c - 3][1];
        left3 = board[c - 4][1];
        down1 = board[c - 1][2];
        down2 = board[c - 1][3];
        down3 = board[c - 1][4];
        crossdownleft1 = board[c - 2][2];
        crossdownleft2 = board[c - 3][3];
        crossdownleft3 = board[c - 4][4];
        crossdownright1 = board[c][2];
        crossdownright2 = board[c + 1][3];
        crossdownright3 = board[c + 2][4];
    } else if (c == 5 && d > 0) {
        right1 = board[c][0];
        right2 = board[c + 1][0];
        right3 = board[c + 2][0];
        left1 = board[c - 2][0];
        left2 = board[c - 3][0];
        left3 = board[c - 4][0];
        down1 = board[c - 1][1];
        down2 = board[c - 1][2];
        down3 = board[c - 1][3];
        crossdownleft1 = board[c - 2][1];
        crossdownleft2 = board[c - 3][2];
        crossdownleft3 = board[c - 4][3];
        crossdownright1 = board[c][1];
        crossdownright2 = board[c + 1][2];
        crossdownright3 = board[c + 2][3];
    } else if (c == 6 && d > 2) {
        right1 = board[c][2];
        right2 = board[c + 1][2];
        left1 = board[c - 2][2];
        left2 = board[c - 3][2];
        left3 = board[c - 4][2];
        down1 = board[c - 1][3];
        down2 = board[c - 1][4];
        down3 = board[c - 1][5];
        crossdownleft1 = board[c - 2][3];
        crossdownleft2 = board[c - 3][4];
        crossdownleft3 = board[c - 4][5];
    } else if (c == 6 && d > 1) {
        right1 = board[c][1];
        right2 = board[c + 1][1];
        left1 = board[c - 2][1];
        left2 = board[c - 3][1];
        left3 = board[c - 4][1];
        down1 = board[c - 1][2];
        down2 = board[c - 1][3];
        down3 = board[c - 1][4];
        crossdownleft1 = board[c - 2][2];
        crossdownleft2 = board[c - 3][3];
        crossdownleft3 = board[c - 4][4];
    } else if (c == 6 && d > 0) {
        right1 = board[c][0];
        right2 = board[c + 1][0];
        left1 = board[c - 2][0];
        left2 = board[c - 3][0];
        left3 = board[c - 4][0];
        down1 = board[c - 1][1];
        down2 = board[c - 1][2];
        down3 = board[c - 1][3];
        crossdownleft1 = board[c - 2][1];
        crossdownleft2 = board[c - 3][2];
        crossdownleft3 = board[c - 4][3];
    } else if (c == 7 && d > 2) {
        right1 = board[c][2];
        right2 = board[c + 1][2];
        down1 = board[c - 1][3];
        down2 = board[c - 1][4];
        down3 = board[c - 1][5];
        crossdownright1 = board[c][3];
        crossdownright2 = board[c + 1][4];
        crossdownright3 = board[c + 2][5];
    } else if (c == 7 && d > 1) {
        right1 = board[c][1];
        right2 = board[c + 1][1];
        down1 = board[c - 1][2];
        down2 = board[c - 1][3];
        down3 = board[c - 1][4];
        crossdownright1 = board[c][2];
        crossdownright2 = board[c + 1][3];
        crossdownright3 = board[c + 2][4];
    } else if (c == 7 && d > 0) {
        right1 = board[c][0];
        right2 = board[c + 1][0];
        down1 = board[c - 1][1];
        down2 = board[c - 1][2];
        down3 = board[c - 1][3];
        crossdownright1 = board[c][1];
        crossdownright2 = board[c + 1][2];
        crossdownright3 = board[c + 2][3];
    } else if (c == 8 && d > 2) {
        right1 = board[c][2];
        down1 = board[c - 1][3];
        down2 = board[c - 1][4];
        down3 = board[c - 1][5];
        crossdownright1 = board[c][3];
        crossdownright2 = board[c + 1][4];
        crossdownright3 = board[c + 2][5];
    } else if (c == 8 && d > 1) {
        right1 = board[c][1];
        down1 = board[c - 1][2];
        down2 = board[c - 1][3];
        down3 = board[c - 1][4];
        crossdownright1 = board[c][2];
        crossdownright2 = board[c + 1][3];
        crossdownright3 = board[c + 2][4];
    } else if (c == 8 && d > 0) {
        right1 = board[c][0];
        down1 = board[c - 1][1];
        down2 = board[c - 1][2];
        down3 = board[c - 1][3];
        crossdownright1 = board[c][1];
        crossdownright2 = board[c + 1][2];
        crossdownright3 = board[c + 2][3];
    }
}