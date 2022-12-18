#include "image_processor.h"
#include "util.h"

uint32_t padding_calculator (uint32_t width) {
    return (4 - (width * sizeof(struct pixel)) % 4) % 4;
}

enum arg_status args_counter( const int args ){
    if( args != 3 ){
        return PROBLEM_WITH_ARGS;
    } else {
        return NUMBER_OF_ARGS_IS_OK;
    }
}
