#include <iostream>
#include <stdio.h>
#include "enemy.h"

using namespace std;

char getCommand();
char* stateToString(enum EnemyState state);

int main()
{
    Enemy* enemy = new Enemy();
    char c = 0;

    while(c != 'q') {
        printf("State: %s, Health: %d\n", stateToString(enemy->getState()), enemy->getHealth());
        c = getCommand();

        switch(c) {
        case 'h':
            enemy->hit(46);
            break;
        case 'r':
            enemy->refill();
            break;
        default:
            continue;
        }
    }

    return 0;
}

char getCommand() {
    char in[256];
    char c;

    do {
        cin >> in;
        c = in[0];
    } while(c != 'r' && c != 'h' && c != 'q');

    return c;
}

char* stateToString(enum EnemyState state) {
    switch(state) {
    case IDLE:
        return "Idle";
    case ATTACK:
        return "Attack";
    case FLEE:
        return "Flee";
    case DEAD:
        return "Dead";
    }

    return "";
}
