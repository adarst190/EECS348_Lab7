/*
User will input a temperature in Farenheit, Celsius, or Kelvin, and what
temperature scale they want to convert to. The program will then output
the temperature based on the conversion they wanted, and categorize the 
temperature based on given ranges of Celsius degrees. Will also provide
a simple weather advisory based on category
*/

#include <stdio.h>
#include <string.h>

int main(){
    float temp;         //Declare temperature variable
    char scale[20];         //Declare scale variable
    char conversion[20];       //Declare conversion variable
    float converted_temp;      //Declare converted temperature variable
    float categorized_temp;    //Declare categorized temperature variable

    printf("Enter the temperature: ");      //Asks user for temperature
    scanf("%f", &temp);         //Gets input into the variable of temp
    printf("Enter current temperature scale(Farenheit, Celsius, Kelvin): ");       //Asks user for temp scale
    scanf("%s", scale);         //Gets input into the variable of scale
    printf("Enter conversion scale(Farenheit, Celsius, Kelvin): ");        //Asks user for conversion scale
    scanf("%s", conversion);        //Gets input into the variable of conversion

    if (strcmp(scale, "Farenheit") == 0){        //If the scale is Farenheit
        categorized_temp = (temp-32) * 5/9;       //Converts Farenheit to Celsius to categorize temperature   
        if (strcmp(conversion, "Celsius") == 0){     //If the conversion is Celsius
            converted_temp = categorized_temp;       //The converted temperature is the categorized temperature
            printf("The temperature in Celsius is: %.2f\n", converted_temp);       //Prints the converted temperature(.2f rounds to 2 decimal places)
        }else if (strcmp(conversion, "Kelvin") == 0){        //If the conversion is Kelvin
            converted_temp = (temp - 32) * 5/9 + 273.15;        //Converts Farenheit to Kelvin
            printf("The temperature in Kelvin is: %.2f\n", converted_temp);         //Prints the converted temperature  
        }else{
            printf("Invalid conversion scale\n");        //If conversion isn't celsius or kelvin, invalid conversion
            return 1;     //Returns to leave main program
        }
    }else if (strcmp(scale, "Celsius") == 0){        //If the scale is Celsius
        categorized_temp = temp;        //Sets categorized temp to temp
        if(strcmp(conversion, "Farenheit") == 0){        //If the conversion is Farenheit
            converted_temp = (temp * 9/5) + 32;       //Converts Celsius to Farenheit
            printf("The temperature in Farenheit is: %.2f\n", converted_temp);       //Prints the converted temperature
        }else if (strcmp(conversion, "Kelvin") == 0){        //If the conversion is Kelvin
            converted_temp = temp + 273.15;        //Converts Celsius to Kelvin
            printf("The temperature in Kelvin is: %.2f\n", converted_temp);         //Prints the converted temperature
        }else{
            printf("Invalid conversion scale\n");        //If conversion isn't farenheit or kelvin, invalid conversion
            return 1;     //Returns to leave main program
        }
    }else if (strcmp(scale, "Kelvin") == 0){     //If the scale is Kelvin
        categorized_temp = temp - 273.15;        //Converts Kelvin to Celsius to categorize temperature
        if(strcmp(conversion, "Farenheit") == 0){        //If the conversion is Farenheit
            converted_temp = (temp - 273.15) * 9/5 + 32;        //Converts Kelvin to Farenheit
            printf("The temperature in Farenheit is: %.2f\n", converted_temp);       //Prints the converted temperature
        }else if (strcmp(conversion, "Celsius") == 0){        //If the conversion is Celsius
            converted_temp = categorized_temp;        //The converted temperature is the categorized temperature
            printf("The temperature in Celsius is: %.2f\n", converted_temp);       //Prints the converted temperature
        }else{
            printf("Invalid conversion scale\n");        //If conversion isn't farenheit or celsius, invalid conversion
            return 1;     //Returns to leave main program
        }
    }else{
        printf("Invalid temperature scale\n");        //If scale isn't farenheit, celsius, or kelvin, invalid scale
        return 1;    //Returns to leave main program
    }

    if (categorized_temp < 0){          //If celsius temperature is less than 0
        printf("Freezing temperature\n");       //Prints freezing temperature
        printf("Stay indoors, but if you must go outside, wear heavy coat and many layers\n");      //Prints weather advisory
    }else if(categorized_temp < 10){        //If celsius temperature is between 0 and 10
        printf("Cold temperature\n");       //Prints cold temperature
        printf("Wear a coat and heavy pants\n");        //Prints weather advisory
    }else if (categorized_temp < 25){       //If celsius temperature is between 10 and 25
        printf("Comfortable temperature\n");        //Prints comfortable temperature
        printf("Wear a light coat or jacket\n");        //Prints weather advisory
    }else if (categorized_temp < 35){       //If celsius temperature is between 25 and 35
        printf("Hot temperature\n");    //Prints hot temperature
        printf("Wear a t-shirt and shorts\n");      //Prints weather advisory
    }else if(categorized_temp >= 35){       //If celsius temperature is greater than or equal to 35
        printf("Very hot temperature\n");       //Prints very hot temperature
        printf("Stay indoors and drink lots of water\n");       //Prints weather advisory
    }

    return 0;       //Returns 0 to leave main program
}