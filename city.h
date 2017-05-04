#ifndef CITY_H
#define CITY_H

#include "stdafx.h"
#include <iostream>

/**
This is a representation of a City (has name(number) and coordinates)
*/

class City {

public:

	City(const int name, const double xCord, const double yCord);
	~City();

	const int getNumber();
	const double getXCord();
	const double getYCord();

private:
	int number_;
	double xCord_;
	double yCord_;
};

#endif // EDGE
