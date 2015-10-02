#include <fstream>

#include "gps.hpp"

const char *FILENAME = "gps.dat";

std::ostream &operator<<(std::ostream &s, gps_position const &g)
{
    s << "GPS(" << g.degrees << "/" << g.minutes << "/" << g.seconds << ")";
    return s;
}

void save(std::string const &root, gps_position const &g)
{
    // create and open a character archive for output
    std::ofstream ofs(root + "/" + FILENAME);
    boost::archive::text_oarchive oa(ofs);
    // write class instance to archive
    oa << g;
    // archive and stream closed when destructors are called
}

void load(std::string const &root, gps_position &g)
{
    // create and open an archive for input
    std::ifstream ifs(root + "/" + FILENAME);
    boost::archive::text_iarchive ia(ifs);
    // read class state from archive
    ia >> g;
    // archive and stream closed when destructors are called
}
