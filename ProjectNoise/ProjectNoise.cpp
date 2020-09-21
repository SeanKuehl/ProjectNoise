//Sean Kuehl
//2020 09 21
//ProjectNoise.cpp
//get user input, if it's valid send to process.h to play it's sounds

#include <iostream>
#include <string>
#include <vector>
#include "Process.h"



bool Contains(char toFind) {
	//check if the given char is a part of the alphabet

	std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	
	for (int i = 0; i < alphabet.size(); i++) {
		if (toFind == alphabet[i]) {
			return true;
			break;
		}
	}
	return false;

}


bool ValidateInput(std::string str) {
	//this will see if there's any pronouncable 
	//character in the input, to see if it's a valid input
	


	
	for (int i = 0; i < str.size(); i++) {
		
		if (Contains(str[i])) {
			//if the char is in the alphabet, return true
			//else return false
			
			return true;
			break;

		}
	}
	return false;
}

std::vector<char> ConvertInput(std::string str) {
	//conert the string into a char array so it's easier to work with
	//when I need to swap the letters with sound files(see Process.h)

	std::vector<char> toReturn;
	for (int i = 0; i < str.size(); i++) {
		toReturn.push_back(str[i]);
	}
	return toReturn;
}

int main()
{
	
	std::string input;
	std::string closeCommand = "!";
	std::vector<char> toPass;	//value to be sent onward to Process.h
    std::cout << "Welcome to Project Noise! Enter some text you want to be turned into speech!\n";
	std::cout << "Enter '!' at anytime to close this application.\n";
	
	while (input != closeCommand) {
		std::getline(std::cin, input);


		
		if (ValidateInput(input) && input != closeCommand) {
			//if input is valid, turn it into char array
			//and pass it to Process.h


			
			toPass = ConvertInput(input);	//convert input to char array
			
			Process process = Process(toPass);

			std::cout << "Enter in another or enter '!' to close.\n";	//once finished, prepare to start the loop again

		}
		else if (input != closeCommand) {
			std::cout << "invalid input\n";
		}
		else {
			//set the program to close on the next loop
			input = closeCommand;
		}
	}
	
	
	

	
	
}








