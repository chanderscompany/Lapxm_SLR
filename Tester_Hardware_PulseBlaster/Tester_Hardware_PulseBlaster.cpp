// Tester_Hardware_PulseBlaster.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <stdio.h>
#include <stdlib.h>

#define PB24
#include "spinapi.h"


int main()
{
	int start, status;
	int numBoards;
	double clock;

	numBoards = pb_count_boards();
	if (numBoards != 1) {
		printf("Error no pulseblaser found\n");
		return -1;
	}

	if (pb_init() != 0) {
		printf("Error initializing board: %s\n", pb_get_error());
		return -1;
	}

	// Tell the driver what clock frequency the board has (in MHz)
	clock = 20.0;
	pb_core_clock(clock);


	printf("\nClock frequency: %lfMHz\n\n", clock);
	printf("All outputs should now be turning on and off with a period of "
		"400ms and \n 50 percent duty cycle.\n\n");


	pb_start_programming(PULSE_PROGRAM);

	// Instruction 0 - Continue to instruction 1 in 200ms
	// Flags = 0xFFFFFF, OPCODE = CONTINUE
	start = pb_inst(0xFFFFFF, CONTINUE, 0, 200.0 * ms);

	// Instruction 1 - Continue to instruction 2 in 100ms
	// Flags = 0x0, OPCODE = CONTINUE
	pb_inst(0x0, CONTINUE, 0, 100.0 * ms);

	// Instruction 2 - Branch to "start" (Instruction 0) in 100ms
	// 0x0, OPCODE = BRANCH, Target = start
	pb_inst(0x0, BRANCH, start, 100.0 * ms);

	pb_stop_programming();

	// Trigger the pulse program
	pb_reset();
	pb_start();

	//Read the status register
	status = pb_read_status();
	printf("status: %d \n", status);
	printf(pb_status_message());
	printf("\n");

	pb_stop();
	pb_close();

	return 0;
}



