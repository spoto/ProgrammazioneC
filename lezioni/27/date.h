// dichiarazione della struct date
struct date {
  int day;
  int month;
  int year;
};

// dichiarazione delle funzioni sulla struct date
struct date read_date(void);
void print_date(struct date d);
struct date next_date(struct date d);
int days_from_beginning(struct date d);
int equals(struct date this, struct date that);

// ritorna < 0 se this viene prima nel tempo di that
// ritorna > 0 se that viene prima nel tempo di this
// ritorna 0 se this e that sono uguali
int compareTo(struct date this, struct date that);

// non è detto che this venga prima di that
int days_between(struct date this, struct date that);
