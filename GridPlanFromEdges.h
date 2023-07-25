#ifndef _GridPlanFromEdges_H_
#define _GridPlanFromEdges_H_

#ifdef _MSC_VER
// We use exception specifications to instruct SWIG to generate the correct
// exception specifications for Java. Turn off the warnings that VC++ issues by
// the mere use of exception specifications (which VC++ does not implement).
#pragma warning(disable : 4290)
#endif

#include "BaseGridPlan.h"
class BaseGridPlan;

class GridPlanFromEdges : public BaseGridPlan
{
public:
    GridPlanFromEdges( std::tuple<float, float> overlap, OrderMode mode, float top, float left, float bottom, float right);
    int numRows(float dy);
    int numCols(float dx);
    float offsetX(float dx);
    float offsetY(float dy);
private:
    float top_;
    float left_;
    float bottom_;
    float right_;
};

#endif // _GridPlanFromEdges_H_