#include <AnalogSensor.hpp>
#include <numeric>
#include <vector>
#include <memory>
AnalogSensor::AnalogSensor(unsigned int samples)
    : mSamples(samples)
{
}

AnalogSensor::~AnalogSensor()
{
}

int AnalogSensor::Read()
{
    std::vector<int> *readings = new std::vector<int>(mSamples, 10);

    /** To fix above memory leak as memory is allocated but not free when readings scopes out
    * One way is to use delete function call manually to free the memory before scopeing out.
    * second way is to use smart pointers which takes care of deleting and freeing memory automatically on scoping out
    */


    // std::unique_ptr<std::vector<int>> readings = std::make_unique<std::vector<int>>(mSamples,10);

    double result = std::accumulate( readings->begin(), readings->end(), 0.0 ) / readings->size();
    delete readings; // manually called to free the memory held by readings
    return result;
}


