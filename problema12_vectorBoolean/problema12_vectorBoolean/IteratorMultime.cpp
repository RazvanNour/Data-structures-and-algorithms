#include "IteratorMultime.h"
#include "Multime.h"
#include <iostream>
using namespace std;

/*
constructor iterator
initializare indice curent cu 0
complexitate: 0(1)
*/
IteratorMultime::IteratorMultime(const Multime & c) : con(c)
{
	this->curent = 0;
}

/*
functia asigneaza indicelui curent pozitia primei valori de 1 din vector
complexitate: O(n)
*/
void IteratorMultime::prim()
{
	for (int i = 0; i < this->con.max - this->con.min + 1; i++) {
		this->curent = i;
		if (this->con.getMultime()[i] == 1) {
			break;
		}
	}
}





/*
functia asigneaza indicelui curent pozitia urmatoarei valori de 1 din vector
complexitate: 0(n)
*/
void IteratorMultime::urmator()
{
	if (this->valid() == false) {
		throw exception();
	}
	int ok = false;
	for (int i = this->curent + 1; i < this->con.max - this->con.min + 1; i++) {
		ok = true;
		this->curent = i;
		if (this->con.getMultime()[i] == 1) {
			break;
		}
	}
	if (ok == false) {
		this->curent += 1;
	}
}

/*
returneaza true daca iteratorul este valid
returneaza false altfel
*/
bool IteratorMultime::valid() const
{
	return (this->curent < this->con.max - this->con.min + 1 && this->con.dim() != 0);
}

TElem IteratorMultime::element() const
{
	if (this->valid() == false) {
		throw exception();
	}
	if (this->con.getMultime()[this->curent] == 1) {
		return this->con.min + this->curent;
	}
	//return -1;
}

