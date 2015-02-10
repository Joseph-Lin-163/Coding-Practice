#ifndef singlyLinked_h
#define singlyLinked_h
#include <string>
#include "house.h"
using namespace std;
// This singly Linked List will hold animals



class singlyLinked {
public:
	singlyLinked() {
		head = nullptr;
		size = 0;
	}

	~singlyLinked() {
		for (int i = 0; i < size; i++) {
			house *toDelete = head;
			head = head->next;
			std::cout << "Deleting " << toDelete->name << endl;
			delete toDelete;
		}
	}

	// Only adds at the beginning or somewhere in between based on position parameter
	// There is error checking to make sure that we don't go past the end
	// If the position > size, then we add at the end and let user know
	void addItem(string animal, int position = 0) {
		// Don't forget, new keyword is used with pointers
		// And pointers use -> not .
		if (position < 0) {
			std::cout << "Deletion unsuccessful! Number out of range, did not add anything." 
			<< std::endl;
			return;
		}

		if (position == 0) {
			house *toAdd = new house;
			toAdd->name = animal;
			toAdd->next = head;
			head = toAdd;
			size++;
			std::cout << animal << " addition successful!" << endl;
		}
		else {
			house *temp = head;

			while (temp->next != nullptr) {
				if (--position == 0)
					break;
				temp = temp->next;
			}

			if (position != 0)
				std::cout << "Position is invalid, not enough nodes. Adding "<< animal
				<< " at end of list." << std::endl;

			// To add a pointer to the middle of the list
			// Create new node, have node point to temp->next
			// then have temp->next point to new node
			house *toAdd = new house;
			toAdd->name = animal;
			toAdd->next = temp->next;
			temp->next = toAdd;
			size++;
		}
		return;
	}

	void deleteItem(string animal) {
		house *temp = head;
		// Check empty case
		if (temp == nullptr) {
			std::cout << "Nothing to delete!" << endl;
			return;
		}

		// Check single element case
		if (temp->name == animal) {
			head = head->next;
			delete temp;
			size--;
			std::cout << "Deletion successful!" << std::endl;
			return;
		}

		// Check for subsequent nodes
		while (temp->next != nullptr) {
			if (temp->next->name == animal) {
				house *toDelete = temp->next;
				temp->next = temp->next->next;
				delete toDelete;
				size--;
				std::cout << "Deletion successful!" << std::endl;
				return;
			}
			temp = temp->next;
		}

		std::cout << "Deletion unsuccessful. Item does not exist, deleted nothing." << std::endl;
		return;
	}

	void deleteItem(int animalNum) {
		if (animalNum < 0) {
			std::cout << "Deletion unsuccessful! Number out of range, did not delete anything." 
			<< std::endl;
			return;
		}

		house *temp = head;
		// Check empty case
		if (temp == nullptr) {
			std::cout << "Nothing to delete!" << endl;
			return;
		}

		// Check single element case
		if (animalNum == 0) {
			head = head->next;
			delete temp;
			size--;
			std::cout << "Deletion successful!" << std::endl;
			return;
		}

		// Check subsequent cases
		while (temp->next != nullptr && animalNum != 0) {
			if (--animalNum == 0) {
				house *toDelete = temp->next;
				temp->next = temp->next->next;
				delete toDelete;
				size--;
				std::cout << "Deletion successful!" << std::endl;
				return;
			}
			temp = temp->next;			
		}

		std::cout << "Deletion unsuccessful! Number out of range, did not delete anything." 
		<< std::endl;
		return;
	}

	int findItem(string animal) {
		house *temp = head;
		// Check empty list
		if (temp == nullptr) {
			std::cout << "No animals found, returning -1." << std::endl;
			return -1;
		}

		// Check single element case
		if (temp->name == animal) {
			return 0;
		}

		// Check subsequent cases
		int animalNum = 0;
		while (temp->next != nullptr) {
			animalNum++;
			temp = temp->next; 
			if (temp->name == animal)
				return animalNum;
		}

		std::cout << "Couldn't find your animal! Returning -1." << endl;
		return -1;
	}

	void printItems() {
		house *temp = head;
		// Check empty case
		if (temp == nullptr) {
			std::cout << "No items in list!" << std::endl;
			return;
		}

		// Subsequent cases, works even with single element case
		for (int i = 0; i < size; i++) {
			std::cout << temp->name << endl;
			temp = temp->next;
		}

		return;
	}

	int printSize() {
		std::cout << "There are " << size << " items in the list." << endl;
	}

private:
	house *head;
	int size;
};

#endif