#include "detector_def.h"
#include "detector_objecta.h"
#include <stdlib.h>
#include <stdio.h>

struct detector_objectb
{
    int val;         
    struct detector api;
};

struct detector_objectb *
detector_objectb_create()
{
    struct detector_objectb *d = (struct detector_objectb *)malloc(sizeof(*d));
    d->val = 1;
    return d;
}

int
detector_objectb_destroy(struct detector_objectb *d)
{
    puts("objectb::destroy()");
    free(d);
    return 0;
}

int
detector_objectb_detect(struct detector_objectb *d)
{
    printf("%d\n", d->val);
    return 0;
}

struct detector *
make_detector_objectb()
{
    struct detector_objectb *d = detector_objectb_create();
    d->api.ptr = d;
    d->api.detect = (int (*)(void*))detector_objectb_detect;
    d->api.destroy = (int (*)(void*))detector_objectb_destroy;
    return &(d->api); // only return the api 
}
