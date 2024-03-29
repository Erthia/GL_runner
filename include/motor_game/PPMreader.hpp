#ifndef RUNNER_PPM_READER_HPP
#define RUNNER_PPM_READER_HPP

#pragma once

#include <string>
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

#include "PPM.hpp"
#include "Element.hpp"
#include "End.hpp"
#include "Floor.hpp"
#include "Coin.hpp"
#include "Wall.hpp"
#include "Gap.hpp"
#include "Obstacle.hpp"
#include "Turn.hpp"

namespace motor_game{
   class PPMreader{
        public:
            /// \brief constructor : open the setting file
            /// \param string of the file name
            PPMreader(const std::string &filename);

            PPMreader() = delete;

            ///\brief destructor
            ~PPMreader();

            /// \brief read the file and set the ppm
            const PPM readFile();

            /// \brief read the file and add coins to the ppm
            /// \param ppm : the ppm to add coins to
            void readFile(PPM &ppm);

        private :
            // return the next valid string in the file (ie not a comment)
            // don't manage end of file
            const std::string nextString();
            // verify the validity of the file, and set m_x and m_y
            const bool validPPM();
            std::string m_currentStr;
            std::string m_r;
            std::string m_g;
            std::string m_b;
            std::ifstream m_ppm_1;
            int m_x=0;
            int m_y=3;
            int m_z=0;
    };

}

#endif
