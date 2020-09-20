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
	
	
	

	

	Process(std::vector<char> input) {
		inputList = input;
		
		//Test();
		
		ReplacePause();
		RemoveSpacing();
		RemoveJunk();
		PathReplace();
		PlaySounds();
		//PlaySounds(0);
	}

	


private:

	std::vector<char> inputList;	//this is so I don't have to keep returning it
	std::vector<std::string> outputList;	//this will be the list of paths
	ISoundEngine* engine = createIrrKlangDevice();
	irrklang::ISound* snd;

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
		char listItem;
		char alphabetItem;
		std::string outputListItem;
		//the best thing I can think of to assign the paths is a giant switch statement, there must be something better?

		//note: fix this! This is disgusting!
		for (int i = 0; i < inputList.size(); i++) {
			listItem = inputList[i];
			//check for spaces and periods here!

			if (listItem == '.') {
				outputList.push_back("..");
			}
			else if (listItem == ' ') {
				outputList.push_back("  ");
			}
			else {
				for (int j = 0; j < alphabet.size(); j++) {
					if (alphabet[j] == listItem) {
						//item could be lower case,
						//but all files are upper case
						alphabetItem = alphabet[j];
						alphabetItem = toupper(alphabetItem);	//make alphaitem uppercase
						outputListItem += alphabetItem;
						outputListItem += ".wav";
						
						outputList.push_back(outputListItem);
						//get outputListItem ready for the next iteration
						outputListItem = "";

					}
			}

			
			}

			


		}
	}

	

	

	
		//for item in string list(but I'll have to treat these like chars because they're singles)

	void PlaySounds() {
		//why can't it just take in a list/vector as input?
		//make a new and better playsounds func that doesn't call itself

		std::cout << "\n";
		//ISoundEngine* engine = createIrrKlangDevice();
		//irrklang::ISound* snd;
		//make the irrklang devices global so I'm not calling them anew each
		//time I call this function
		char const* sound = "";	//this is needed for conversions
		std::string str;
		


		for (int counter = 0; counter < outputList.size(); counter++) {
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



				do {

					snd = engine->play2D(sound, false, false, true);

					//engine->play2D(str.c_str(), true);
					while (snd->isFinished() == false) {
						//do nothing
					}
					
					break;
					//PlaySounds(counter + 1);	//play the next sound

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

