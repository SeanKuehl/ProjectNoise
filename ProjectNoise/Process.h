#pragma once
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>
#include <time.h>

#include <Windows.h>
#include <stdlib.h>
#include <chrono>
#include <stdio.h>
#include "irrKlang.h"
#if defined(WIN32)
#include <conio.h>
#else
#include "../common/conio.h"
#endif




using namespace irrklang;
using namespace std::chrono;

// To be able to use the irrKlang.dll file, we need to link with the irrKlang.lib.
// We could set this option in the project settings, but to make it easy we use
// a pragma comment:

#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll



class Process
{
public:

	//this is needed so SoundEndReceiver can communicate
	
	
	void CallPlaySounds(int i) {
		std::cout << "this is a good sign";
		//PlaySounds(i);

	}

	

	Process(std::vector<char> input) {
		inputList = input;
		
		//Test();
		
		ReplacePause();
		RemoveSpacing();
		RemoveJunk();
		PathReplace();
		PlaySounds(0);
	}

	


private:

	std::vector<char> inputList;	//this is so I don't have to keep returning it
	std::vector<std::string> outputList;	//this will be the list of paths

	bool Contains(char toFind, std::string toReplace) {
		


		for (int i = 0; i < toReplace.size(); i++) {
			if (toFind == toReplace[i]) {
				return true;
				break;
			}
		}
		return false;

	}

	void ReplacePause() {
		//after testing, this func works!
		//this will replace every peice of pause punctuation with the period
		//to limit the number of cases later
		
		

		for (int i = 0; i < inputList.size(); i++) {
			if (Contains(inputList[i], "!?,;:")) {
				inputList[i] = '.';
			}
		}

		
		
	}

	void RemoveSpacing() {
		//this will remove redundant spacing to prevent
		//uneeded delays later
		
		for (int i = 1; i < inputList.size(); i++) {
			if (inputList[i] == inputList[i-1]) {
				//if this element is the same as the last
				//whether it's space or second b in abba
				//then remove it
				inputList.erase(inputList.begin() + i);
			}
			
		}
		
		
	}

	void RemoveJunk() {
		//remove useless punctuation and 
		//things that aren't a part of the alphabet or what I'll pronounce
		std::string alphabetAndPeriod = "!?,;:ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ";
		
		//don't forget to add a space to above!

		for (int i = 0; i < inputList.size(); i++) {
			if (Contains(inputList[i], alphabetAndPeriod)) {
				//then do nothing, it's fine
			}
			else {
				//it's something I want to get rid of, so...
				inputList.erase(inputList.begin() + i);
				//delete it
			}
		}
	}

	void PathReplace() {
		

		//replace each char with the path to their sound
		std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

		//the best thing I can think of to assign the paths is a giant switch statement, there must be something better?
		
		for (int i = 0; i < inputList.size(); i++) {
			if (inputList[i] == 'a' || inputList[i] == 'A') {
				outputList.push_back("A.wav");	//add the 'a' path
			}
			else if (inputList[i] == 'b' || inputList[i] == 'B') {
				outputList.push_back("B.wav");	//add the 'b' path
			}
			else if (inputList[i] == 'c' || inputList[i] == 'C') {
				outputList.push_back("C.wav");	//add the 'c' path
			}
			else if (inputList[i] == 'd' || inputList[i] == 'D') {
				outputList.push_back("D.wav");	//add the 'd' path
			}
			else if (inputList[i] == 'e' || inputList[i] == 'E') {
				outputList.push_back("E.wav");	//add the 'e' path
			}
			else if (inputList[i] == 'f' || inputList[i] == 'F') {
				outputList.push_back("F.wav");	//add the 'f' path
			}
			else if (inputList[i] == 'g' || inputList[i] == 'G') {
				outputList.push_back("G.wav");	//add the 'g' path
			}
			else if (inputList[i] == 'h' || inputList[i] == 'H') {
				outputList.push_back("H.wav");	//add the 'h' path
			}
			else if (inputList[i] == 'i' || inputList[i] == 'I') {
				outputList.push_back("I.wav");	//add the 'i' path
			}
			else if (inputList[i] == 'j' || inputList[i] == 'J') {
				outputList.push_back("J.wav");	//add the 'j' path
			}
			else if (inputList[i] == 'k' || inputList[i] == 'K') {
				outputList.push_back("K.wav");	//add the 'k' path
			}
			else if (inputList[i] == 'l' || inputList[i] == 'L') {
				outputList.push_back("L.wav");	//add the 'l' path
			}
			else if (inputList[i] == 'm' || inputList[i] == 'M') {
				outputList.push_back("M.wav");	//add the 'm' path
			}
			else if (inputList[i] == 'n' || inputList[i] == 'N') {
				outputList.push_back("N.wav");	//add the 'n' path
			}
			else if (inputList[i] == 'o' || inputList[i] == 'O') {
				outputList.push_back("O.wav");	//add the 'o' path
			}
			else if (inputList[i] == 'p' || inputList[i] == 'P') {
				outputList.push_back("P.wav");	//add the 'p' path
			}
			else if (inputList[i] == 'q' || inputList[i] == 'Q') {
				outputList.push_back("Q.wav");	//add the 'q' path
			}
			else if (inputList[i] == 'r' || inputList[i] == 'R') {
				outputList.push_back("R.wav");	//add the 'r' path
			}
			else if (inputList[i] == 's' || inputList[i] == 'S') {
				outputList.push_back("S.wav");	//add the 's' path
			}
			else if (inputList[i] == 't' || inputList[i] == 'T') {
				outputList.push_back("T.wav");	//add the 't' path
			}
			else if (inputList[i] == 'u' || inputList[i] == 'U') {
				outputList.push_back("U.wav");	//add the 'u' path
			}
			else if (inputList[i] == 'v' || inputList[i] == 'V') {
				outputList.push_back("V.wav");	//add the 'v' path
			}
			else if (inputList[i] == 'w' || inputList[i] == 'W') {
				outputList.push_back("W.wav");	//add the 'w' path

			}
			else if (inputList[i] == 'x' || inputList[i] == 'X') {
				outputList.push_back("X.wav");	//add the 'x' path
			}
			else if (inputList[i] == 'y' || inputList[i] == 'Y') {
				outputList.push_back("Y.wav");	//add the 'a' path
			}
			else if (inputList[i] == 'z' || inputList[i] == 'Z') {
				outputList.push_back("Z.wav");	//add the 'a' path
			}
			else if (inputList[i] == '.') {
				//replace it with double so it's a string and not a char
				outputList.push_back("..");
			}
			else if (inputList[i] == ' ') {
				//replace it with double so it's a string and not a char
				outputList.push_back("  ");
			}

				
		}

	}

