#include "Elf.h"
#include "Character.h"
using namespace std;
#include "string"
#include <iostream>
Elf::Elf (const string & name, double health, double attackStrength, const string & family) : Character(ELF, name, health, attackStrength), family(family) {

}

void Elf::attack(Character & character) {
    
    if (character.getType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(character);
        if (opp.family == family) {
            cout << "Elf " << name <<  " does not attack Elf " << opp.getName() << "."<< endl  << "They are both members of the " << family << " family." << endl;
            return;
        }
    }
    cout << "Elf " << name << " shoots an arrow at " << character.getName() << " --- TWANG!!" << endl;
    character.damage(double(health / MAX_HEALTH) * attackStrength);
    cout << character.getName() <<  " takes "<< ((health / MAX_HEALTH) * attackStrength) << " damage." << endl;
}
