#include "Scores.hpp"

namespace motor_game{
    
    Scores::Scores(const std::string &filename)
    {
        //open the file
        std::ifstream inStream = std::ifstream("elt/" + filename, std::ios::in);
        if(inStream.is_open()){
            inStream >> m_maxSize;
            std::string currentName;
            long currentValue;
            for(size_t i=0; i<m_maxSize; i++){
                inStream >> currentValue >> currentName;
                std::cout << "Hello " << std::endl;
                m_scores.insert(std::pair<long, std::string>(currentValue, currentName));
                m_size ++;
            }
            inStream.close();
        }
        else THROW_EXCEPTION("Fails to open " + filename);
    }
    
    Scores::Scores(const size_t &maxSize)
        : m_maxSize(maxSize)
    {}
    
    void Scores::add(const std::pair<long,std::string> &score){
        std::multimap<long,std::string,std::greater<long>>::const_iterator it;
        for(it=m_scores.begin(); it!=m_scores.end() ; it++){
            if(it->second == score.second){
                if(score.first > it->first){
                    m_scores.insert(score);
                    m_scores.erase(it);
                }
                return;
            }
        }
        // the user has no entry
        m_scores.insert(score);
        m_size++;
        if(m_maxSize < m_size)
            m_scores.erase(--m_scores.end());
    }
    
    void Scores::clear(){
        m_scores.clear();
    }
    
    const std::multimap<long,std::string,std::greater<long>> &Scores::multimap() const{
        return m_scores;
    }
    
    // can throw an exception
    void Scores::save(const std::string &filename){
        // open the file
        std::ofstream writeStream = std::ofstream("elt/" + filename, std::ios::out);
        if(writeStream.is_open()==false)
            THROW_EXCEPTION("Fails to open " + filename);
        writeStream << m_maxSize;
        std::multimap<long,std::string,std::greater<long>>::const_iterator it;
        for(it=m_scores.begin(); it!=m_scores.end(); it++)
            writeStream << it->first << " " << it->second << "\n";
        
        // close filestream
        writeStream.close();
    }
}
