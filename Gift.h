#ifndef SDDS_GIFT_H
#define SDDS_GIFT_H
#include <cstring>
namespace sdds {
	const int MAX_DESC = 15;
	const double MAX_PRICE = 999.999;
	const int MAX_WRAP = 20;//p2  //CHANGED FROM CHAR TO INT

	struct Gift {
		char m_description[MAX_DESC + 1];
		double m_price;
		int m_units;
		struct Wrapping* m_wrap; // ADDED NAME "struct" 
		int m_wrapLayers;

	};

	struct Wrapping {
		char* m_pattern;
	};

	void gifting(char* m_description);
	void gifting(double& m_price);
	void gifting(int& m_units);
	bool wrap(Gift& theGift);
	bool unwrap(Gift& theGift);
	void gifting(Gift& theGift);
	void display(const Gift& os);


}

#endif