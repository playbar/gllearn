//
// Created by hou guoli on 2019/5/31.
//
#include <list>
#include "psimpl.h"


int main(int argc, char** argv)
{
    unsigned tolerance = 30;     // point count tolerance
    std::vector <double > polyline;     // original polyline, assume not empty
    std::vector <double> result;        // resulting simplified polyline

    for (int i = 0; i < 100 ; ++i) {
        polyline.push_back( i * 5 );
        polyline.push_back( i % 5 );
    }

// simplify the 4d polyline to 25 points
    psimpl::simplify_douglas_peucker_n <2> (
            polyline.begin (), polyline.end(),
            tolerance, std::back_inserter (result));

    return 0;
}