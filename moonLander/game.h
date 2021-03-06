#pragma once
/*************************************************************
* File: game.h
* Author: Br. Burton
*
* Description: Contains the definition of the game class.
*
* Please DO NOT share this code with other students from
*  other sections or other semesters. They may not receive
*  the same code that you are receiving.
*************************************************************/

#ifndef GAME_H
#define GAME_H

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "ground.h"
#include "lander.h"

#define FUEL        500    // initial fuel for the game
#define MIN_SPEED   3.0    // minimal landing speed
#define FALL_HEIGHT 4.0    // greatest height we can fall from
#define NUM_LIVES   3      // number of lives the lander has

//TODO ask B Comeau for this because goes to fast with 0.1
#define GRAVITY_AMOUNT 0.01 //I changed because it was going to fast

/*****************************************
* GAME
* The main game class containing all the state
*****************************************/
class Game
{
public:
	/*********************************************
	* Constructor
	* Initializes the game
	*********************************************/
	Game(Point tl, Point br) 
		: topLeft(tl), bottomRight(br), ground(Ground(topLeft, bottomRight)),
		lander(Point(bottomRight.getX(), topLeft.getY())),skipFrames(0) //starting above the screen
	{
		// Set up the initial conditions of the game
		lander.setFuel(FUEL);
	}

	/*********************************************
	* Function: handleInput
	* Description: Takes actions according to whatever
	*  keys the user has pressed.
	*********************************************/
	void handleInput(const Interface & ui);

	/*********************************************
	* Function: advance
	* Description: Move everything forward one
	*  step in time.
	*********************************************/
	void advance();

	/*********************************************
	* Function: draw
	* Description: draws everything for the game.
	*********************************************/
	void draw(const Interface & ui);
	
private:
	/*********************************************
	* Function: justLanded
	* Description: Returns true if the lander has
	*  just successfully landed.
	*********************************************/
	bool justLanded() const;
	void drawAltitude() const;
	void drawHorizontalSpeed() const;
	void drawVerticalSpeed() const;
	void drawLives() const;
	void resetGame(); //reset for the next live

	// The coordinates of the screen
	Point topLeft;
	Point bottomRight;
	int skipFrames; //a counter to skip frames
	Ground ground; //has a default constructor that generates the ground
	Lander lander; 

};

#endif /* GAME_H */
