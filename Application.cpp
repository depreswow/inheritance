#include "Application.h"
#define STRING 1
#define DECIMAL 2
#define EXIT 3


Application::Application() 
	: arr_1(nullptr), arr_2(nullptr) {}

Application::~Application() {
	delete arr_1;
	delete arr_2;
}

void Application::Run() {
	int option;
	do {
		std::cout << R"(Choose:
	1. Work with String
	2. Work with Decimal
	3. Exit)" << std::endl;
		do
			std::cin >> option;
		while (option < 1 || option > 3);
		switch (option) {
		case (STRING):
			Run_String();
			break;
		case (DECIMAL):
			Run_Decimal();
			break;
		}
	} while (option != 3);
}

void Application::Run_String() {
	arr_1 = new String;
	arr_2 = new String;
	String* str_1 = dynamic_cast<String*>(arr_1);
	String* str_2 = dynamic_cast<String*>(arr_2);
	int option, found, index;
	do {
		std::cout << R"(Choose:
	1. Enter string 1
	2. Enter string 2
	3. Find string 2 in string 1
	4. Remove string 2 from string 1
	5. Insert string 2 into string 1
	6. Join string 1 and string 2
	7. Add string 2 to string 1
	8. Exit)" << std::endl;
		do
			std::cin >> option;
		while (option < 1 || option > 8);
		switch (option) {
		case (1):
			try {
				std::cin >> (*str_2);
			}
			catch (const OutOfRangeException& e) {
				std::cerr << e.what() << std::endl;
			}
			break;
		case (2):
			try {
				std::cin >> (*str_2);
			}
			catch (const OutOfRangeException& e) {
				std::cerr << e.what() << std::endl;
			}
			break;
		case (3):
			found = str_1->find(*str_2);
			if (found == 0)
				std::cout << "Not found" << std::endl;
			else
				std::cout << "Found at index " << found << std::endl;
			break;
		case (4):
			if (str_1->remove(*str_2))
				std::cout << "Removed" << std::endl;
			else
				std::cout << "Not possible to remove" << std::endl;
			break;
		case (5):
			std::cout << "Enter an index to insert to" << std::endl;
			std::cin >> index;
			if (str_1->insert(*str_2, index))
				std::cout << "Inserted" << std::endl;
			else
				std::cout << "Not possible to insert" << std::endl;
			break;
		case (6):
			if (str_1->join(*str_2))
				std::cout << "Joined" << std::endl;
			else
				std::cout << "Not possible to join" << std::endl;
			break;
		case (7):
			try {
				arr_1->add(arr_2);
			}
			catch (const IncompatibleSizeException& e) {
				std::cerr << e.what() << std::endl;
			}
			break;
		}
		std::cout << "String 1: " << (*str_1) << std::endl << "String 2: " << (*str_2) << std::endl;
		fflush(stdin);
	} while (option != 8);
	delete arr_1;
	arr_1 = nullptr;
	delete arr_2;
	arr_2 = nullptr;
}

void Application::Run_Decimal() {
	arr_1 = new Decimal;
	arr_2 = new Decimal;
	Decimal* decimal_1 = dynamic_cast<Decimal*>(arr_1);
	Decimal* decimal_2 = dynamic_cast<Decimal*>(arr_2);
	int option;
	do {
		std::cout << R"(Choose:
	1. Enter decimal 1
	2. Enter decimal 2
	3. Decimal 1 + Decimal 2
	4. Decimal 1 - Decimal 2
	5. Decimal 1 * Decimal 2
	6. Decimal 1 > Decimal 2
	7. Decimal 1 < Decimal 2
	8. Add Decimal 2 to Decimal 1
	9. Exit)" << std::endl;
		do
			std::cin >> option;
		while (option < 1 || option > 9);
		switch (option) {
		case (1):
			std::cin >> (*decimal_1);
			break;
		case (2):
			std::cin >> (*decimal_2);
			break;
		case (3):
			try {
				std::cout << (*decimal_1) + (*decimal_2) << std::endl;
			}
			catch (const TooBigException& e) {
				std::cerr << e.what() << std::endl;
			}
			break;
		case (4):
			try {
				std::cout << (*decimal_1) - (*decimal_2) << std::endl;
			}
			catch (const TooBigException& e) {
				std::cerr << e.what() << std::endl;
			}
			break;
		case (5):
			try {
				std::cout << (*decimal_1) * (*decimal_2) << std::endl;
			}
			catch (const TooBigException& e) {
				std::cerr << e.what() << std::endl;
			}
			break;
		case (6):
			std::cout << ((*decimal_1) > (*decimal_2)) << std::endl;
			break;
		case (7):
			std::cout << ((*decimal_1) < (*decimal_2)) << std::endl;
			break;
		case (8):
			try {
				arr_1->add(arr_2);
			}
			catch (const IncompatibleSizeException& e) {
				std::cerr << e.what() << std::endl;
			}
			break;
		}
		std::cout << "Decimal 1: " << (*decimal_1) << std::endl << "Decimal 2: " << (*decimal_2) << std::endl;
	} while (option != 9);
	delete arr_1;
	arr_1 = nullptr;
	delete arr_2;
	arr_2 = nullptr;
}