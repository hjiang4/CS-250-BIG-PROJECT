/*
    Hongchang Jiang
    Khang Tran
    James Zhao

    12/6/2020

    CS A250
    Project 2
*/

#include "CandidateType.h"

using namespace std;

// Implement all functions in the SAME order
// as listed in the interface file.

CandidateType::CandidateType()
    :totalVotes(0), numOfKingdoms(NUM_OF_KINGDOMS), kingdomVotes(new int[NUM_OF_KINGDOMS] {0}), CharacterType()
{
}

CandidateType::CandidateType(const CandidateType& another)
{
    setCharacterInfo(another.getFirstName(), another.getLastName(), another.getID());
    totalVotes = another.totalVotes;
    numOfKingdoms = another.numOfKingdoms;
    kingdomVotes = another.kingdomVotes;
    for (size_t i = 0; i < numOfKingdoms; ++i)
    {
        kingdomVotes[i] = another.kingdomVotes[i];
    }
}

CandidateType& CandidateType::operator=(const CandidateType& another)
{
    setCharacterInfo(another.getFirstName(), another.getLastName(), another.getID());
    if (&another != this) //avoid self assignment
    {
        if (numOfKingdoms != another.numOfKingdoms)
        {
            delete[ ] kingdomVotes; 
            kingdomVotes = new int[another.numOfKingdoms];  
        }
        totalVotes = another.totalVotes;
        numOfKingdoms = another.numOfKingdoms;    
        for(int i = 0; i < numOfKingdoms; ++i) 
        {
            kingdomVotes[i] = another.kingdomVotes[i];
        }
    }
    else
    {
        cerr << "Attempted assignment to itself.";
    }
    return *this;
}

void CandidateType::updateVotesByKingdom(int index, int NumOfVotes)
{
    totalVotes += NumOfVotes;
    kingdomVotes[index] = NumOfVotes;
}

int CandidateType::getTotalVotes() const
{
    return totalVotes;
}

int CandidateType::getVotesByKingdom(int index) const
{
    return kingdomVotes[index];
}

void CandidateType::printCandidateInfo() const
{
    printID();
    cout << " - " << getFirstName() << ", " << getLastName() << endl;
}

void CandidateType::printCandidateTotalVotes() const
{
    printName();
    cout << "\n=>Total votes(all kindgoms): " << getTotalVotes();
}

CandidateType::~CandidateType()
{
}

bool CandidateType::operator==(const CandidateType& rhs) const
{
    return getID() == rhs.getID();
}