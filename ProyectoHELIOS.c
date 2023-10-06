//14_Dynnks_Cruz
//Proyecto Helios
#include <stdio.h>
#include <stdlib.h>

/*
Entrada: Ingrese fecha (día, mes, año_opcional )
Salida: Días transcurridos del año
*/
int dd,mm,aaaa,diasT=0;
int compYSum();

int main(){
    printf("PROYECTO HELIOS\nEste programa calcula la cantidad de días transcurridos\nen un año dada una fecha");
    
    char dia[5], mes[5], anio[7];
    
    printf("\n\nPor favor, ingresa la fecha que desees\n    DD: ");
    fgets(dia,5,stdin);
    dd=strtol(dia,NULL,10);
    printf("    MM: ");
    fgets(mes,5,stdin);
    mm=strtol(mes,NULL,10);
    printf("    AAAA (opcional): ");
    fgets(anio,5,stdin);
    aaaa=strtol(anio,NULL,10);
    
    if(compYSum()==0){
        printf("\n\nHan transcurrido %d días en el año",diasT);
        printf("\nHasta el %2d/%2d/%4d",dd,mm,aaaa);
    }else{
        printf("\n\nLa fecha que ingresaste no es real");
    }
    
    return 0;
}

int compYSum(){
    int cmp=1;
    if(aaaa==0){
        aaaa=2023;
    }
    if(mm>0&&mm<13){
        int diasPmes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(((aaaa%4)==0&&(aaaa%100)!=0)||((aaaa%400)==0)){
            diasPmes[2] = 29;
        }
        if(dd>0&&dd<=diasPmes[mm]){
            cmp=0;
            for(int i=1;i<mm;i++){
                diasT=diasT+diasPmes[i];
            }
            diasT=diasT+dd;
        }
    }
    return cmp;
}
