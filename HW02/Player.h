//
// Created by nimrod on 03/12/2022.
//

#ifndef CPPCOURSE_PLAYER_H
#define CPPCOURSE_PLAYER_H


class Player {
private:
    int score;
    char potionSymbol;
    char gemSymbol;
public: //No dynamic allocation, so no need to define any of the three and five rule
    Player(char potionSymbol, char gemSymbol);

    int getScore() const;

    char getPotionSymbol() const;

    char getGemSymbol() const;

    Player &operator-=(const int &i);

    Player &operator+=(const int &i);
};


#endif //CPPCOURSE_PLAYER_H
