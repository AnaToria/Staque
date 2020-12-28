#include<iostream>
#include "Staque.h"
using namespace std;

Staque::Staque()
	:myTop(NULL), myLast(NULL), size(0)
{};

Staque::Staque(const Staque& original) {
	myTop = NULL;
	myLast = NULL;
	size = 0;
	if (!original.Empty()) {
		myTop = new Staque::Node(original.Top());

		Staque::NodePointer tempPointer = myTop,
			origPointer = original.myTop->next;

		while (origPointer != NULL) {
			tempPointer->next = new Staque::Node(origPointer->data, NULL, tempPointer);
			tempPointer = tempPointer->next;
			origPointer = origPointer->next;
		}
		myLast = tempPointer;
		size = original.size;
	}
}

Staque::~Staque() {
	Staque::NodePointer currentPointer = myTop, 
		nextPointer;
	while (currentPointer != NULL) {
		nextPointer = currentPointer->next;
		delete currentPointer;
		currentPointer = nextPointer;
	}
	delete myTop;
	delete myLast;
}

const Staque& Staque::operator=(const Staque& rightHandSide) {
	if (this != &rightHandSide) {
		this->~Staque();
		
		if (rightHandSide.Empty())
			myTop = NULL;
		else {
			myTop = new Staque::Node(rightHandSide.Top());
			Staque::NodePointer tempPointer = myTop,
				rhsPointer = rightHandSide.myTop->next;
			while (rhsPointer != NULL)
			{
				tempPointer->next = new Staque::Node(rhsPointer->data, NULL, tempPointer);
				tempPointer = tempPointer->next;
				rhsPointer = rhsPointer->next;
			}
			myLast = tempPointer;
			size = rightHandSide.size;
		}
	}
	return *this;
}
bool Staque::Empty() const {
	return (myTop == 0);
}
StaqueElement Staque::Top() const {
	if (!Empty())
		return (myTop->data);
	else {
		cerr << "\t\tStaque is empty - it's a 'garbage'" << endl;
		StaqueElement* garbage = new StaqueElement;
		return *garbage;
		delete garbage;
	}
}

ostream& operator<<(ostream& out, const Staque& aStaque) {
	aStaque.Display(out);
	return out;
}
void Staque::Display(ostream& out) const {
	Staque::NodePointer i;
	if (!Empty()) {
		for (i = myTop; i != 0; i = i->next)
			out << i->data << " ";
		out << endl;
	}
	else {
		cerr << "\t*** Staque is empty ***" << endl;
	}
}

void Staque::Push(const StaqueElement& object) {
	if (object % 2 == 0) {
		if (Empty()) {
			myTop = myLast = new Staque::Node(object, NULL, NULL);
		}
		else {
			myTop->prev = new Staque::Node(object, NULL, myTop);
			myTop = myTop->prev;
		}
		size++;
	}
	else {
		if (Empty()) {
			myTop = myLast = new Staque::Node(object, NULL, NULL);
		}
		else {
			myLast->next = new Staque::Node(object, myLast, NULL);
			myLast = myLast->next;
		}
		size++;
	}
}

void Staque::RemoveFront(int num) {
	if (Empty()) {
		cout << "\t***** Empty List *****" << endl;
		return;
	}
	if (num <= 0) {
		cout << "\t***** Invalid operation *****" << endl;
		return;
	}
	if (EvenMembers() < num) {
		cout << "There is only " << EvenMembers() << " even members to delete, insted of " << num << endl;
		num = EvenMembers();
	}
	int count = 0;
	int total = size;
	while (!Empty() && num != count) {
		Staque::NodePointer ptr = myTop;
		myTop = myTop->next;
		if (total != num) {
			myTop->prev = NULL;
		}
		else {
			myTop == NULL;
			myLast == NULL;
		}
		delete ptr;
		count++;
		size--; 
	}
}

void Staque::RemoveBack(int num) {
	if (Empty()) {
		cout << "\t***** Empty List *****" << endl;
		return;
	}
	if (num <= 0) {
		cout << "\t***** Invalid operation *****" << endl;
		return;
	}
	if (OddMembers() < num) {
		cout << "There is only " << OddMembers() << " odd members to delete, insted of " << num << endl;
		num = OddMembers();
	}
	
	int count = 0;
	int total = size;
	while (!Empty() && num != count) {
		Staque::NodePointer ptr = myLast;
		myLast = myLast->prev;
		if (total != num) {
			myLast->next = NULL;
		}
		else {
			myTop = NULL;
			myLast == NULL;
		}
		delete ptr;
		count++;
		size--;
	}
	
}

int Staque::EvenMembers()const {
	Staque::NodePointer ptr = myTop;
	int result = 0;
	while (ptr != NULL)
	{
		if (ptr->data % 2 == 0)
			result++;
		ptr = ptr->next;
	}
	delete ptr;
	return result;
}
int Staque::OddMembers()const {
	Staque::NodePointer ptr = myTop;
	int result = 0;
	while (ptr != NULL)
	{
		if (ptr->data % 2 != 0)
			result++;
		ptr = ptr->next;
	}
	delete ptr;
	return result;
}