#ifndef IMAGE_TRANSFORMER_UTIL_H
#define IMAGE_TRANSFORMER_UTIL_H

#include  <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t padding_calculator(uint32_t width);

enum  arg_status  {
    NUMBER_OF_ARGS_IS_OK = 0,
    PROBLEM_WITH_ARGS
};

enum  arg_status args_counter( const int args );

#endif //IMAGE_TRANSFORMER_UTIL_H
