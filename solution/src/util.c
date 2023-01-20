#include "image_processor.h"
#include "util.h"

enum arg_status args_counter( const int args ){
    if( args != 3 ){
        return PROBLEM_WITH_ARGS;
    } else {
        return NUMBER_OF_ARGS_IS_OK;
    }
}

void delete_image(struct image img) {
    if (img.data != NULL) {
        free(img.data);
        img.data = NULL;
    }
}
