#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct data {
	int giorno;
    int mese;
    int anno;
};

struct corso {
   char codice_corso[6];
   int CFU;
   struct data data_inizio;
   struct corso *next;
};

struct corso *construct_entry(char codice_corso[], int CFU, struct data d,
  struct corso *next) {
//da completare
}


int list_length(struct corso *l) {
//da completare
}

void print_list(struct corso *l) {
//da completare
}

void destroy_list(struct corso *l) {	
//da completare
}


int valid_study_plan (struct corso *l, int anno){
//da completare
}


struct corso * create_by_sector(struct corso *l, char s){
//da completare
}


struct corso * add_from_input (struct corso *l) {
//da completare	
}

int main(void) {
	struct corso *l = NULL;
	l = construct_entry( "BI006", 10, (struct data){2,3,2024}, l);
	l = construct_entry( "INF04", 10,(struct data) {2,3,2024}, l);
	l = construct_entry("INF03",8,(struct data){11,11,2023}, l);
	l = construct_entry( "BI005", 12,(struct data) {1,3,2024}, l);
	l = construct_entry( "INF02", 12,(struct data) {12,4,2023}, l);
	l = construct_entry("INF01",8,(struct data){11,6,2023}, l);
	l = construct_entry( "BI004", 12,(struct data) {21,5,2024}, l);
	l = construct_entry( "BI003", 12,(struct data) {21,5,2024}, l);
	l = construct_entry( "BI002", 12,(struct data) {21,5,2024}, l);
	l = construct_entry( "BI001", 12,(struct data) {21,5,2024}, l);
	 
	l =  add_from_input(l);
	 
	printf("La lista di corsi e' lunga %d\n", list_length(l));
	printf("I corsi sono:\n");
	print_list(l);
	printf("Piano di studio valido: %d\n", valid_study_plan (l, 2023));
	printf("Piano di studio valido: %d\n", valid_study_plan (l, 2024));
	struct corso * sector_plan=create_by_sector(l,'B');
	print_list(sector_plan);
	destroy_list(sector_plan);
	destroy_list(l);
	return 0;
}

