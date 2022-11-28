using namespace std;
#include "Character.h"
#include "string"

Character::Character(HeroType type, const string & name, double health, double attack) : type(type), name(name), health(health), attackStrength(attack) {

}

HeroType Character::getType() const {
    return type;
}

const string & Character::getName() const {
    return name;
}
int Character::getHealth() const {
    return health;
}
void Character::damage(double d) {
    health -= d;
}
bool Character::isAlive() const {
    return (health > 0) ? true : false;
}