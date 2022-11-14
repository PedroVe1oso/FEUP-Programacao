#include <rgb/color.hpp>

namespace rgb {
    const color color::BLACK(0,0,0);
    const color color::WHITE(255,255,255);
    const color color::RED(255,0,0);
    const color color::GREEN(0,255,0);
    const color color::BLUE(0,0,255);
    color::color() {

    }
    color::color(const color& other) {

    }
    color::color(rgb_value red, rgb_value green, rgb_value blue) {

    }
    rgb_value color::red() const {
        return r;
    }
    rgb_value color::green() const {
        return g;
    }
    rgb_value color::blue() const {
        return b;
    }
    rgb_value& color::red()  {
        return r;
    }
    rgb_value& color::green()  {
        return g;
    }
    rgb_value& color::blue()  {
        return b;
    }
    color& color::operator=(const color& c) {
        return *this;
    }
    bool color::operator==(const color &c) const {
        return false;
    }
    bool color::operator!=(const color &c) const {
        return false;
    }
    void color::invert() {

    }
    void color::mix(const color& c, int f) {

    }
    void color::to_gray_scale() {

    }
}