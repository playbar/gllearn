//
// Created by hou guoli on 2019/5/31.
//
#include <list>
#include "psimpl.h"

int main(int argc, char** argv)
{
    unsigned tolerance = 25;     // point count tolerance
    std::list <long> polyline;   // original polyline, assume not empty
    std::vector <double> result; // resulting simplified polyline

// simplify the 4d polyline to 25 points
    psimpl::simplify_douglas_peucker_n <4> (
            polyline.begin (), polyline.end (),
            tolerance, std::back_inserter (result));

    return 0;
}