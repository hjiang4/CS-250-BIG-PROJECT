/*
    Hongchang Jiang
    Khang Tran
    James Zhao

    11/29/2020

    CS A250
    Project 1 (Part B+C)
*/

#include "CandidateList.h"
#include "CandidateList.h"
#include <vector>
#include <algorithm>

using namespace std;

// Default constructor
CandidateList::CandidateList()
                            :first(nullptr), last(nullptr), count(0)
{
}

// addCandidate
void CandidateList::addCandidate(const CandidateType& obj) 
{
    Node* newNode = new Node;
    newNode->setCandidate(obj);
    newNode->setLink(nullptr);
    if (this->first == nullptr) 
    {
        //cout << "List IS empty" << endl;
        this->first = newNode;
    }
    else if (this->last == nullptr)
    {
        //cout << "List only have 1 elements" << endl;
        this->first->setLink(newNode);
        this->last = newNode;
    }
    else if (this->last != nullptr) 
    {
        //cout << "Normal cases" << endl;
        this->last->setLink(newNode);
        this->last = newNode;
    }
    this->count++;
}

// getWinner
int CandidateList::getWinner() const 
{
    if (this->count == 0) 
    {
        cout << "List is empty." << endl;
        return -1;
    }
    Node* dummy = this->first;
    int maxVote = -1;
    CandidateType candidateWithMaxVotes;
    while (dummy != nullptr) 
    {
        if (dummy->getCandidate().getTotalVotes() > maxVote) 
        {
            maxVote = dummy->getCandidate().getTotalVotes();
            candidateWithMaxVotes = dummy->getCandidate();
        }
        dummy = dummy->getLink();
    }
    return candidateWithMaxVotes.getID();
}

// isEmpty
bool CandidateList::isEmpty() const
{
    return this->count == 0;
}

// searchCandidate
bool CandidateList::searchCandidate(int idNumber) const
{
    Node* resultNode = nullptr;
    this->searchCandidate(idNumber, &resultNode);
    return resultNode != nullptr;
}

// printCandidateName
void CandidateList::printCandidateName(int idNumber) const
{
    Node* resultNode = nullptr;
    this->searchCandidate(idNumber, &resultNode);
    if (resultNode != nullptr) {
        cout << resultNode->getCandidate().getLastName() << ", " << resultNode->getCandidate().getFirstName() << ends;
    }
}

// printAllCandidates
void CandidateList::printAllCandidates() const 
{
    if (this->count == 0) 
    {
        cout << "List is empty." << endl;
        return;
    }
    Node* dummy = this->first;
    while (dummy != nullptr) 
    {
        dummy->getCandidate().printCandidateInfo();
        dummy = dummy->getLink();
    }
    return;
}

// printKingdomVotes
void CandidateList::printKingdomVotes(int idNumber,int idx) const
{
    Node* resultNode = nullptr;
    this->searchCandidate(idNumber, &resultNode);
    if (resultNode != nullptr) 
    {
        cout << "    *" << right << setw(3) << resultNode->getCandidate().getVotesByKingdom(idx) << "( => )" << KINGDOMS[idx] << endl;
    }
}

// printCandidateTotalVotes
void CandidateList::printCandidateTotalVotes(int idNumber) const
{
    Node* resultNode = nullptr;
    this->searchCandidate(idNumber, &resultNode);
    if (resultNode != nullptr) 
    {
        cout << "    => Total votes: " << right << setw(3) << resultNode->getCandidate().getTotalVotes() << endl;
    }
}

// compare function for sorting
bool compareCandidateType(CandidateType c1, CandidateType c2)
{
    return (c1.getTotalVotes() > c2.getTotalVotes());
}

// printFinalResults
void CandidateList::printFinalResults() const
{
    if (first == nullptr)
    {
        cerr << "List is empty.";
    }
    else
    {
        cout << "************ FINAL RESULTS ************" << endl;
        cout << "LAST           FIRST     TOTAL    POS" << endl;
        cout << "NAME           NAME      VOTES      #" << endl;
        cout << "_______________________________________" << endl;

        Node* current = first;
        Node* highestVotes = first;

        while (current != nullptr)
        {
            highestVotes->getCandidate().getTotalVotes() < current->getCandidate().getTotalVotes() ?
                highestVotes = current : current = current->getLink();
        }

        int pos = 1;

        cout << left << setw(15) << highestVotes->getCandidate().getLastName()
            << left << setw(10) << highestVotes->getCandidate().getFirstName()
            << right << setw(5) << highestVotes->getCandidate().getTotalVotes()
            << right << setw(7) << pos << endl;

        int prevHigh = highestVotes->getCandidate().getTotalVotes();

        while (pos < count)
        {
            current = first;
            highestVotes = first;

            while (current != nullptr &&
                highestVotes->getCandidate().getTotalVotes() !=
                prevHigh - 1)
            {
                while (highestVotes->getCandidate().getTotalVotes() >
                    prevHigh - 1)
                {
                    highestVotes = highestVotes->getLink();
                }

                current->getCandidate().getTotalVotes() < prevHigh&&
                    current->getCandidate().getTotalVotes() > highestVotes->getCandidate().getTotalVotes() ?
                    highestVotes = current : current = current->getLink();
            }

            prevHigh = highestVotes->getCandidate().getTotalVotes();
            ++pos;

            cout << left << setw(15) << highestVotes->getCandidate().getLastName()
                << left << setw(10) << highestVotes->getCandidate().getFirstName()
                << right << setw(5) << highestVotes->getCandidate().getTotalVotes()
                << right << setw(7) << pos << endl;
            if (pos % 5 == 0)
            {
                cout << "---------------------------------------" << endl;
            }
            
        }

        current, highestVotes = nullptr;
        cout << "__" << endl;
    }
}

// clearList
void CandidateList::clearList() 
{
    Node* dummy = this->first;
    while (dummy != nullptr) 
    {
        Node* tmp = dummy->getLink();
        delete dummy;
        this->count--;
        dummy = tmp;
    }
}

// Destructor
CandidateList::~CandidateList()
{
    clearList();
}

// searchCandidate
void CandidateList::searchCandidate(int idNumber, Node** node) const
{
    if (this->count == 0) 
    {
        cout << "List is empty." << endl;
        return;
    }
    Node* dummy = this->first;
    while (dummy != nullptr) 
    {
        if (dummy->getCandidate().getID() == idNumber) 
        {
            *node = dummy;
            break;
        }
        dummy = dummy->getLink();
    }
    if (*node == nullptr)
    {
        cout << "    => ID not in the list." << endl;
    }
}

