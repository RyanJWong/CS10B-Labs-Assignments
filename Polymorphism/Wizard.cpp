#include "Character.h"
#include "Wizard.h"
using namespace std;
#include "string"
#include <iostream>
Wizard::Wizard (const string & name, double health, double attackStrength, const int  & rank) : Character(WIZARD, name, health, attackStrength), rank(rank) {

}

void Wizard::attack(Character & character) {
    
    if (character.getType() == WIZARD) {
        Wizard &opp = dynamic_cast<Wizard &>(character);
        cout << "Wizard " << name << " attacks " << character.getName() << " --- POOF!!" << endl;
        character.damage(attackStrength*(double(rank)/opp.rank));
        cout << character.getName() <<  " takes "<< (attackStrength * (double(rank) / opp.rank))<< " damage." << endl;
        return;
        
    }
    cout << "Wizard " << name << " attacks " << character.getName() << " --- POOF!!" << endl;
    character.damage(attackStrength);
    cout << character.getName() <<  " takes "<< (attackStrength) << " damage." << endl;

}
