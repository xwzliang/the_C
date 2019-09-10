#include <stdio.h>

/*print Fahrenheit-Celsius table for fahr = 0, 20, ..., 100*/
void temperature_Fahrenheit_to_Celsius_use_for_loop() {
	int fahr;

	for (fahr = 0; fahr <= 100; fahr = fahr + 20)
		printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32.0));
}
