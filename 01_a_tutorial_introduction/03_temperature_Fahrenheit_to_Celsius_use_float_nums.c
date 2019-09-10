#include <stdio.h>

/*print Fahrenheit-Celsius table for fahr = 0, 20, ..., 100*/
void temperature_Fahrenheit_to_Celsius_use_float_nums() {
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;	// lower limit of temperature scale
	upper = 100;	// upper limit
	step = 20;

	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}
