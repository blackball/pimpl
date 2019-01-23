#include "detector_objecta.h"
#include "detector_objectb.h"
#include "detector_def.h"
#include "detector.h"
#include <stdio.h>
#include <assert.h>

struct detector*
detector_create(int mode)
{
    switch (mode) 
    {
    case DETECTOR_TYPE_OBJECTA:
        return make_detector_objecta();
    case DETECTOR_TYPE_OBJECTB:
        return make_detector_objectb();
    default:
        assert(0);
    }
    return NULL;
}

int
detector_destroy(struct detector **pp)
{
    if (pp && *pp) {
        (*pp)->destroy((*pp)->ptr);
        *pp = NULL;
        return 0; 
    }
    return -1; 
}

int
detector_detect(struct detector *p)
{
    return p != NULL ? p->detect(p->ptr) : -1; 
}



