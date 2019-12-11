#include "gameScene.h"

CS_Character::CS_Character()
{
    std::cout << "create a character" << std::endl;
    saveAnimation = NULL;
    bank = new (CS_BankAnimation);
    physic = new (CS_PersonalPhysic);
    right = false;
}

CS_Character::~CS_Character()
{
    std::cout << "delete a character" << std::endl;
    delete bank;
    delete physic;
}