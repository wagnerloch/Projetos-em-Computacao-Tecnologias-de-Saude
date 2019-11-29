#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa {
	int id;
	char surname[20];
	char firstname[20];
	char middlename[20];
	char gender[20];
	int gender_male;
	int gender_female;
	char state[20];
	char settlement[20];
	int rural_settlement;
	int urban_settlement;
	char report_date[20];
	int report_year;
	int age;
	char age_str[20];
	char date_of_birth[20];
	int child_group;
	int adult_group;
	char disease[20];
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
	char serotype[20];
	int NmA;
	int NmC;
	int NmW;
	char health_status[20];
	int alive;
	int dead;
	char report_outcome[20];
	int unconfirmed;
	int confirmed;
	int null_serotype;
} pessoa[288500];

struct doenca {
    int infectados;
    int mortos;
    int urbano;
    int rural;
    int feminino;
    int masculino;
} cholera,diarrhoea,measles,viral_haemmorrhaphic_fever,meningitis,ebola,marburg_virus,yellow_fever,rubella_mars,malaria;



int lerDataSet ();
void inicializarEstruturas ();
void buscarDoencas ();
void imprimirResultados ();

int qtdPessoas;

int main () {

	inicializarEstruturas ();	
	qtdPessoas = lerDataSet ();
	buscarDoencas ();	
	imprimirResultados ();	
	
    return 0;
}



void inicializarEstruturas () {
	//cholera
    cholera.infectados = 0;
    cholera.mortos = 0;
    cholera.urbano = 0;
    cholera.rural = 0;
    cholera.feminino = 0;
    cholera.masculino = 0;
    //diarrhoea
    diarrhoea.infectados = 0;
    diarrhoea.mortos = 0;
    diarrhoea.urbano = 0;
    diarrhoea.rural = 0;
    diarrhoea.feminino = 0;
    diarrhoea.masculino = 0;
    //measles
    measles.infectados = 0;
    measles.mortos = 0;
    measles.urbano = 0;
    measles.rural = 0;
    measles.feminino = 0;
    measles.masculino = 0;
    //viral_haemmorrhaphic_fever
    viral_haemmorrhaphic_fever.infectados = 0;
    viral_haemmorrhaphic_fever.mortos = 0;
    viral_haemmorrhaphic_fever.urbano = 0;
    viral_haemmorrhaphic_fever.rural = 0;
    viral_haemmorrhaphic_fever.feminino = 0;
    viral_haemmorrhaphic_fever.masculino = 0;
    //meningitis
    meningitis.infectados = 0;
    meningitis.mortos = 0;
    meningitis.urbano = 0;
    meningitis.rural = 0;
    meningitis.feminino = 0;
    meningitis.masculino = 0;
    //ebola
    ebola.infectados = 0;
    ebola.mortos = 0;
    ebola.urbano = 0;
    ebola.rural = 0;
    ebola.feminino = 0;
    ebola.masculino = 0;
    //marburg_virus
    marburg_virus.infectados = 0;
    marburg_virus.mortos = 0;
    marburg_virus.urbano = 0;
    marburg_virus.rural = 0;
    marburg_virus.feminino = 0;
    marburg_virus.masculino = 0;
    //yellow_fever
    yellow_fever.infectados = 0;
    yellow_fever.mortos = 0;
    yellow_fever.urbano = 0;
    yellow_fever.rural = 0;
    yellow_fever.feminino = 0;
    yellow_fever.masculino = 0;
    //rubella_mars
    rubella_mars.infectados = 0;
    rubella_mars.mortos = 0;
    rubella_mars.urbano = 0;
    rubella_mars.rural = 0;
    rubella_mars.feminino = 0;
    rubella_mars.masculino = 0;
    //malaria
    malaria.infectados = 0;
    malaria.mortos = 0;
    malaria.urbano = 0;
    malaria.rural = 0;
    malaria.feminino = 0;
    malaria.masculino = 0;
}

