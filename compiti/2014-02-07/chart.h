struct chart {
  const char *titles[10];
};

struct chart *construct_chart();
void destroy_chart(struct chart *this);
void print_chart(struct chart *this);
void set_song_title(struct chart *this, const char *title, int position); 
