/// ---------------------------------------------------------------------- /
//Kajhal Ghaffary
//ID: 149669178
//Professor: Mohammad Shamas
/************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Gift.h"
using namespace std;
namespace sdds {

	void gifting(char* description) {
		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> description;

	};
	void gifting(double& price) {
		cout << "Enter gift price: ";
		cin >> price;
		cin.ignore(2000, '\n');

		while (price < 0 || price > MAX_PRICE) {
			cout << "Gift price must be between 0 and 999.999" << endl;
			cout << "Enter gift price: ";
			cin >> price;
		}
	}

	void gifting(int& units) {
		cout << "Enter gift units: ";
		cin >> units;
		cin.ignore(2000, '\n');

		while (units < 1) {
			cout << "Gift units must be at least 1" << endl;
			cout << "Enter gift units: ";
			cin >> units;
		}



	}




	bool wrap(Gift& theGift) {
		bool wrap = false;
		if (theGift.m_wrapLayers >= 1) {
			cout << "Gift is already wrapped!" << endl;
		}
		else {
			cout << "Wrapping gifts..." << endl;
			cout << "Enter the number of wrapping layers for the Gift: ";
			cin >> theGift.m_wrapLayers;
			cin.ignore(2000, '\n'); // clear input buffer

			while (theGift.m_wrapLayers <= 0) {
				cout << "Layers at minimum must be 1, try again." << endl;
				cout << "Enter the number of wrapping layers for the Gift: ";
				cin >> theGift.m_wrapLayers;
				cin.ignore(2000, '\n'); // clear input buffer

			}
			int n, i;
			n = theGift.m_wrapLayers;
			theGift.m_wrap = new Wrapping[n];
			char tempBuf[100];
			for (i = 0; i < n; i++) {//done :)
				cout << "Enter wrapping pattern #" << i + 1 << ": ";
				cin >> tempBuf;
				theGift.m_wrap[i].m_pattern = new char[strlen(tempBuf) + 1];
				strcpy(theGift.m_wrap[i].m_pattern, tempBuf);
			}
			
			wrap = true;
		}

		return wrap;
	}

	bool unwrap(Gift& theGift) {
		bool unwrap = true;
		if (!theGift.m_wrapLayers) {
			cout << "Gift isn't wrapped! Cannot unwrap." << endl;
			unwrap = false;
		}
		else {
			cout << "Gift being unwrapped." << endl;
			for (int i = 0; i < theGift.m_wrapLayers; i++) {

				delete[] theGift.m_wrap[i].m_pattern;
				theGift.m_wrap[i].m_pattern = nullptr;

			}

			delete[] theGift.m_wrap;
			theGift.m_wrap = nullptr;

			theGift.m_wrapLayers = 0;
			
			
		}
		return unwrap;
		
	}


	void gifting(Gift& theGift) {
		cout << "Preparing a gift..." << endl;
		gifting(theGift.m_description);
		gifting(theGift.m_price);
		gifting(theGift.m_units);
		wrap(theGift);


	}


	void display(const Gift& gift) {
	/*	char pattern[100];*/
	
			cout << "Gift Details:" << endl;
			cout << " Description: " << gift.m_description << endl;
			cout << "       Price: " << gift.m_price << endl;
			cout << "       Units: " << gift.m_units << endl;
			if (!gift.m_wrapLayers) {
			cout << "Unwrapped!" << endl;
		}

		else {
				
			cout << "Wrap Layers : " << gift.m_wrapLayers << endl;
		
			/*gift.m_wrap[i].m_pattern = new char[strlen(pattern) + 1];
			strcpy(gift.m_wrap[i].m_pattern, pattern );*/
			for (int i = 0; i  < gift.m_wrapLayers; i++) {
				cout << "Wrap #" << i + 1 << " -> " << gift.m_wrap[i].m_pattern << endl;

			}
			
			
		}
	
		
	}




}