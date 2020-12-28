#include<iostream>
using namespace std;

#ifndef STAQUE
#define STAQUE

typedef int StaqueElement;

class Staque {
private:
	class Node {
	public:
		StaqueElement data;
		Node* next;
		Node* prev;
		Node(StaqueElement data = 0, Node* prev = NULL, Node* next = NULL)
			:data(data), prev(prev), next(next)
		{};
	};
	typedef Node* NodePointer;
	StaqueElement size;
	NodePointer myTop;
	NodePointer myLast;

public:
	Staque();
	Staque(const Staque& original);
	~Staque();

	const Staque& operator=(const Staque& rightHandSide);

	bool Empty() const;
	void Display(ostream& out) const;
	void Push(const StaqueElement& object);
	void RemoveFront(int num);
	void RemoveBack(int num);
	int EvenMembers() const;
	int OddMembers() const;

	StaqueElement Top() const;
};

ostream& operator<<(ostream& out, const Staque& aStaque);

#endif // !STAQUE