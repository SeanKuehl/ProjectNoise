//Sean Kuehl
//2020 09 21
//Process.h
//take a char array, convert it to sound file paths and play it



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



#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll



class Process
{
public:

	
	
	
	

	

	Process(std::vector<char> input) {
		inputList = input;	//make the global list equal to input for easier handling
		
		
		
		ReplacePause();
		RemoveDoubles();
		RemoveJunk();	//remove any characters that don't matter for my purposes
		PathReplace();	//replace each char with the path to an audio file
		PlaySounds();	
		
	}

	


private:

	std::vector<char> inputList;	
	std::vector<std::string> outputList;	//this will be the list of paths to sound files

	//every time irrklang is instantiated it output text to the screen.
	//in order to minimize this, they are made globals
	ISoundEngine* engine = createIrrKlangDevice();
	irrklang::ISound* snd;

	bool Contains(char toFind, std::string toReplace) {
		

		//below is unsigned int in order to remove signed/unsigned mismatch compiler warning
		for (unsigned int i = 0; i < toReplace.size(); i++) {
			if (toFind == toReplace[i]) {
				return true;
				break;
			}
		}
		return false;

	}

	void ReplacePause() {
		
		//this will replace every peice of pause punctuation with the period
		//so later they can be more easily replaced with sound files
		
		
		//below is unsigned int in order to remove signed/unsigned mismatch compiler warning
		for (unsigned int i = 0; i < inputList.size(); i++) {
			if (Contains(inputList[i], "!?,;:")) {
				inputList[i] = '.';
			}
		}

		
		
	}

	void RemoveDoubles() {
		//remove double spacing and characters like the second 'b' in 'abba'
		
		//below is unsigned int in order to remove signed/unsigned mismatch compiler warning
		for (unsigned int i = 1; i < inputList.size(); i++) {
			if (inputList[i] == inputList[i-1]) {
				
				
				inputList.erase(inputList.begin() + i);
			}
			
		}
		
		
	}

	void RemoveJunk() {
		//remove characters that have no effect on the output unlike a pause or a letter

		std::string alphabetAndPeriod = "!?,;:ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ";
		
		
		//below is unsigned int in order to remove signed/unsigned mismatch compiler warning
		for (unsigned int i = 0; i < inputList.size(); i++) {
			if (Contains(inputList[i], alphabetAndPeriod)) {
				//if the character has an effect, do nothing
			}
			else {
				//it's something I want to get rid of, so...
				inputList.erase(inputList.begin() + i);
				
			}
		}
	}

	void PathReplace() {
		//replace each char with the path to their sound file
		std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		char listItem;
		char alphabetItem;
		std::string outputListItem;
		

		//below is unsigned int in order to remove signed/unsigned mismatch compiler warning
		for (unsigned int i = 0; i < inputList.size(); i++) {
			listItem = inputList[i];
			
			//periods and spaces have no sound file and are instead pauses
			//so they are replaced with a simple string equivalent
			if (listItem == '.') {
				outputList.push_back("..");
			}
			else if (listItem == ' ') {
				outputList.push_back("  ");
			}
			else {
				
				//below is unsigned int in order to remove signed/unsigned mismatch compiler warning
				for (unsigned int j = 0; j < alphabet.size(); j++) {
					if (alphabet[j] == listItem) {
						//item could be lower case,
						//but all files are upper case
						alphabetItem = alphabet[j];
						alphabetItem = toupper(alphabetItem);	//make alphaitem uppercase
						outputListItem += alphabetItem;	//add file name, 'A' etc
						outputListItem += ".wav";	//add file extension so it's now 'A.wav'
						
						outputList.push_back(outputListItem);
						
						outputListItem = "";	//clear/empty outputListItem so it's ready for the next iteration

					}
			}

			
			}

			


		}
	}

	

	

	
		

	void PlaySounds() {
		

		std::cout << "\n";	//the irrklang devices will print text to the screen before this function is called
		
		
		char const* sound = "";	//this is used for conversions from string to const char
		std::string str;
		

		//below is unsigned int in order to remove signed/unsigned mismatch compiler warning
		for (unsigned int counter = 0; counter < outputList.size(); counter++) {
			str = outputList[counter];
			
			sound = str.c_str();	//convert string to const char so play2D will accept it
			if (str.compare("..") == 0) {
				

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

					
					while (snd->isFinished() == false) {
						
					}
					
					break;	//once the sound is finished, go to the next one
					

				} while (_getch() != 'q');
				


			}
		}





	}

	

	
	

	



	void WaitS(int seconds) {
		
		time_t timer;
		time_t start;
		bool running = true;

		time(&start);
		time(&timer);	
		

		while (running) {
			time(&timer);
			if (timer >= (start + seconds)) {
				running = false;
				
			}
		}

	}

	void WaitM(milliseconds milis) {
		
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

