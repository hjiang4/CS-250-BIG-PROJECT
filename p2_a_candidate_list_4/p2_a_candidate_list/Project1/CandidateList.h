/*
	Hongchang Jiang
	Khang Tran
	James Zhao

	12/6/2020

	CS A250
	Project 2
*/
#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H

#include "CandidateType.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <list>
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

	// Destructor
	~CandidateList();

private:
	// searchCandidate
	bool searchCandidate(int idNumber, std::list<CandidateType>::const_iterator& it) const;

	// printHeader
	void printHeader() const;

	// printCandidate
	void printCandidate(std::list<CandidateType>::const_iterator it, int pos) const;

	// declare an STL list of CandidateType named candidates
	std::list<CandidateType> candidates;
};
#endif