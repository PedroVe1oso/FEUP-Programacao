#include <rgb/image.hpp>

namespace rgb {
    image::image(int w, int h, const color& fill) {
        assert(h > 0 && w > 0);
        iwidth = w;
        iheight = h;
        pixels = new color*[w];
        color* data = new color[h * w];
        for (int i = 0; i < w; i++) {
            pixels[i] = data + i * h;
            for(int j = 0; j < h; j++){
                pixels[i][j] = fill;
            }
        }
    }

    image::~image() {
        delete [] pixels[0];
        delete [] pixels;
    }

    int image::width() const {
        return iwidth;
    }

    int image::height() const {
        return iheight;
    }

    color& image::at(int x, int y) {
        return pixels[x][y];
    }

    const color& image::at(int x, int y) const {
        return pixels[x][y];
    }

    void image::invert() {
        for (int i = 0; i < iwidth; i++) {
            for(int j = 0; j < iheight; j++){
                pixels[i][j].invert();
            }
        }
    }

    void image::to_gray_scale() {
        for (int i = 0; i < iwidth; i++) {
            for(int j = 0; j < iheight; j++){
                pixels[i][j].to_gray_scale();
            }
        }
    }

    void image::fill(int x, int y, int w, int h, const color& c) {
        for (int i = x; i < x + w; i++) {
            for(int j = y; j < y + h; j++){
                pixels[i][j] = c;
            }
        }
    }

    void image::replace(const color& a, const color& b) {
        for (int i = 0; i < iwidth; i++) {
            for(int j = 0; j < iheight; j++){
                if(pixels[i][j] == a) pixels[i][j] = b;
            }
        }
    }

    void image::add(const image& img,
                    const color& neutral,
                    int x,
                    int y) {
        for (int i = 0; i < img.width(); i++) {
            for(int j = 0; j < img.height(); j++){
                if (img.at(i, j) != neutral)
                    pixels[i + x][j + y] = img.at(i, j);
            }
        }
    }

    void image::crop(int x, int y, int w, int h) {
        color** new_pixels = new color*[w];
        color* data = new color[h * w];

        for(int i = 0; i < w ; i++){
            new_pixels[i] = data + i * h;
        }
        for(int i = x; i < x + w ; i++){
            for(int j = y; j < y + h; j++){
                new_pixels[i - x][j - y] = pixels[i][j];
            }
        }

        iwidth = w;
        iheight = h;

        delete [] pixels[0];
        delete [] pixels;

        pixels = new_pixels;
    }

    void image::rotate_left() {

        color** new_pixels = new color*[iheight];
        color* data = new color[iwidth * iheight];

        for(int i = 0; i < iheight ; i++){
            new_pixels[i] = data + i * iwidth;
        }
        for (int i = 0; i < iwidth; i++) {
            for(int j = 0; j < iheight; j++){
                new_pixels[j][iwidth - 1 - i] = pixels[i][j];
            }
        }

        int tmp = iwidth;
        iwidth = iheight;
        iheight = tmp;

        delete [] pixels[0];
        delete [] pixels;

        pixels = new_pixels;
    }

    void image::rotate_right() {
        color** new_pixels = new color*[iheight];
        color* data = new color[iwidth * iheight];

        for(int i = 0; i < iheight ; i++){
            new_pixels[i] = data + i * iwidth;
        }
        for (int i = 0; i < iwidth; i++) {
            for(int j = 0; j < iheight; j++){
                new_pixels[iheight - 1 - j][i] = pixels[i][j];
            }
        }

        int tmp = iwidth;
        iwidth = iheight;
        iheight = tmp;

        delete [] pixels[0];
        delete [] pixels;

        pixels = new_pixels;
    }

    void image::mix(const image& img, int factor) {
        for (int i = 0; i < iwidth; i++) {
            for(int j = 0; j < iheight; j++){
                pixels[i][j].mix(img.at(i, j), factor);
            }
        }
    }
}
