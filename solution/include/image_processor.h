#ifndef IMAGE_TRANSFORMER_IMAGE_PROCESSOR_H
#define IMAGE_TRANSFORMER_IMAGE_PROCESSOR_H

#include  <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct pixel {uint8_t b, g, r;};

struct image {
    uint64_t width, height;
    struct pixel* data;
};

enum read_status  {
    READ_OK = 0,
    READ_INVALID_SIGNATURE,
    READ_INVALID_BITS,
    READ_INVALID_HEADER
};

enum read_status from_bmp( FILE* in, struct image* img );

enum  write_status  {
    WRITE_OK = 0,
    WRITE_ERROR
};

enum write_status to_bmp( FILE* out, struct image const* img );

#endif //IMAGE_TRANSFORMER_IMAGE_PROCESSOR_H
