#include <iostream>

using namespace std;

char sign; // the name "operator" is already taken
int num1, num2, result;

void getData()
{
	cout << "Enter two integers: ";
	cin >> num1 >> num2;
	cout << "Enter an operator: (Enter 'q' to quit) ";
	cin >> sign;
}

void displayResult()
{
	cout << num1 << sign << num2 << '=' << result << endl;
}

void divisionBy0()
{
	cout << "Error: Division by 0.\n";
}

int main()
{
	cout << " __________________ \n|  ______________  |\n| |              | |\n| |______________| |\n|  __  __  __  __  |\n| |%_||/_||*_||-_| |\n|  __  __  __  __  |\n| |7_||8_||9_||+ | |\n|  __  __  __ |  | |\n| |4_||5_||6_||__| |\n|  __  __  __  __  |\n| |1_||2_||3_||= | |\n|  ______  __ |  | |\n| |0_____||._||__| |\n|__________________|\n\n";

	_asm
	{
	WhileLoop:
		call getData;
		cmp sign, 'q';
		je ExitLoop;

		mov eax, num1;
		cmp sign, '+';
		je Addition;
		cmp sign, '-';
		je Subtraction;
		cmp sign, '*';
		je Multiplication;
		cmp sign, '/';
		je Division;

  //Modulo:
		cdq;
		idiv num2;
		mov result, edx;
		call DisplayResult;
		jmp WhileLoop;

	Addition:
		add eax, num2;
		jmp DisplayResult;
	Subtraction:
		sub eax, num2;
		jmp DisplayResult;
	Multiplication:
		imul num2;
		jmp DisplayResult;
	Division:
		cmp num2, 0;
		je DivisionBy0;
		cdq;
		idiv num2;

	DisplayResult:
		mov result, eax;
		call displayResult;
		jmp WhileLoop;

	DivisionBy0:
		call divisionBy0;
		jmp WhileLoop;
	
	ExitLoop:
	}

	return 0;
}