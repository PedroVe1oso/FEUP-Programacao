//! @file color.hpp

#ifndef __rgb_color_hpp__
#define __rgb_color_hpp__

#include <iostream>

namespace rgb {
    typedef unsigned char rgb_value;

    //! A rgb::color object has three integer values associated with it  (r,g,b) between 0 and 255 for the red, green, and blue ranges.
    class color {
    private:
        //! Red component.
        rgb_value r;
        //! Green component.
        rgb_value g;
        //! Blue component.
        rgb_value b;
    public:
        //! Red color constant.
        static const color RED;
        //! Green color constant.
        static const color GREEN;
        //! Blue color constant.
        static const color BLUE;
        //! Black color constant.
        static const color BLACK;
        //! White color constant.
        static const color WHITE;
        //! Default constructor.
        //!
        //! This is the default parameterless constructor. When this constructor is called the RGB components are all initialized as 0.
        //!
        //! ### Example
        //! ~~~~~~~~~~~~~~~~~~~~~~~.cpp
        //! color c;
        //! ~~~~~~~~~~~~~~~~~~~~~~~
        color();
        //! Copy constructor.
        //!
        //! This constructor initializes a color object using another color object.
        //!
        //! @param c
        //!
        //! ### Example
        //! ~~~~~~~~~~~~~~~~~~~~~~~.cpp
        //! color c1(1, 2, 3);
        //! color c2 = c1;
        //! ~~~~~~~~~~~~~~~~~~~~~~~
        color(const color &c);
        //! Parameterized constructor.
        //!
        //! The RGB components are initialized respectively with the arguments provided.
        //!
        //! @param r describes the red component.
        //! @param g describes the green component.
        //! @param b describes the blue component.
        //!
        //!  ### Example
        //! ~~~~~~~~~~~~~~~~~~~~~~~.cpp
        //!  color c(1, 2, 3);
        //! ~~~~~~~~~~~~~~~~~~~~~~~
        color(rgb_value r, rgb_value g, rgb_value b);
        //! @returns The R component value.
        rgb_value red() const;
        //! @returns The R component reference.
        rgb_value& red();
        //! @returns The G component value.
        rgb_value green() const;
        //! @returns The G component reference.
        rgb_value& green();
        //! @returns The B component value.
        rgb_value blue() const;
        //! @returns The B component reference.
        rgb_value& blue();
        //! Assignment operator.
        color& operator=(const color&c);
        //! Equal operator.
        //!
        //! Find out if the current color equals the color c.
        //! ### Example
        //! ~~~~~~~~~~~~~~~~~~~~~~~.cpp
        //! color c1(1, 2, 3);
        //! color c2(1, 2, 3);
        //! color c3(7, 4, 8);
        //! c1 == c2; //returns true
        //! c1 == c3; //returns false
        //! ~~~~~~~~~~~~~~~~~~~~~~~
        bool operator==(const color &c) const;
        //! Not equal operator.
        //!
        //! Find out if the current color is different from the color c.
        //! ### Example
        //! ~~~~~~~~~~~~~~~~~~~~~~~.cpp
        //! color c1(1, 2, 3);
        //! color c2(1, 2, 3);
        //! color c3(7, 4, 8);
        //! c1 != c2; //returns false
        //! c1 != c3; //returns true
        //! ~~~~~~~~~~~~~~~~~~~~~~~
        bool operator!=(const color &c) const;
        //! Inverts color.
        //!
        //! ### Example
        //! ~~~~~~~~~~~~~~~~~~~~~~~.cpp
        //! color c;
        //! c.invert();
        //! ~~~~~~~~~~~~~~~~~~~~~~~
        //! @note (r,g,b)↦(255−r,255−g,255−b).
        void invert();
        //! Converts color to grayscale.
        //!
        //! ### Example
        //! ~~~~~~~~~~~~~~~~~~~~~~~.cpp
        //! color c;
        //! c.to_gray_scale();
        //! ~~~~~~~~~~~~~~~~~~~~~~~
        //! @note (r,g,b)↦(v,v,v) where v=(r+g+b)/3.
        void to_gray_scale();
        //! Mixes the color c with a factor f between 0 and 100.
        //!
        //! @param c
        //! @param f
        //!
        //! ### Example
        //! ~~~~~~~~~~~~~~~~~~~~~~~.cpp
        //! color c1;
        //! color c2(1, 2, 3);
        //! c.mix(c2, f);
        //! ~~~~~~~~~~~~~~~~~~~~~~~
        //! @note (r,g,b)↦(m(r,c.r),m(g,c.g),m(b,c.b)) where m(a,b)=((100−f)a+fb)/100.
        void mix(const color& c, int f);
    };
}
#endif
