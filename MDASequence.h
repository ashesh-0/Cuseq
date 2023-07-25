#ifndef _MDASequence_H_
#define _MDASequence_H_

#ifdef _MSC_VER
// We use exception specifications to instruct SWIG to generate the correct
// exception specifications for Java. Turn off the warnings that VC++ issues by
// the mere use of exception specifications (which VC++ does not implement).
#pragma warning(disable : 4290)
#endif

#include "TimePlan.h"
#include "MDAPosition.h"
#include "ZPlan.h"
#include "GridPlanFromEdges.h"
#include "string.h"
#include "Channel.h"
#include <tuple>

class MDASequence;

class MDASequence
{
public:
    MDASequence(std::string axisOrder, std::vector<Position> stagePositions,
    GridPlanFromEdges& grid, std::vector<Channel> channels, TimePlan& timePlan,
    ZPlan& zplan);
    // TODO: replace these classes with their base versions.
        
private:
    int uid_;
    unsigned int length_;
    std::tuple<float,float> fovSize_;

};

#endif //_MDASequence_H_
