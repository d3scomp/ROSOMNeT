#include <iostream>

#include "Simulation.h"

int main() {
	std::cout << "ROSOMNeT++ starting up" << std::endl;

	Simulation *sim = new Simulation("config.ini");
	sim->runSimulation();
}
