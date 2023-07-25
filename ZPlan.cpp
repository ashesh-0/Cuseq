#ifndef _WINDOWS
// Needed on Unix for getcwd() and gethostname()
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>
#else
// for _getcwd
#include <direct.h>
#include <vector>
#endif

#include "ZPlan.h"
#include <cmath>
#include <iostream>

using namespace std;

BaseZPlan::BaseZPlan( bool is_relative, bool go_up):
    is_relative_(is_relative),
    go_up_(go_up),
    cur_position_(-1),
    epsilon_(1e-6)
{
    ;
}
unsigned int BaseZPlan::numPositions()
{
    return size_;
}

ZPlanTopBottom::ZPlanTopBottom( float top, float bottom, float step, bool go_up):
    BaseZPlan(false, go_up),
    top_(top),
    bottom_(bottom),
    step_(step)
{
    ;
}

void ZPlanTopBottom::initialize()
{
    if (go_up_)
        cur_z_ = bottom_ - step_;
    else
    {
        int count = (top_ + step_ - bottom_)/ step_;
        cur_z_ = bottom_ + count * step_ + epsilon_; 
    }
}

float ZPlanTopBottom::nextZ()
{
    if (go_up_)
    {
        cur_z_ = cur_z_ + step_;
        if (cur_z_ > top_)
        {
            cur_z_ = (float) INT_MIN;
        }
    }
    else
    {
        cur_z_ = cur_z_ - step_;
        cout << cur_z_ << " " << bottom_<< cur_z_ - bottom_<< endl;
        if (cur_z_ < bottom_)
        {
            cur_z_ = (float) INT_MIN;
        }
    }
    cur_position_++;
    return cur_z_;
}

unsigned int ZPlanTopBottom::numPositions()
{
    return ceil(abs(top_ + step_ - bottom_) / step_);
}

int main(){
    auto obj = ZPlanTopBottom( 3.0, 1.0, 1.1, false);
    obj.initialize();
    auto next = obj.nextZ();
    cout << "z: " << next << endl;
    next = obj.nextZ();
    cout << "z: " << next << endl;
    next = obj.nextZ();
    cout << "z: " << next << endl;
}