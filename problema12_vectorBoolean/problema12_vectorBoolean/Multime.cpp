#include "Multime.h"
#include "IteratorMultime.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

/*
constructorul multimii
se initializeaza min si max
complexitate: 0(1)
*/
Multime::Multime()
{
	this->min = -10;
	this->max = 9;
	this->v = (TElem*)calloc((this->max - this->min + 1), sizeof(TElem));
}

void Multime::Schema()
{
	free(this->v);
	this->min = -10;
	this->max = 9;
	this->v = (TElem*)calloc((this->max - this->min + 1), sizeof(TElem));
}

/*
functie de redimensionare la stanga
in momentul in care valoarea adaugata este mai mica decat min
complexitate: 0(n)
*/
void Multime::resizeLeft(Multime *m, int val)
{
	int nCap = this->max - val + 1;
	int cu_cat = this->min - val;
	TElem* nElems = (TElem*)calloc(nCap, sizeof(TElem));
	nElems[0] = 1;
	for (int i = 0; i < this->max - this->min + 1; i++) {
		nElems[i + cu_cat] = m->v[i];
	}
	free(m->v);
	m->v = nElems;
	m->min = val;
}

/*
functie de redimensionare la dreapta
in momentul in care se adauga o valoare mai mare decat max
complexitate: 0(n)
*/
void Multime::resizeRight(Multime *m, int val)
{
	int nCap = val - this->min + 1;
	TElem* nElems = (TElem*)calloc(nCap, sizeof(TElem));
	for (int i = 0; i < this->max - this->min + 1; i++) {
		nElems[i] = m->v[i];
	}
	nElems[nCap - 1] = 1;
	free(m->v);
	m->v = nElems;
	m->max = val;
}

/*
functie de adaugare a unui element
returneaza true daca elementul a fost adaugat
returneaza false altfel
complexitate: 0(1)
*/
bool Multime::adauga(TElem e)
{
	if (e < this->min) {
		this->resizeLeft(this, e);
		return true;
	}
	else if (e > this->max) {
		this->resizeRight(this, e);
		return true;
	}
	else {
		if (this->v[e - this->min] == 0) {
			this->v[e - this->min] = 1;
			return true;
		}
	}
	return false;
}



/*
functie care sterge un element din vector, schimband valoarea 1 in 0
returneaza true daca s-a reusit "stergerea"
returneaza false altfel
complexitate: 0(1)
*/
bool Multime::sterge(TElem e)
{
	if (e<this->min || e>this->max || this->v[e - this->min] == 0) {
		return false;
	}
	this->v[e - this->min] = 0;
	return true;
}



/*
functia returneaza pointer spre multime
*/
TElem * Multime::getMultime() const
{
	return this->v;
}

/*
functia "cauta" un element in multime
returneaza true daca valorea de pe pozitia asociata el este 1
returneaza false altfel
complexitate: 0(n)
*/
bool Multime::cauta(TElem elem) const
{
	if (this->v[elem - this->min] == 1) {
		return true;
	}
	return false;
}

/*
functia returneaza nr valorilor de 1 din vector("dimensiunea" acestuia)
complexitate: 0(n)
*/
int Multime::dim() const
{
	int nrValori = 0;
	for (int i = 0; i < this->max - this->min + 1; i++) {
		if (this->v[i] == 1)
			nrValori++;
	}
	return nrValori;
}

/*
functia returneaza true daca "dimensiunea" vectorului este vida
returneaza false altfel
complexitate: 0(1)
*/
bool Multime::vida() const
{
	return this->dim()==0;
	
}

/*
functia returneaza un iterator pe multime
complexitate: 0(1)
*/
IteratorMultime Multime::iterator() const
{
	return IteratorMultime(*this);
}

/*
destructorul multimii
se elibereaza memoria ocupata de vectorul v
*/
Multime::~Multime()
{
	free(this->v);
}
