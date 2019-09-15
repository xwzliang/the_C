/*We started the array daytab with a column of zero so that month numbers can run from the natural 1 to 12 instead of 0 to 11. Since space is not at a premium here, this is clearer than adjusting the indices.*/
static char daytable[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},    
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

/*day_of_year: set day of year from month & day*/
int day_of_year(int year, int month, int day) {
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; i < month; i++)
		day += daytable[leap][i];
	return day;
}

/*month_day: set month, day from day of year*/
void month_day(int year, int yearday, int *pmonth, int *pday) {
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; yearday > daytable[leap][i]; i++)
		yearday -= daytable[leap][i];
	*pmonth = i;
	*pday = yearday;
}
