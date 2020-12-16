/*
    Hongchang Jiang
    Khang Tran
    James Zhao

    12/6/2020

    CS A250
    Project 2
*/

#include "CandidateList.h"
#include "CandidateList.h"
#include <vector>
#include <algorithm>

using namespace std;

CandidateList::CandidateList()
{
}

// addCandidate
void CandidateList::addCandidate(const CandidateType& obj)
{
    candidates.push_back(obj);
}

// getWinner
int CandidateList::getWinner() const
{
    int maxVote = 0;
    list<CandidateType>::const_iterator it = candidates.cbegin();
    list<CandidateType>::const_iterator candidateWithMaxVotes;
    while (it != candidates.cend())
    {
        if (it->getTotalVotes() > maxVote)
        {
            maxVote = it->getTotalVotes();
            candidateWithMaxVotes = it;
        }
        else
        {
            it++;
        }
    }
    return candidateWithMaxVotes->getID();
}

// isEmpty
bool CandidateList::isEmpty() const
{
    return candidates.empty();
}

// searchCandidate(public)
bool CandidateList::searchCandidate(int idNumber) const
{
    list<CandidateType>::const_iterator it = candidates.cbegin();
    return searchCandidate(idNumber, it);
}

// printCandidateName
void CandidateList::printCandidateName(int idNumber) const
{
    list<CandidateType>::const_iterator it = candidates.cbegin();
    searchCandidate(idNumber, it);
    if (it != candidates.cend())
    {
        cout << it->getLastName() << ", " << it->getFirstName() << ends;
    }
}

// printAllCandidates
void CandidateList::printAllCandidates() const
{
    for (auto it = candidates.begin();it != candidates.end();it++)
    {
        it->printCandidateInfo();
    }
}

// printKingdomVotes
void CandidateList::printKingdomVotes(int idNumber, int idx) const
{
    list<CandidateType>::const_iterator it = candidates.begin();
    searchCandidate(idNumber, it);
    if (it != candidates.end())
    {
        cout << "    *" << right << setw(3) << it->getVotesByKingdom(idx) << "( => )" << KINGDOMS[idx] << endl;
    }
}

// printCandidateTotalVotes
void CandidateList::printCandidateTotalVotes(int idNumber) const
{
    list<CandidateType>::const_iterator it = candidates.begin();
    searchCandidate(idNumber, it);
    if (it != candidates.end())
    {
        cout << "    => Total votes: " << right << setw(3) << it->getTotalVotes() << endl;
    }
}

// printFinalResults
void CandidateList::printFinalResults() const
{
    printHeader();
    auto current = candidates.cbegin();
    auto highestVotes = candidates.cbegin();
    while (current != candidates.cend())
    {
        highestVotes->getTotalVotes() < current->getTotalVotes() ?
        highestVotes = current : current++;
    }
    int pos = 1;
    printCandidate(highestVotes,pos);
    int prevHigh = highestVotes->getTotalVotes();
    while (pos < static_cast<int>(candidates.size()))
    {
        current = candidates.cbegin();;
        highestVotes = candidates.cbegin();;
        while (current != candidates.cend() && highestVotes->getTotalVotes() != prevHigh - 1)
        {
            while (highestVotes->getTotalVotes() >
                prevHigh - 1)
            {
                highestVotes++;
            }
            current->getTotalVotes() < prevHigh&& current->getTotalVotes() > highestVotes->getTotalVotes() ?
            highestVotes = current : current++;
        }
        prevHigh = highestVotes->getTotalVotes();
        ++pos;
        printCandidate(highestVotes, pos);
        if (pos % 5 == 0)
        {
            cout << "---------------------------------------" << endl;
        }
    }
    cout << "__" << endl;
}

// Destructor
CandidateList::~CandidateList()
{
}

// searchCandidate(private)
bool CandidateList::searchCandidate(int idNumber, list<CandidateType>::const_iterator& it) const
{
    CandidateType candi = CandidateType();
    candi.setCharacterInfo("","",idNumber);
    it = find(candidates.begin(), candidates.end(), candi);
    if (it != candidates.cend())
    {
        return true;
    }
    return false;
}
void CandidateList::printHeader() const
{
    cout << " FINAL RESULTS \n" << endl;
    cout << "LAST" << setw(16) << "FIRST" << setw(10) << "TOTAL"
        << setw(7) << "POS" << endl;
    cout << "NAME" << setw(15) << "NAME" << setw(11) << "VOTES"
        << setw(7) << "#" << endl;
    cout << "__\n" << endl;
}

void CandidateList::printCandidate(list<CandidateType>::const_iterator it, int pos) const
{
    cout << left << setw(15) << it->getLastName()
    << left << setw(10) << it->getFirstName()
    << right << setw(5) << it->getTotalVotes()
    << right << setw(7) << pos << endl;
}