	void PlaySounds(int counter) {
		//I need to make my own sleep/wait function

		std::cout << "\n";
		ISoundEngine* engine = createIrrKlangDevice();
		
		char const * sound = "";	//this is needed for conversions
		std::string str;


		for (counter; counter < outputList.size(); counter++) {
			str = outputList[counter];
			//it reaches here and output what I'd expect
			sound = str.c_str(); //if I can do this, sound works without errors in play2d
			if (str.compare("..") == 0) {
				//all of them went here, there is something wrong with str.compare("..");
				//str.compare() returns 0 if it's equal but I wasn't accounting for that

				//if it's a period
			//wait for a second
				WaitS(1);
			}
			else if (str.compare("  ") == 0) {
				//if it's a space
				
				//wait for half a second
				WaitM((milliseconds)500);

			}
			else {
				//try the case "hello there!" it seems to have trouble
				//for now it works for any single word
				

				do {
					
					irrklang::ISound* snd = engine->play2D(sound, false, false, true);
					
					//engine->play2D(str.c_str(), true);
					while (snd->isFinished() == false) {
						//do nothing
					}
					PlaySounds(counter+1);
					//engine->play2D("getout.ogg");

				} while (_getch() != 'q');
				//it's a letter with a sound, play that sound
				//irrklang::ISound * source is what str must become


			}
		}






		//do
		//{
			//must be a do while loop


			// play a single sound
			//engine->play2D("getout.ogg", true);	//second param is to do it looped
			//second param is to do it looped, true means it's looped
			//engine->play2D("A.wav");

			//it's default directory is the ProjectNoise directory

			//I have a Music folder that will hold all of my sound files
		//} while (_getch() != 'q');


		//engine->drop(); // delete engine


		//cannot convert from const char to LPCWSTR
	}

	
		//for item in string list(but I'll have to treat these like chars because they're singles)



	void God() {
		std::cout << "yo momma";
		std::cout << "\n";
	}

	
	

	void Test() {
		bool done = false;
		std::cout << "\n";
		std::string str = "A.wav";
		ISoundEngine* engine = createIrrKlangDevice();
		//my wav files play, so it's not that
		
		
		char const * sound = "getout.ogg";	//this is needed for conversions


		
			
			//str.c_str()
		do {
			
			irrklang::ISound* snd = engine->play2D(str.c_str(), false, false, true);
			//engine->play2D(str.c_str(), true);
			while (snd->isFinished() == false) {
				//do nothing
			}
			God();
			//if it's reached here, it's done, in theory

			
				//snd->setSoundStopEventReceiver(endR);
				//done =  irrklang::ISoundEngine::isCurrentlyPlaying(snd);
				
				//a nonstatic member reference must be relative to a specific object
				//only continue the loop once the sound is done, call this func in the endR func
			
			

			
			
			
			//engine->play2D("getout.ogg", true);

		} while (_getch() != 'q');
		
		
		
		//irrklang::ISound* snd = engine->play2D(str.c_str(), false, false, true);
		//if (snd) {
		//	snd->setSoundStopEventReceiver(endR);
		//}

	}



	void WaitS(int seconds) {
		//yay! I made my own wait function!
		//only works for full seconds
		time_t timer;
		time_t start;
		bool running = true;

		time(&start);
		time(&timer);	//this is just so it's initialized
		

		while (running) {
			time(&timer);
			if (timer >= (start + seconds)) {
				running = false;
				
			}
		}

	}

	void WaitM(milliseconds milis) {
		//this will be the mili wait function, and I'm pretty sure it works!
		milliseconds start = duration_cast<milliseconds>(
			system_clock::now().time_since_epoch());

		milliseconds now = duration_cast<milliseconds>(
			system_clock::now().time_since_epoch());

		bool running = true;
		
		while (running) {
			now = duration_cast<milliseconds>(
				system_clock::now().time_since_epoch());
			if (now >= (start + milis)) {
				running = false;
			}
		}
	}

};

