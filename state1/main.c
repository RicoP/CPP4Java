#include <stdio.h>

enum States {
    NONE,
    RED,
    REDYELLOW,
    GREEN,
    YELLOW
};

enum States think(const enum States state) {
    switch(state) {
        case NONE:
        case YELLOW:
        return RED;

        case RED:
        return REDYELLOW;

        case REDYELLOW:
        return GREEN;

        case GREEN:
        return YELLOW;
    }

    return NONE;
}

int main(void)
{
    int i;
    enum States state = NONE;

    for(i = 0; i != 10; i++) {
        state = think(state);
        printf("%d\n", state);
    }

    return 0;
}


