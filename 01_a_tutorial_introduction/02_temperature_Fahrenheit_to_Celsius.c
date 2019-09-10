#include <stdio.h>

/*print Fahrenheit-Celsius table for fahr = 0, 20, ..., 100*/
void temperature_Fahrenheit_to_Celsius() {
	int fahr, celsius;
	int lower, upper, step;

	lower = 0;	// lower limit of temperature scale
	upper = 100;	// upper limit
	step = 20;

	fahr = lower;
	while (fahr <= upper) {
		celsius = 5 * (fahr-32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + step;
	}
}
