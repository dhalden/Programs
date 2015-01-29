#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void calculation(double temp, double wind)
{
	double chill;
	chill = (35.74 + (0.6215*temp) - (35.75*(pow(wind,0.16))) + (0.4275*temp*pow(wind,0.16)));
	printf("%.1f\t%.1f\t%.1f\n",temp, wind, chill);
}
void calc_chill(double argTemp)
{
	int j;
	for(j=5;j<20;j+=5){
		calculation(argTemp, j);
	}
}

//Wind Chill = 35.74 + 0.6215*T - 35.75*(math.pow(V,0.16)+ 0.4275*T*math.pow(V,0.16))

int main(int argc, char * argv[])
{
	double argTemp;
	double argWind;
	double i;
	char str[20];
	char str2[20];
	argTemp=0;
	argWind=0;
	fflush(stdout);

	if(argc >= 2) {
	sscanf(argv[1], "%lf", &argTemp);
	sscanf(argv[1], "%20s",  str);
	sprintf(str2, "%lf", argTemp);
	int len;
	len = strlen(str);
	str2[len] = '\0';

		if(strcmp(str, str2)){
			printf("Error: you entered a non-numeric entry for temperature\n");
			return 0;
		}
	}
	if(argc == 3) {
		sscanf(argv[2], "%lf", &argWind);
		sscanf(argv[2], "%20s",  str);
		sprintf(str2, "%lf", argWind);
		int len;
		len = strlen(str);
		str2[len] = '\0';

		if(strcmp(str, str2)){
			printf("Error: you entered a non-numeric entry for wind speed\n");
			return 0;
		}
	}
	if(argc > 3){
		printf("Error: Too many arguments provided\n");
		return 0;
	}


	if(argc == 3) {

		//checking valid inputs
		if(argTemp > 50){
			printf("Error: Temperature must be less than 50.0 degrees Fahrenheit\n");
			return 0;
		}
		
		if(argWind <= .5){
			printf("Error: Wind velocity must be greater than 0.5 MPH\n");
			return 0;
		}
		
		printf("Temp\tWind\tChill\n");
		printf("----\t----\t-----\n");
		calculation(argTemp, argWind);
	}
	else if(argc == 2) {
		if(argTemp > 50){
			printf("Temperature must be less than 50.0 degrees Fahrenheit\n");
			return 0;
		}
		printf("Temp\tWind\tChill\n");
		printf("----\t----\t-----\n");
		calc_chill(argTemp);
	}
	else {
		printf("Temp\tWind\tChill\n");
		printf("----\t----\t-----\n");
		for(i=-10; i<40; i+=10) {
			calc_chill(i);
			printf("\n");
		}
	}


	return 0;
}
