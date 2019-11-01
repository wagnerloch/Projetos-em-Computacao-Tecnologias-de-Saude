#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
// "Classe" para criar a doença
 typedef struct {
    char diseaseName[50];
    int live;
    int death;
  }Disease;
//lista de doenças para uma avaliação total
   typedef struct  {
    int tam ;
    Disease *diseaseList;
    int totallive;
    int totaldeath;
  }DiseaseList;

int main(int argc, char* argv[]) {

    FILE* csv_file = fopen(argv[1], "r");

    //id,surname,firstname,middlename,gender,gender_male,gender_female,state ,settlement,rural_settlement,urban_settlement,report_date,report_year,age,age_str ,date_of_birth,child_group,adult_group,disease,cholera,diarrhoea,measles,viral_haemmorrhaphic_fever,meningitis,ebola,marburg_virus,yellow_fever,rubella_mars,malaria,serotype     ,NmA,NmC,NmW,health_status,alive,dead,report_outcome,unconfirmed,confirmed,null_serotype
    //1 ,Solade ,Grace    ,Solape    ,Female,0          ,1            ,Rivers,Rural     ,1               ,0               ,2018-05-15 ,2018       ,32 ,32 years,1986-01-17   ,0          ,1          ,Cholera,1      ,0        ,0      ,0                         ,0         ,0    ,0            ,0           ,0           ,0      ,null serotype,0  ,0  ,0  ,alive        ,1    ,0   ,confirmed     ,0          ,1        ,1

    // ignorar;
    char stream [500];
    // Infos

    int id;
    int gender_male;
    int gender_female;
    int rural_settlement;
    int urban_settlement;
    int age;
    int child_group;
    int adult_group;
    int cholera;
    int diarrhoea;
    int measles;
    int viral_haemmorrhaphic_fever;
    int meningitis;
    int ebola;
    int marburg_virus;
    int yellow_fever;
    int rubella_mars;
    int malaria;
    int NmA;
    int NmC;
    int NmW;
    int alive;
    int dead;
    int unconfirmed;
    int confirmed;

    int result;

    while((result = fscanf(csv_file, "%d,%s,%s,%s,%s,%d,%d,%s,%s,%d,%d,%s,%s,%d,%s,%s,%d,%d,%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%s,%d,%d,%d,%s,%d,%d,%s,%d,%d,%d,%s\n", &id, stream, stream, stream, stream, &gender_male, &gender_female, stream , stream, &rural_settlement, &urban_settlement, stream, stream, &age, stream , stream, &child_group, &adult_group, stream, &cholera, &diarrhoea, &measles, &viral_haemmorrhaphic_fever, &meningitis, &ebola, &marburg_virus, &yellow_fever, &rubella_mars, &malaria, stream, &NmA, &NmC, &NmW, stream, &alive, &dead, stream, &unconfirmed, &confirmed, stream)) != EOF) {

        printf("id: %d | male: %d.\n", id, gender_male);
    }
    
    fclose(csv_file);

    return 0;
}
