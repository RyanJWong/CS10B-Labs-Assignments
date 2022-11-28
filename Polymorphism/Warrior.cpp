#include "Warrior.h"
#include "Character.h"
using namespace std;
#include "string"
#include <iostream>
Warrior::Warrior (const string & name, double health, double attackStrength, const string & allegiance) : Character(WARRIOR, name, health, attackStrength), allegiance(allegiance) {

}

void Warrior::attack(Character & character) {
    
    if (character.getType() == WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(character);
        if (opp.allegiance == allegiance) {
            cout << "Warrior " << name <<  " does not attack Warrior " << opp.getName() << "."<< endl  << "They share an allegiance with " << allegiance << "." << endl;
            return;
        }
    }
    cout << "Warrior " << name << " attacks " << character.getName() << " --- SLASH!!" << endl;
    character.damage(double((health / MAX_HEALTH) * attackStrength));
    cout << character.getName() <<  " takes "<< (double(health / MAX_HEALTH) * attackStrength) << " damage." << endl;

}
