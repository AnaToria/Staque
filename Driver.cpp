#include<iostream>
#include "Staque.h"
using namespace std;

int main() {
	Staque s;
	cout << "Staque 'S' is created. Empty? " << boolalpha << s.Empty() << endl;

	s.Push(4);
	cout << "After insertion : " << s << endl;
	s.Push(6);
	cout << "After insertion : " << s << endl;
	s.Push(11);
	cout << "After insertion : " << s << endl;
	s.Push(8);
	cout << "After insertion : " << s << endl;
	s.Push(9);
	cout << "After insertion : " << s << endl;
	s.Push(17);
	cout << "After insertion : " << s << endl;
	
	s.RemoveFront(4);
	cout << "After removing 4 even elements : " << s << endl;
	s.RemoveBack(3);
	cout << "After removing 3 odd elements : " << s << endl;
	s.Push(104);
	cout << "After insertion : " << s << endl;
	cout << "Is 'S' empty? " << boolalpha << s.Empty() << endl;
	
	
	Staque a;
	cout << "\nStaque 'A' is created. Empty? " << boolalpha << a.Empty() << endl;
	a.Push(24);
	cout << "After insertion : " << a << endl;
	a.Push(804);
	cout << "After insertion : " << a << endl;
	a.Push(46);
	cout << "After insertion : " << a << endl;
	a.RemoveBack(5);
	cout << "After requesting to remove 5 odd elements, 'A' : " << a << endl;
	a.Push(7);
	cout << "After insertion : " << a << endl;
	a.RemoveFront(6);
	cout << "After requesting to remove 6 even elements, 'A' : " << a << endl;
	cout << "Is 'A' empty? " << boolalpha << a.Empty() << endl;
	Staque b;
	cout << "\nStaque 'B' is created. Empty? " << boolalpha << b.Empty() << endl;
	b.Push(2);
	cout << "After insertion" << b << endl;
	b.Push(4);
	cout << "After insertion" << b << endl;
	b.Push(6);
	cout << "After insertion" << b << endl;
	b.RemoveFront(3);
	cout << "After requesting to remove 3 even elements, 'B' : " << b << endl;
	b.RemoveBack(3);
	cout << "After requesting to remove 3 odd element, 'B' : " << b << endl;
}