#include <stdio.h>
#include <stdlib.h> //required for fopen and fprintf

int main(){
    int population = 1000; 
    int birthrate = 0.1;
    int deathrate = 0.05;
    int year = 10;

    //open a file for writing 
    FILE *fp;
    fp = fopen("popln_growth.csv","w");

    //write a header row to file 
    fprintf(fp, "Year, Population\n"); 

    for(int i = 0; i<=year; i++){
        int births = population*birthrate;
        int deaths = population*deathrate;
        population += births-deaths;
        
        // write the current year and population to the file 
        fprintf(fp,"%d,%d\n",i,population);
    }
    // close the file 
    fclose(fp);

    return 0;
}
