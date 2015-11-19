/*
 * ROSSyncApplication.cpp
 *
 *  Created on: 19. 11. 2015
 *      Author: Vlaimir Matena
 */

#include <iostream>
#include <iomanip>
#include <unistd.h>

#include "ROSSyncApplication.h"

Define_Module (ROSSyncApplication);

using namespace std;

ROSSyncApplication::ROSSyncApplication() {
	cout << "ROSSyncApplication constructor" << endl;
}

void ROSSyncApplication::initialize(int stage) {
	cout << "ROSSyncApplication init " << stage << endl;

	if (stage == 0) {
		scheduleAt(0, syncMsg);
	}
}

void ROSSyncApplication::handleMessage(cMessage *msg) {
	// Handle time synchronization message
	if(msg == syncMsg) {
		cout << "ROSSyncPoint at " << setw(8) << fixed << simTime() << endl;

		// Sync with ROS
		// TODO: This is very primitive code
		usleep(TIME_STEP * 1000000);

		// Schedule next sync invocation
		scheduleAt(simTime() + TIME_STEP, syncMsg);
	}
}
