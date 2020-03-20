#include "gameScene.h"

CS_Character::CS_Character()
{
    std::cout << "create a character" << std::endl;
    bankMoine = new (CS_BankAnimation);
    bankKitsune = new (CS_BankAnimation);
    physic = new (CS_PersonalPhysic);
    right = false;
    moine = true;
    jump = 2;
    maxJump = 2;
}

CS_Character::~CS_Character()
{
    std::cout << "delete a character" << std::endl;
    delete bankMoine;
    delete bankKitsune;
    delete physic;
}
