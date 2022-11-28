using namespace std;
#include "string"
#include "Character.h"
#ifndef __WIZARD_H__
#define __WIZARD_H__
class Wizard : public Character {
 private:
        int rank;
 public:
        Wizard(const string & name, double health, double attackStrength, const int & rank);
        void attack(Character & character) override;

};
#endif