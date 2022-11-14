//! @file script.hpp
#ifndef __rgb_script_hpp__
#define __rgb_script_hpp__

#include <fstream>
#include <rgb/image.hpp>

namespace rgb {
    //! The rgb::script class is used to process text scripts with image manipulation commands.
    class script {
    private:
        //! Initializes the image \a filename file.
        void open();
        //! Initializes the image with the dimensions w × h and initial color (r,g,b) for all pixels.
        void blank();
        //! Saves the image in a PNG file.
        void save();
        //! Executes the rgb::image::invert member function.
        void invert();
        //! Executes the rgb::image::to_gray_scale member function.
        void to_gray_scale();
        //! Executes the rgb::image::replace member function.
        void replace();
        //! Executes the rgb::image::fill member function.
        void fill();
        //! Executes the rgb::image::mix member function.
        void mix();
        //! Executes the rgb::image::add member function.
        void add();
        //! Executes the rgb::image::crop member function.
        void crop();
        //! Executes the rgb::image::rotate_left member function.
        void rotate_left();
        //! Executes the rgb::image::rotate_right member function.
        void rotate_right();
    public:
        //! Parameterized constructor
        script(const std::string& filename);
        //! Destructor
        ~script();
        //! Processes the commands given and manipulates an image accordingly.
        void process();
    private:
        //! Image pointer used to point to the image opened.
        image* img;
        //! ifstream object used to read files.
        std::ifstream input;
        //! Path to the file that will be opened.
        std::string root_path;
    };
}
#endif
