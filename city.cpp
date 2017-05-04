#include "stdafx.h"
#include "city.h"

City::City(const int number, const double xCord, const double yCord):
	number_(number), xCord_(xCord), yCord_(yCord){}

City::~City(){}

const int City::getNumber() {
	return number_;
}

const double City::getXCord() {
	return xCord_;
}

const double City::getYCord() {
	return yCord_;
}
