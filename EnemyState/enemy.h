#ifndef ENEMY_H
#define ENEMY_H

enum EnemyAction {
    HIT,
    TICK,
    REFILL
};

enum EnemyState {
    IDLE,
    DEAD,
    ATTACK,
    FLEE
};

class Enemy
{
protected:
    enum EnemyState state;
    int energy;
    enum EnemyState processHit();
    void think(EnemyAction action);

public:
    Enemy();
    enum EnemyState getState();
    int getHealth();
    void refill();
    void hit(int points);
};

#endif // ENEMY_H
