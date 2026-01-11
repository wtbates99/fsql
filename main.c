#include <stdio.h>
#include <stdlib.h>

void file_reader(const char *file_path) {
    FILE *file = fopen(file_path, "r");

    if (file == NULL) {
        printf("File doesn't exist at path %s\n", file_path);
        return;
    }

    char buffer[256];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    file_reader(argv[1]);
    return 0;
}

