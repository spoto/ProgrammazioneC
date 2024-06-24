#include <stdio.h>
struct entry {
	  //da completare
};

struct entry *construct_entry(char fiscal_code[], float income,
  struct entry *next) {
	//da completare
}



int list_length(struct entry *l) {
	//da completare
}
float list_sum(struct entry *l) {
	//da completare
 }


void print_list(struct entry *l) {
 	//da completare
}


void destroy_list(struct entry *l) {
 	//da completare
}


struct entry *senior_women_manager(struct entry *l, float avg_income) {
	//da completare
}

int main(void) {
	struct entry *l = NULL;
	l = construct_entry( "czzvtr81s51d086n", 1300.0, construct_entry( "czzvtr61s51d086n",3300, construct_entry( "vnrmzz93s42d086n", 1100.0, construct_entry( "abclmn00s71d086n", 3000.0, construct_entry( "mrtmtt93d48f205j",3500.0, construct_entry( "rmqxss61s01d086n", 2500.0, l))))));
	  
	 printf("La lista e' lunga %d\n", list_length(l));
	 printf("I dipendenti sono:\n");
	 print_list(l);
	 
	 float avg_income= list_length(l)!=0? list_sum(l)/list_length(l): 0;
	 printf("La media degli elementi e' %2.f\n", avg_income);
	 printf("I dipendenti senior e con stipendio maggiore della media sono:\n");
	  struct entry * swm = senior_women_manager(l, avg_income);
	  print_list(swm);
	  destroy_list(l);
	  destroy_list(swm);
  return 0;
}



