#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//czzvtr81s51d086n
struct entry {
	  char fiscal_code[17];
	  float income;
	  struct entry *next;
};

struct entry *construct_entry(char fiscal_code[], float income,
  struct entry *next) {
	  struct entry *p = malloc(sizeof(struct entry));
	  p->income = income;
	  strcpy(p->fiscal_code,fiscal_code);
	  p->next = next;
	  return p;
}

void destroy_entry(struct entry *p) {
  free(p);
}


int list_length(struct entry *l) {
  if (l == NULL)
    return 0;
  else
    return 1 + list_length(l->next);
}
float list_sum(struct entry *l) {
  if (l == NULL)
    return 0;
  else {
    return l->income+list_sum(l->next);
  }
}
int is_woman(char fiscal_code[]){
  return fiscal_code[9]>='4';  
}

int findBirthYear(char fiscal_code[]){
	  char a=fiscal_code[6];
	  char b=fiscal_code[7];
	  
	  int year=(a-'0')*10+(b-'0');
	  return year;
}



void print_list(struct entry *l) {
  if (l == NULL)
    printf("\n");
  else {
    printf("%s: %2.f\n", l->fiscal_code, l->income);
    print_list(l->next);
  }
}


void destroy_list(struct entry *l) {
  if (l == NULL)
    {}
  else {
    destroy_list(l->next);
    free(l);
  }
}


struct entry *senior_women_manager(struct entry *l, float avg_income) {
  if (l == NULL)
    return NULL; 
  int yob=  findBirthYear(l->fiscal_code);
 // printf("%d\n",yob);
  if (( l->income > avg_income) && is_woman(l->fiscal_code) && (yob<=94	 && yob>24 )) 
    return construct_entry(l->fiscal_code, l->income, senior_women_manager(l->next, avg_income));
  else
    return senior_women_manager(l->next, avg_income);
}

int main(void) {
	  struct entry *l = NULL;
	  l= construct_entry( "czzvtr81s51d086n", 1300.0, construct_entry( "czzvtr61s51d086n",3300, construct_entry( "vnrmzz93s42d086n", 1100.0, construct_entry( "abclmn00s71d086n", 3000.0, construct_entry( "mrtmtt93d48f205j",3500.0, construct_entry( "rmqxss61s01d086n", 2500.0, l))))));
	  
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



