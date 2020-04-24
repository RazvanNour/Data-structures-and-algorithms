#pragma once
#include "Multime.h"

class Multime;
typedef int TElem;

class IteratorMultime
{
	friend class Multime;

private:
	//iteratorul memoreaza o referinta catre container
	//const Container& con;
	//aici alte atribute specifice: curent, etc
	//IteratorContainer(const Container& c);

	const Multime& con; //referinta spre containerul pe care il itereaza
	int curent=0;

public:
	IteratorMultime(const Multime& c);

	void prim();

	void urmator();

	bool valid() const;

	TElem element() const;
	

	//~IteratorMultime();
};