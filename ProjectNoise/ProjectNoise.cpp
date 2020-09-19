// ProjectNoise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "Process.h"



bool Contains(char toFind) {
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
	//character in the input, to see if it's valid
	


	
	for (int i = 0; i < str.size(); i++) {
		//if the character is in alphabet, return true and break
		if (Contains(str[i])) {
			//this checks if alphabet contains str
			
			return true;
			break;

		}
	}
	return false;
}

std::vector<char> ConvertInput(std::string str) {
	std::vector<char> toReturn;
	for (int i = 0; i < str.size(); i++) {
		toReturn.push_back(str[i]);
	}
	return toReturn;
}

int main()
{
	
	std::string input;
	std::vector<char> toPass;
    std::cout << "Welcome to Project Noise! Enter some text you want to be turned into speech!\n";
	std::cin >> input;
	//note: cin doesn't allow a line of only whitespace, cool!

	//if input is valid, turn it into char array(the only thing the computer will accept later on in comparisons)
	//and pass it to Process
	if (ValidateInput(input)) {
		//convert to char array and pass to process
		toPass = ConvertInput(input);
		std::cout << "valid input";
		Process process = Process(toPass);

	}
	else {
		std::cout << "invalid input";
	}
	
	
	//validate input works
	
	
}







// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
