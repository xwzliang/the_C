#include <stdio.h>

/*It's bad practice to bury "magic numbers" like 300 and 20 in a program; they convey little information to someone who might have to read the program later, and they are hard to change in a systematic way. One way to deal with magic numbers is to give them meaningful names. A #define line defines a symbolic name or symbolic constant to be a particular string of characters:*/
#define LOWER 0		// lower limit of table
#define UPPER 100		// upper limit of table
#define STEP 20
/*The quantities LOWER, UPPER and STEP are symbolic constants, not variables, so they do not appear in declarations. Symbolic constant names are conventionally written in upper case so they can be readily distinguished from lower case variable names. Notice that there is no semicolon at the end of a #define line.*/

/*print Fahrenheit-Celsius table for fahr = 0, 20, ..., 100*/
void temperature_Fahrenheit_to_Celsius_use_symbolic_constants() {
	int fahr;

	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32.0));
}
