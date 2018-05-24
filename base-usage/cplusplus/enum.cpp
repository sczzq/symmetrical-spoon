/*************************************************************************
	> File Name: enum.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sun 15 Apr 2018 03:43:12 PM CST
 ************************************************************************/

#include <iostream>

enum class Traffic_light {red, yellow, green};
enum class Warning {green, yellow, orange, red};

enum class Printer_flags {
	acknowledge = 1,
	paper_empty = 2,
	busy = 4,
	out_of_black = 8,
	out_of_color = 16,
	unknown = 32
};

constexpr Printer_flags operator|(Printer_flags a, Printer_flags b)
{
	return static_cast<Printer_flags>((static_cast<int>(a))|(static_cast<int>(b)));
}

constexpr Printer_flags operator&(Printer_flags a, Printer_flags b)
{
	return static_cast<Printer_flags>(static_cast<int>(a)&static_cast<int>(b));
}

constexpr bool operator&&(Printer_flags a, Printer_flags b)
{
	return (static_cast<int>(a)&&static_cast<int>(b));
}

/*
 * 此处不定义也是可以的。
constexpr bool operator==(Printer_flags a, Printer_flags b)
{
	return (static_cast<int>(a) == static_cast<int>(b));
}
*/

void try_to_print(Printer_flags x)
{
	// note
	// x&Printer_flags::acknowledge need 括号.
	if((x&(Printer_flags::acknowledge)) == Printer_flags::acknowledge){
		std::cout << "Printer_flags::acknowledge\n";
	}
	if ((x&Printer_flags::paper_empty) == Printer_flags::paper_empty){
		std::cout << "Printer_flags::paper_empty\n";
	} 
	if ((x&Printer_flags::busy) == Printer_flags::busy){
		std::cout << "Printer_flags::busy\n";
	}
	if ((x&Printer_flags::out_of_black) == Printer_flags::out_of_black){
		std::cout << "Printer_flags::out_of_black\n";
	} 
	if ((x&Printer_flags::out_of_color) == Printer_flags::out_of_color){
		std::cout << "Printer_flags::out_of_color\n";
	} 
	if ((x&Printer_flags::unknown) == Printer_flags::unknown) {
		std::cout << "Printer_flags::unknown\n";
	}
//	if((x&Printer_flags::unknown)){		std::cout << "Printer_flags::unknown\n";	} // error
}

enum class Color_code : char;
void footbar(Color_code * p);

enum class Color_code : char {
	red, yellow, green, blue
};

int main()
{
	Printer_flags x = Printer_flags::paper_empty | Printer_flags::busy | Printer_flags::out_of_black;
	try_to_print(x);
}

