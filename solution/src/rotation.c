#include "image_processor.h"
#include "rotation.h"
#include <stdint.h>

struct pixel get_pixels(const struct image *const img, const size_t row, const size_t c) {
    return img->data[row * img->width + c];
}

void set_pixels(struct image *const img, const size_t row, const size_t c, const struct pixel pixel) {
    img->data[row * img->width + c] = pixel;
}

struct image generate_image(size_t width, size_t height) {
    return (struct image) {.height = height, .width = width, .data = malloc(height * width * sizeof(struct pixel))};
}

struct image rotate(struct image* const source) {
    const uint64_t original_image_width = source->width;
    const uint64_t original_image_height = source->height;
    struct image rotated_image = generate_image(original_image_height, original_image_width);
    for (uint64_t i = 0; i < original_image_height; i++)
        for (uint64_t j = 0; j < original_image_width; j++) {
            const struct pixel pixel = get_pixels(source, i, j);
            set_pixels(&rotated_image, j, original_image_height - i - 1, pixel);
        }
    return rotated_image;
}




