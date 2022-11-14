//! @file image.hpp
#ifndef __rgb_image_hpp__
#define __rgb_image_hpp__
#include <cassert>
#include <rgb/color.hpp>

namespace rgb {
    //! An rgb::image object is defined by a width (width()), a height (height()), and a RGB color matrix with width() × height() dimension.
    //! Each position (x,y) is called a pixel. The upper left corner of the image corresponds to the pixel (0,0) and the lower right field to the pixel (width()-1, height()-1).
    class image {
    private:
        //! Image width.
        int iwidth;
        //! Image height.
        int iheight;
        //! Color matrix.
        //!
        //! Stores the image pixels.
        //! Implemented using an array of pointers.
        color** pixels;
    public:
        //! Parameterized constructor.
        //!
        //! The iwidth, iheight and pixels components are initialized respectively with the arguments provided.
        //!
        //! @param w describes the image width.
        //! @param h describes the image height.
        //! @param fill describes the color of all the pixels in the image matrix.
        //!
        //!  ### Examples
        //! ~~~~~~~~~~~~~~~~~~~~~~~.cpp
        //! image image(10, 20);
        //!
        //! color c(1, 2, 3);
        //! image image(20, 10, c);
        //! ~~~~~~~~~~~~~~~~~~~~~~~
        //! @note If no argument is passed to fill the default value is WHITE.
        image(int w, int h, const color &fill = color::WHITE);
        //! Destructor.
        //! The purpose of this destructor is to free the resources allocated to the pixels matrix.
        ~image();
        //! @returns The width of the image.
        int width() const;
        //! @returns The height of the image.
        int height() const;
        //! @param x
        //! @param y
        //! @returns A reference to the color in the position (x, y).
        //! @note 0≤x<width() and 0≤y<height().
        color& at(int x, int y);
        //! @param x
        //! @param y
        //! @returns A constant reference to the color in the position (x, y).
        //! @note 0≤x<width() and 0≤y<height().
        const color& at(int x, int y) const;
        //! Inverts all the pixels in the image.
        void invert();
        //! Converts all the pixels in the image to grayscale.
        void to_gray_scale();
        //! Replaces all the pixels in the image that have the color a with color b.
        //! @param a
        //! @param b
        void replace(const color& a, const color& b);
        //! Fill an area of pixels with the color c.
        //! @param x
        //! @param y
        //! @param w
        //! @param h
        //! @param c
        //! @note The pixels must have the coordinates (x′,y′) where x≤x′<x+w and y≤y′<y+h.
        void fill(int x, int y, int w, int h, const color& c);
        //! Changes the current image by mixing every pixel from img with the factor f.
        //! @param img
        //! @param factor
        void mix(const image& img, int factor);
        //! Cuts the image into a smaller size.
        //! @note Reduces the image (by changing its dimension) to the rectangle with the top left (x,y) and dimension w × h.
        void crop(int x, int y, int w, int h);
        //! Rotates the image to the left.
        void rotate_left();
        //! Rotates the image to the right.
        void rotate_right();
        //! Adds the img content, replacing the current pixels from position (x,y) except for pixels in img that have the neutral color.
        void add(const image& img, const color& neutral,
                 int x, int y);
    };
}


#endif
