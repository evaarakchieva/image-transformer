#ifndef IMAGE_TRANSFORMER_ROTATION_H
#define IMAGE_TRANSFORMER_ROTATION_H


struct image rotate(struct image* const source);

struct pixel get_pixels(const struct image *const img, const size_t row, const size_t c);

struct image generate_image(size_t width, size_t height);

void set_pixels(struct image *const img, const size_t row, const size_t c, const struct pixel pixel);
#endif //IMAGE_TRANSFORMER_ROTATION_H
