#include "image_processor.h"
#include "rotation.h"
#include <stdint.h>

struct image rotate(struct image const source) {
    uint64_t original_image_width = source.width;
    uint64_t original_image_height = source.height;
    struct pixel *original_pixels = source.data;
    struct pixel *rotated_pixels = malloc(sizeof(struct pixel) * original_image_width * original_image_height);

    for (uint64_t i = 0; i < original_image_height; i++)
        for (uint64_t j = 0; j < original_image_width; j++) {
            rotated_pixels[(original_image_height - i - 1) + original_image_height * j] = original_pixels[j + original_image_width * i];
        }

    struct image rotated_image = {0};

    rotated_image.width = original_image_height;
    rotated_image.height = original_image_width;
    rotated_image.data = rotated_pixels;

    return rotated_image;
}




