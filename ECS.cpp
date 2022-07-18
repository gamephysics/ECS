// ECS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ECS.h"

int main()
{
	//===============================================
	// ECS WORLD LOOP
	//===============================================
	FieldWorld world(100);	// 100 ms interval update
	
	world.Loop();

}
