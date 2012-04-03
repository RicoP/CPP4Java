#include "enemy.h"

Enemy::Enemy()
    : state(IDLE), energy(100)
{
}

void Enemy::think(EnemyAction action) {
    for(;;) {
        switch(state) {
            case IDLE:
            case ATTACK: {
                if(action == HIT) {
                    state = processHit();
                    return;
                }
                return;
            }

            case FLEE: {
                if(action == HIT) {
                    state = processHit();
                    return;
                }
                if(action == REFILL) {
                    state = IDLE;
                    return;
                }
                return;
            }

            case DEAD: {
                return;
            }
        }
    }
}

enum EnemyState Enemy::processHit() {
    if(energy <= 0) {
        return DEAD;
    }
    if(energy < 10) {
        return FLEE;
    }
    return ATTACK;
}

enum EnemyState Enemy::getState() {
    return state;
}

int Enemy::getHealth() {
    return energy;
}

void Enemy::refill() {
    energy = 100;
    think(REFILL);
}

void Enemy::hit(int points) {
    energy -= points;
    think(HIT);
}
