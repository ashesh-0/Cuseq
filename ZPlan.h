#ifndef _ZPlan_H_
#define _ZPlan_H_

#ifdef _MSC_VER
// We use exception specifications to instruct SWIG to generate the correct
// exception specifications for Java. Turn off the warnings that VC++ issues by
// the mere use of exception specifications (which VC++ does not implement).
#pragma warning(disable : 4290)
#endif
class BaseZPlan
{
public:
    BaseZPlan( bool is_relative, bool go_up);
    virtual float nextZ() = 0;
    virtual void initialize() = 0;
    unsigned int numPositions();
protected:
    unsigned int size_;
    bool is_relative_;
    bool go_up_;
    float cur_z_;
    unsigned int cur_position_;
    float epsilon_; // to avoid rounding errors. Otherwise, when we go_up_ is false, 
                    // then the first element is not the bottom_.It gets skipped. 


};


class ZPlanTopBottom : public BaseZPlan
{
public:
    ZPlanTopBottom( float top, float bottom, float step, bool go_up);
    float nextZ();
    unsigned int numPositions();
    void initialize();
private:
    float top_;
    float bottom_;
    float step_;
};

#endif // _ZPlan_H_