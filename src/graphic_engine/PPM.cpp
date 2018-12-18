
namespace graphic_engine{
    
    PPM::PPM(const std::string &filename)
    {
        m_ppm.open(filename);
        std::abort(ppm.is_open());
    }
    
    PPM::~PPM(){
        m_ppm.close();
    }
}
