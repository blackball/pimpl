#include "detector.h"

int main()
{
    struct detector *d = detector_create(DETECTOR_TYPE_OBJECTA);
    detector_detect(d);
    detector_destroy(&d);
    detector_destroy(&d);

    d = detector_create(DETECTOR_TYPE_OBJECTB);
    detector_detect(d);
    detector_destroy(&d);
    detector_destroy(&d);    
    return 0;
}
