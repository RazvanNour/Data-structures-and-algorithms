#pragma once
#include "IteratorMultime.h"
//#include <vector>


//using namespace std;
typedef int TElem;
class IteratorMultime;

class Multime {
	friend class IteratorMultime;
private:
	//* aici e reprezentarea */
	TElem* v;
	int min;
	int max;

public:
	//constructorul implicit
	Multime();
	void Schema();
	TElem* getMultime() const;

	//adauga un element in multime
	//returneaza adevarat daca elementul a fost adaugat (nu exista deja in multime)
	bool adauga(TElem e);

	//sterge un element din multime
	//returneaza adevarat daca elementul a existat si a fost sters
	bool sterge(TElem e);

	//verifica daca un element se afla in multime
	bool cauta(TElem elem) const;

	//intoarce numarul de elemente din multime;
	int dim() const;

	//verifica daca multimea e vida;
	bool vida() const;

	//returneaza un iterator pe multime
	IteratorMultime iterator() const;

	//redimensioneaza la stanga
	void resizeLeft(Multime*, int);

	//redimensioneaza la dreapta
	void resizeRight(Multime*, int);

	// destructorul multimii
	~Multime();

};