#include "LinearProbingHashTable.h"
#include <iostream>
#include <cmath>

using namespace std;

LinearProbingHashTable::LinearProbingHashTable(size_t numBuckets, std::shared_ptr<HashFamily> family) {
  numElements = 0;
  tableSize = numBuckets;
  table = new int [tableSize];
  for (size_t i {}; i < numBuckets; i++)
  	table[i] = -1;

  hashFunction = family->get();
}

LinearProbingHashTable::~LinearProbingHashTable() {
  delete [] table;
}

void LinearProbingHashTable::insert(int data) {

  size_t hash {hashFunction(data)};
  int index {abs(static_cast<int>(hash)) % static_cast<int>(tableSize)};
  while (table[index] != -1) { // if the current index is taken
  	if (table[index] == static_cast<int>(hash)) // if the element already exists
  		return;
  	index++;
	if (index >= static_cast<int>(tableSize)) // if the current index is greater than the max index, loop it around to 0.
		index = 0;
  }
  table[index] = static_cast<int>(hash);
  numElements++;
  return;
}

bool LinearProbingHashTable::contains(int data) const {
	if (numElements <= 0)
  		return false;

	size_t hash {hashFunction(data)};
	int index {abs(static_cast<int>(hash)) % static_cast<int>(tableSize)};
	bool doesContain {};

	while (table[index] != -1) { // if the current index is taken
		if (table[index] == static_cast<int>(hash)) { // if the hash at the index matches, return true
			doesContain = true;
			break;
		}
		index++; // increment index
		if (index >= static_cast<int>(tableSize)) {// if the new index is greater than the max index, loop it around to 0.
			index = 0;
		}
	}
	return doesContain;
}

void LinearProbingHashTable::remove(int data) {
	if (numElements <= 0)
  		return;

    size_t hash {hashFunction(data)};
	int index {abs(static_cast<int>(hash)) % static_cast<int>(tableSize)};

 	bool doesExist {};
 	while (table[index] != -1 && !doesExist) { // if the current index is taken (isn't a -1), and the number hasn;t been found
		if (table[index] == static_cast<int>(hash)) // if the hash at the index matches, we can break the loop
			doesExist = true;
		else {
			index++; // increment index
			if (index >= static_cast<int>(tableSize)) // if the new index is greater than the max index, loop it around to 0.
				index = 0;
		}
	}
	if (doesExist) {// if the value was found
		table[index] = -2;
	}
	return;
}
