#ifndef ERREUR_HPP
#define ERREUR_HPP

#pragma once

#include <exception>
#include <iostream>
#include <string>
#include <sstream>

namespace cpp_IMAC{

    class ExceptIMAC : public std::exception{
        public :
            // CONSTRUCTOR AND DESTRUCTOR
            ExceptIMAC(
                const std::string &description,
                const std::string &filename,
                const unsigned int line
            ) throw();
            ~ExceptIMAC() throw() = default;
            

            const char* what() const throw(){
                return m_what.c_str();
            }
            
        private :
            // ATTRIBUTE
            std::string m_description;
            std::string m_filename;
            unsigned int m_line;
            std::string m_what;
    };
    
}

//macro (cf TP) --> pour que le code soit recopié par le compilateur,
//pour avoir la bonne ligne et le bon fichier
#define THROW_EXCEPTION(str) throw cpp_IMAC::ExceptIMAC(str, __FILE__, __LINE__)

#endif