int lerDataSet () {
	FILE *fp = fopen("dataset.csv", "r");

    if (!fp) {
        printf("Can't open file\n");
        return 0;
    }

    char buf[1024];
    int i = 0;
    int field_count = 0;
    while (fgets(buf, 1024, fp)) {
        field_count = 0;
        i++;

        if (i == 1) {	//Pula a primeira linha
            continue;
        }

        char *field = strtok(buf, ",");
        while (field) {
        	if (field_count == 0) {
        		pessoa[i].id = atoi(field);
        	}
            if (field_count == 1) {
            	strcpy(pessoa[i].surname, field);
            }
            if (field_count == 2) {
                strcpy(pessoa[i].firstname, field);
            }
            if (field_count == 3) {
                strcpy(pessoa[i].middlename, field);
            }
            if (field_count == 4) {
                strcpy(pessoa[i].gender, field);
            }
            if (field_count == 5) {
                pessoa[i].gender_male = atoi(field);
            } 
            if (field_count == 6) {
                pessoa[i].gender_female = atoi(field);
            }
            if (field_count == 7) {
                strcpy(pessoa[i].state, field);
            } 
            if (field_count == 8) {
                strcpy(pessoa[i].settlement, field);
            }
            if (field_count == 9) {
            	pessoa[i].rural_settlement = atoi(field);
            } 
            if (field_count == 10) {
            	pessoa[i].urban_settlement = atoi(field);
            }
            if (field_count == 11) {
            	strcpy(pessoa[i].report_date, field);
            }
            if (field_count == 12) {
            	pessoa[i].report_year = atoi(field);
            }  
            if (field_count == 13) {
            	pessoa[i].age = atoi(field);
            }
            if (field_count == 14) {
            	strcpy(pessoa[i].age_str, field);
            } 
            if (field_count == 15) {
            	strcpy(pessoa[i].date_of_birth, field);
            }
            if (field_count == 16) {
            	pessoa[i].child_group = atoi(field);
            }
            if (field_count == 17) {
            	pessoa[i].adult_group = atoi(field);
            }
            if (field_count == 18) {
            	strcpy(pessoa[i].disease, field);
            }
            if (field_count == 19) { //cholera
            	pessoa[i].cholera = atoi(field);
            }
            if (field_count == 20) {
            	pessoa[i].diarrhoea = atoi(field);
            }
            if (field_count == 21) {
            	pessoa[i].measles = atoi(field);
            }
            if (field_count == 22) {
            	pessoa[i].viral_haemmorrhaphic_fever = atoi(field);
            }
            if (field_count == 23) {
            	pessoa[i].meningitis = atoi(field);
            }
            if (field_count == 24) {
            	pessoa[i].ebola = atoi(field);
            }
            if (field_count == 25) {
            	pessoa[i].marburg_virus = atoi(field);
            }
            if (field_count == 26) {
            	pessoa[i].yellow_fever = atoi(field);
            }
            if (field_count == 27) {
            	pessoa[i].rubella_mars = atoi(field);
            }
            if (field_count == 28) {
            	pessoa[i].malaria = atoi(field);
            }
            if (field_count == 29) {
            	strcpy(pessoa[i].serotype, field);
            }
            if (field_count == 30) {
            	pessoa[i].NmA = atoi(field);
            }
            if (field_count == 31) {
            	pessoa[i].NmC = atoi(field);
            }
            if (field_count == 32) {
            	pessoa[i].NmW = atoi(field);
            }
            if (field_count == 33) {
            	strcpy(pessoa[i].health_status, field);
            }
            if (field_count == 34) {
            	pessoa[i].alive = atoi(field);
            }
            if (field_count == 35) {
            	pessoa[i].dead = atoi(field);
            }
            if (field_count == 36) {
            	strcpy(pessoa[i].report_outcome, field);
            }
            if (field_count == 37) {
            	pessoa[i].unconfirmed = atoi(field);
            }
            if (field_count == 38) {
            	pessoa[i].confirmed = atoi(field);
            }
            if (field_count == 39) {
            	pessoa[i].null_serotype = atoi(field);
            }
            field = strtok(NULL, ",");
            field_count++;
        }
    }

    fclose(fp);
    return i;
}

