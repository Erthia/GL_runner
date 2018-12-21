#include "Scores.hpp"


int main(){
    
    //test Score class #1
    /*
        //create empty multimap (default : 7 values)
    motor_game::Scores scoreTable;
        // fill multimap
    scoreTable.add(std::pair<long,std::string>(12051, "Marion"));
    scoreTable.add(std::pair<long,std::string>(170, "Emilie"));
    scoreTable.add(std::pair<long,std::string>(100, "Valérian"));
    scoreTable.add(std::pair<long,std::string>(120, "Pierre"));
    scoreTable.add(std::pair<long,std::string>(5000, "Laurine"));
    scoreTable.add(std::pair<long,std::string>(60, "Marie"));
    scoreTable.add(std::pair<long,std::string>(21003, "Henry"));
    scoreTable.add(std::pair<long,std::string>(999999, "Wx234"));
    scoreTable.add(std::pair<long,std::string>(1000000, "Guillaume"));
    scoreTable.add(std::pair<long,std::string>(75213, "Amina"));
    
        //print the scores
    std::multimap<long,std::string>::const_iterator it;
    for(it=scoreTable.multimap().begin(); it!=scoreTable.multimap().end(); it++)
        std::cout << it->second << " : " << it->first << std::endl;
    
        //save the scores
    scoreTable.save("myWay.txt");
    
        //empty the multimap
    scoreTable.clear();
    
        //save the empty multimap
    scoreTable.save("clear.txt");
    */
    //test Score class #2
    /*
        //test contructor from file
    motor_game::Scores scoreTable("myWay.txt");
    
    
    // print the scores
    std::multimap<long,std::string>::const_iterator it;
    for(it=scoreTable.multimap().begin(); it!=scoreTable.multimap().end(); it++)
        std::cout << it->second << " : " << it->first << std::endl;
    */
    
    //test Score class #3
    //test add class, when several entry fir each user
        
        //create empty multimap (default : 7 values)
    motor_game::Scores scoreTable;
        // fill multimap
    scoreTable.add(std::pair<long,std::string>(12051, "Marion"));
    scoreTable.add(std::pair<long,std::string>(170, "Emilie"));
    scoreTable.add(std::pair<long,std::string>(100, "Valérian"));
    scoreTable.add(std::pair<long,std::string>(120, "Pierre"));
    scoreTable.add(std::pair<long,std::string>(5000, "Laurine"));
    scoreTable.add(std::pair<long,std::string>(21003, "Marie"));
    scoreTable.add(std::pair<long,std::string>(21003, "Henry"));
    scoreTable.add(std::pair<long,std::string>(999999, "Wx234"));
    scoreTable.add(std::pair<long,std::string>(1000000, "Guillaume"));
    scoreTable.add(std::pair<long,std::string>(75213, "Amina"));
    
        //print the scores
    std::multimap<long,std::string>::const_iterator it;
    for(it=scoreTable.multimap().begin(); it!=scoreTable.multimap().end(); it++)
        std::cout << it->second << " : " << it->first << std::endl;
    
    std::cout << std::endl;
        // fill multimap with same users
    scoreTable.add(std::pair<long,std::string>(60000, "Marion"));
    scoreTable.add(std::pair<long,std::string>(60, "Amina"));
    
        //print the scores
    for(it=scoreTable.multimap().begin(); it!=scoreTable.multimap().end(); it++)
        std::cout << it->second << " : " << it->first << std::endl;

    return 0;
}
