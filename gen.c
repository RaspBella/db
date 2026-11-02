#include <stdlib.h>
#include <stdio.h>

#define array_len(xs) sizeof((xs)) / sizeof((xs)[0])

#define FILENAME "docs/index.json"

int main(void) {
  char *dbs[] = { "cubing", "trans" };

  FILE *fp = fopen(FILENAME, "w");

  if (!fp) {
    perror("Can't open: "FILENAME);

    exit(EXIT_FAILURE);
  }

  fprintf(fp, "{\"dbs\":[");

  size_t count = array_len(dbs);

  if (count) {
    fprintf(fp, "\"%s\"", *dbs);

    for (int i = 1; i < sizeof(dbs) / sizeof(dbs[0]); ++i) {
      fprintf(fp, ",\"%s\"", dbs[i]);
    }
  }

  fprintf(fp, "]}");

  fclose(fp);
}
