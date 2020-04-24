#pragma once
#include <iostream>
#include "TestScurt.h"
#include "TestExtins.h"
#include "Multime.h"
#include "IteratorMultime.h"

using namespace std;

int main() {

	testAll();
	cout << "Am trecut de testul scurt!\n";
	testAllExtins();

	cout << "Am trecut de testul extins!\n";
	cout << "Am trecut de toate testele!\n";
	system("pause");
	return 0;
}