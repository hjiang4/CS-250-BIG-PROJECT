/*
    Hongchang Jiang
    Khang Tran
    James Zhao

    12/6/2020

    CS A250
    Project 2
*/

#include "CharacterType.h"

using namespace std;

// Implement all functions in the SAME order
// as listed in the interface file.

CharacterType::CharacterType()
                            :id(0)
{
}

CharacterType::CharacterType(const std::string& newFirstName, const std::string& newLastName, int newId)
                            :firstName(newFirstName),lastName(newLastName),id(newId)
{
}

void CharacterType::setCharacterInfo(const std::string& newFirstName, const std::string& newLastName, int newId)
{
    firstName = newFirstName;
    lastName = newLastName;
    id = newId;
}

std::string CharacterType::getFirstName() const
{
    return firstName;
}

std::string  CharacterType::getLastName() const
{
    return lastName;
}

int CharacterType::getID() const
{
    return id;
}

void CharacterType::printName() const
{
    cout << getLastName() << ", " << getFirstName();
}

void CharacterType::printCharacterInfo() const
{
    printID();
    cout <<" " << getFirstName() << " " << getLastName();
}

void CharacterType::printID() const
{
    cout << "ID# " << getID();
}
