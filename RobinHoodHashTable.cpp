#include "RobinHoodHashTable.h"
#include <iostream>

using namespace std;

RobinHoodHashTable::RobinHoodHashTable(size_t numBuckets, std::shared_ptr<HashFamily> family) {
  // TODO: Implement this
  tableSize = numBuckets;
  table = new size_t*[tableSize] {nullptr};
  hashFunction = family->get();
  cout << endl;
}

RobinHoodHashTable::~RobinHoodHashTable() {

	for (size_t i {}; i < tableSize; i++)
		if (table[i] != nullptr)
			delete table[i];
	delete [] table;
}

void RobinHoodHashTable::insert(int data) {
  // TODO: Implement this
  	cout << "===========================" << endl;
  	cout << " Insert" << endl;
	cout << "===========================" << endl;

	size_t hash = hashFunction(data);
	size_t index = (hash % tableSize);

	table[index] = new size_t {hash};

	cout << "Hash: " << hash << endl;
	cout << "Index: " << index << endl;
}

bool RobinHoodHashTable::contains(int data) const {
  // TODO: Implement this
	cout << "===========================" << endl;
	cout << " Contains" << endl;
	cout << "===========================" << endl;

  return false;
}

/**
 * You should implement this operation using backward-shift deletion: once
 * you've found the element to remove, continue scanning forward until you
 * find an element that is at its home location or an empty cell, then shift
 * each element up to that point backwards by one step.
 */
void RobinHoodHashTable::remove(int data) {
	cout << "===========================" << endl;
	cout << " Remove" << endl;
	cout << "===========================" << endl;

  // TODO: Implement this
}
