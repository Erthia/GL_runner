#ifndef SCORES_HPP
#define SCORES_HPP

#pragma once

#include "ExceptIMAC.hpp"

#include <map>
#include <string>
#include <fstream>
#include <utility>

namespace motor_game{
    class Scores{
        public :
            /// \brief constructor
            /// \param maxSize : max number of scores stored
            Scores(const size_t &maxSize=7);
            
            
            /// \param filename : constructor reads scores from this file
            void read(const std::string &filename);
            
            /// \brief getter : returns the multimap which contains the scores
            const std::multimap<long,std::string,std::greater<long>> &multimap() const;
            
            /// \brief save scores into a file - can throw an exception
            void save(const std::string &filename);
            
            /// \brief add the score, if it is high enough. A name is present only one time.
            void add(const std::pair<long,std::string> &score);
            
            /// \brief empty the Scores data
            void clear();
            
            ~Scores() = default;
            
        private :
            std::multimap<long, std::string, std::greater<long>> m_scores; // scores
            size_t m_maxSize; // max number of scores stored
            size_t m_size=0; // cuurent number of scores stored
    };
}

#endif