void buscarDoencas () {
	int i;
	for (i = 2; i <= qtdPessoas; i++) {
		if (pessoa[i].cholera) {
			cholera.infectados++;
			if (pessoa[i].dead) {
				cholera.mortos++;
			}
			if (pessoa[i].rural_settlement) {
				cholera.rural++;
			}
			else {
				cholera.urbano++;
			}
			if (pessoa[i].gender_male) {
				cholera.masculino++;
			}
			else {
				cholera.feminino++;
			}
		}
		if (pessoa[i].diarrhoea) {
			diarrhoea.infectados++;
			if(pessoa[i].dead) {
				diarrhoea.mortos++;
			}
			if (pessoa[i].rural_settlement) {
				diarrhoea.rural++;
			}
			else {
				diarrhoea.urbano++;
			}
			if (pessoa[i].gender_male) {
				diarrhoea.masculino++;
			}
			else {
				diarrhoea.feminino++;
			}
		}
		if (pessoa[i].measles) {
			measles.infectados++;
			if(pessoa[i].dead) {
				measles.mortos++;
			}
			if (pessoa[i].rural_settlement) {
				measles.rural++;
			}
			else {
				measles.urbano++;
			}
			if (pessoa[i].gender_male) {
				measles.masculino++;
			}
			else {
				measles.feminino++;
			}
		}
		if (pessoa[i].viral_haemmorrhaphic_fever) {
			viral_haemmorrhaphic_fever.infectados++;
			if(pessoa[i].dead) {
				viral_haemmorrhaphic_fever.mortos++;
			}
			if (pessoa[i].rural_settlement) {
				viral_haemmorrhaphic_fever.rural++;
			}
			else {
				viral_haemmorrhaphic_fever.urbano++;
			}
			if (pessoa[i].gender_male) {
				viral_haemmorrhaphic_fever.masculino++;
			}
			else {
				viral_haemmorrhaphic_fever.feminino++;
			}
		}
		if (pessoa[i].meningitis) {
			meningitis.infectados++;
			if (pessoa[i].dead) {
				meningitis.mortos++;
			}
			if (pessoa[i].rural_settlement) {
				meningitis.rural++;
			}
			else {
				meningitis.urbano++;
			}
			if (pessoa[i].gender_male) {
				meningitis.masculino++;
			}
			else {
				meningitis.feminino++;
			}
		}
		if (pessoa[i].ebola) {
			ebola.infectados++;
			if (pessoa[i].dead) {
				ebola.mortos++;
			}
			if (pessoa[i].rural_settlement) {
				ebola.rural++;
			}
			else {
				ebola.urbano++;
			}
			if (pessoa[i].gender_male) {
				ebola.masculino++;
			}
			else {
				ebola.feminino++;
			}
		}
		if (pessoa[i].marburg_virus) {
			marburg_virus.infectados++;
			if (pessoa[i].dead) {
				marburg_virus.mortos++;
			}
			if (pessoa[i].rural_settlement) {
				marburg_virus.rural++;
			}
			else {
				marburg_virus.urbano++;
			}
			if (pessoa[i].gender_male) {
				marburg_virus.masculino++;
			}
			else {
				marburg_virus.feminino++;
			}
		}
		if (pessoa[i].yellow_fever) {
			yellow_fever.infectados++;
			if (pessoa[i].dead) {
				yellow_fever.mortos++;
			}
			if (pessoa[i].rural_settlement) {
				yellow_fever.rural++;
			}
			else {
				yellow_fever.urbano++;
			}
			if (pessoa[i].gender_male) {
				yellow_fever.masculino++;
			}
			else {
				yellow_fever.feminino++;
			}
		}
		if (pessoa[i].rubella_mars) {
			rubella_mars.infectados++;
			if (pessoa[i].dead) {
				rubella_mars.mortos++;
			}
			if (pessoa[i].rural_settlement) {
				rubella_mars.rural++;
			}
			else {
				rubella_mars.urbano++;
			}
			if (pessoa[i].gender_male) {
				rubella_mars.masculino++;
			}
			else {
				rubella_mars.feminino++;
			}
		}
		if (pessoa[i].malaria) {
			malaria.infectados++;
			if (pessoa[i].dead) {
				malaria.mortos++;
			}
			if (pessoa[i].rural_settlement) {
				malaria.rural++;
			}
			else {
				malaria.urbano++;
			}
			if (pessoa[i].gender_male) {
				malaria.masculino++;
			}
			else {
				malaria.feminino++;
			}
		}
	}
}

