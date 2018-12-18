#include "../../include/exception/ExceptIMAC.hpp"

namespace cpp_IMAC{
    
    ExceptIMAC::ExceptIMAC(const std::string &description, const std::string &filename, const unsigned int line) throw()
        : m_description(description), m_filename(filename), m_line(line)
    {
        m_what =
            "Exception throw from file " + m_filename + ", line " + std::to_string(m_line)
            + " : " + m_description;
        
    }
    

}
