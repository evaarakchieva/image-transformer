#include "image_processor.h"
#include "rotation.h"
#include "util.h"
#include <stdint.h>
#include <stdio.h>


int main(int argc, char** argv) {
    (void) argc; (void) argv;

//    char *input_file = "/Users/evaarakcieva/CLionProjects/assignment-image-rotation/tester/tests/1/input.bmp";
//    char *output_file = "/Users/evaarakcieva/CLionProjects/assignment-image-rotation/tester/tests/1/output_expected.bmp";

    enum arg_status new_arg_status = args_counter(argc);
    if (new_arg_status != NUMBER_OF_ARGS_IS_OK) {
        fprintf(stderr, "there is a problem: the number of args is invalid");
        return PROBLEM_WITH_ARGS;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];

    FILE * in = fopen(input_file, "rb");
    if(in == NULL) {
        fprintf(stderr,"there is a problem: the file cannot be opened");
        return THERE_IS_NO_FILE;
    }

    struct image original_image;

    fprintf(stdout, "PROCESS OF FILE READING HAS BEGUN");

    enum read_status new_read_status = from_bmp (in, &original_image);
    if (new_read_status != READ_OK) {
        fprintf(stderr, "there is a problem: the file cannot be read");
        printf("%d\n", new_read_status);
    }

    fprintf(stdout, "THE IMAGE WAS SUCCESSFULLY READ");

    fprintf(stdout, "THE PROCESS OF ROTATING HAS BEGUN...");

    struct image rotated_image = rotate(&original_image);

    delete_image(original_image);

    fprintf(stdout, "THE IMAGE WAS SUCCESSFULLY ROTATED");

    FILE * out = fopen(output_file, "wb");

    if(out == NULL) {
        fprintf(stderr, "there is a problem: the file cannot be written");
        return THERE_IS_NO_FILE;
    }

    fprintf(stdout, "THE PROCESS OF WRITING HAS BEGUN...");

    enum write_status new_write_status = to_bmp(out, &rotated_image);
    if(new_write_status != WRITE_OK) {
        fprintf(stderr, "there is a problem: the file cannot be written");
        return new_write_status;
    }

    delete_image(rotated_image);

    fclose(in);
    fclose(out);

    return 0;
}