void imprimirResultados () {
	printf("DOENCA\t\t\t\t| INFECTADOS \t| MORTOS \t|\n");
	printf("cholera\t\t\t\t| %d \t| %d \t|\n", cholera.infectados, cholera.mortos);
	printf("diarrhoea\t\t\t| %d \t| %d \t|\n", diarrhoea.infectados, diarrhoea.mortos);
	printf("measles\t\t\t\t| %d \t| %d \t|\n", measles.infectados, measles.mortos);
	printf("viral_haemmorrhaphic_fever\t| %d \t| %d \t|\n", viral_haemmorrhaphic_fever.infectados, viral_haemmorrhaphic_fever.mortos);
	printf("meningitis\t\t\t| %d \t| %d \t|\n", meningitis.infectados, meningitis.mortos);
	printf("ebola\t\t\t\t| %d \t| %d \t|\n", ebola.infectados, ebola.mortos);
	printf("marburg_virus\t\t\t| %d \t| %d \t|\n", marburg_virus.infectados, marburg_virus.mortos);
	printf("yellow_fever\t\t\t| %d \t| %d \t|\n", yellow_fever.infectados, yellow_fever.mortos);
	printf("rubella_mars\t\t\t| %d \t| %d \t|\n", rubella_mars.infectados, rubella_mars.mortos);
	printf("malaria\t\t\t\t| %d \t| %d \t|\n", malaria.infectados, malaria.mortos);
	printf("========================================\n");
	printf("DOENCA\t\t\t\t| RURAL \t| URBANO \t|\n");
	printf("cholera\t\t\t\t| %d \t| %d \t|\n", cholera.rural, cholera.urbano);
	printf("diarrhoea\t\t\t| %d \t| %d \t|\n", diarrhoea.rural, diarrhoea.urbano);
	printf("measles\t\t\t\t| %d \t| %d \t|\n", measles.rural, measles.urbano);
	printf("viral_haemmorrhaphic_fever\t| %d \t| %d \t|\n", viral_haemmorrhaphic_fever.rural, viral_haemmorrhaphic_fever.urbano);
	printf("meningitis\t\t\t| %d \t| %d \t|\n", meningitis.rural, meningitis.urbano);
	printf("ebola\t\t\t\t| %d \t| %d \t|\n", ebola.rural, ebola.urbano);
	printf("marburg_virus\t\t\t| %d \t| %d \t|\n", marburg_virus.rural, marburg_virus.urbano);
	printf("yellow_fever\t\t\t| %d \t| %d \t|\n", yellow_fever.rural, yellow_fever.urbano);
	printf("rubella_mars\t\t\t| %d \t| %d \t|\n", rubella_mars.rural, rubella_mars.urbano);
	printf("malaria\t\t\t\t| %d \t| %d \t|\n", malaria.rural, malaria.urbano);
	printf("========================================\n");
	printf("DOENCA\t\t\t\t| HOMENS \t| MULHERES \t|\n");
	printf("cholera\t\t\t\t| %d \t| %d \t|\n", cholera.masculino, cholera.feminino);
	printf("diarrhoea\t\t\t| %d \t| %d \t|\n", diarrhoea.masculino, diarrhoea.feminino);
	printf("measles\t\t\t\t| %d \t| %d \t|\n", measles.masculino, measles.feminino);
	printf("viral_haemmorrhaphic_fever\t| %d \t| %d \t|\n", viral_haemmorrhaphic_fever.masculino, viral_haemmorrhaphic_fever.feminino);
	printf("meningitis\t\t\t| %d \t| %d \t|\n", meningitis.masculino, meningitis.feminino);
	printf("ebola\t\t\t\t| %d \t| %d \t|\n", ebola.masculino, ebola.feminino);
	printf("marburg_virus\t\t\t| %d \t| %d \t|\n", marburg_virus.masculino, marburg_virus.feminino);
	printf("yellow_fever\t\t\t| %d \t| %d \t|\n", yellow_fever.masculino, yellow_fever.feminino);
	printf("rubella_mars\t\t\t| %d \t| %d \t|\n", rubella_mars.masculino, rubella_mars.feminino);
	printf("malaria\t\t\t\t| %d \t| %d \t|\n", malaria.masculino, malaria.feminino);
}