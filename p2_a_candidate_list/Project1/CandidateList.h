/*
	Hongchang Jiang
	Khang Tran
	James Zhao

	11/29/2020

	CS A250
	Project 1 (Part B+C)
*/

#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H

#include "CandidateType.h"
#include <iostream>
#include <string>
#include <iomanip>

class Node
{
public:
	Node() : link(nullptr) {}
    Node(const CandidateType& newCandidate, Node *theLink) 
		: candidate(newCandidate), link(theLink){}
    Node* getLink( ) const { return link; }
	CandidateType getCandidate( ) const { return candidate; }
    void setCandidate(const CandidateType& newCandidate)
		{ candidate = newCandidate; }
    void setLink(Node *theLink) { link = theLink; }
	~Node() {}
private:
    CandidateType candidate;
    Node *link;		//pointer that points to next node
};

class CandidateList
{
public:
	// Default constructor
	CandidateList();

	// addCandidate
	void addCandidate(const CandidateType& obj);

	// getWinner
	int getWinner() const;

	// isEmpty
	bool isEmpty() const;
	// searchCandidate
	bool searchCandidate(int idNumber) const;

	// printCandidateName
	void printCandidateName(int idNumber) const;
	// printAllCandidates
	void printAllCandidates() const;
	// printKingdomVotes
	void printKingdomVotes(int idNumber, int idx) const;
	// printCandidateTotalVotes
	void printCandidateTotalVotes(int idNumber) const;

	// printFinalResults
	void printFinalResults() const;
	// clearList
	void clearList();
	// Destructor
	~CandidateList();

private:
	// searchCandidate
	void searchCandidate(int idNumber, Node** node) const;

	Node* first; 	// pointer to the first candidate in the list
	Node* last;		// pointer to last candidate in the list
	int count;		// number of candidates in the list	
};
#endif
