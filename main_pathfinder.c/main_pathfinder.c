#include "pathfinder.h"

int main(int argc, char *argv[]) {
    int count;
    char *file_str[2];
    char **lines = mx_get_lines(argc, argv[1], &file_str[0], &count);
    char **islands;
    int **distances = mx_create_arrs(&islands, count);

    file_str[1] = mx_get_data(islands, lines, distances, count);
    if (file_str[1]) {
        mx_clean_all(&distances, &islands, lines, file_str[0]);
        if (mx_strcmp(file_str[1], "-6") == 0)
            mx_check_err(-6, NULL);
        mx_check_err(-5, file_str[1]);
    }
    mx_do_all(islands, distances, count);
    mx_clean_all(&distances, &islands, lines, file_str[0]);
    return 0;
}
