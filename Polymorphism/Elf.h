using namespace std;
#include "string"
#include "Character.h"
#ifndef __ELF_H__
#define __ELF_H__
class Elf : public Character {
 private:
        string family;
 public:
        Elf(const string & name, double health, double attackStrength, const string & family);
        void attack(Character & character) override;

};
#endif