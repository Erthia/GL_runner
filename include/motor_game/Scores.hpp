#include <map>
#include <string>
#include <fstream>

namespace motor_game{
    class Scores{
        public :
            /// \brief constructor : based on a file, or empty is the file doesn't exist
            Scores(std::string &filename);
            ~Scores = default;
            
            /// \brief add the score, if it is high enough
            void add(const long &value, const &std::string);
            
            /// \brief empty the Scores data
            void clear();
            
        private :
            multimap<long, std::string> m_scores;
            std::ifstream m_inStream;
            std::string m_currentName;
            long m_currentValue;
    };
}
