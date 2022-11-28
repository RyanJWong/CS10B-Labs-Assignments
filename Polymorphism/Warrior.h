using namespace std;
#include "string"
#include "Character.h"
#ifndef __WARRIOR_H__
#define __WARRIOR_H__
class Warrior : public Character {
 private:
        string allegiance;
 public:
        Warrior(const string & name, double health, double attackStrength, const string & allegiance);
        void attack(Character & character) override;

};
#endif