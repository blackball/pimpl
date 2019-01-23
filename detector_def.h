#ifndef DETECTOR_DEF_H
#define DETECTOR_DEF_H

struct detector
{
        void *ptr;
        int (*detect)(void* ptr);
        int (*destroy)(void* ptr);        
};

#endif /* DETECTOR_DEF_H */

