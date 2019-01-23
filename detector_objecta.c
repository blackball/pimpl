#include "detector_def.h"
#include "detector_objecta.h"
#include <stdlib.h>
#include <stdio.h>

struct detector_objecta
{
    int val;         
    struct detector api;
};

static struct detector_objecta *
detector_objecta_create()
{
    struct detector_objecta *d = (struct detector_objecta *)malloc(sizeof(*d));
    d->val = 0;
    return d;
}

static int
detector_objecta_destroy(struct detector_objecta *d)
{
    puts("objecta::destroy()");
    free(d);
    return 0;
}

static int
detector_objecta_detect(struct detector_objecta *d)
{
    printf("%d\n", d->val);
    return 0;
}

struct detector *
make_detector_objecta()
{
    struct detector_objecta *d = detector_objecta_create();
    d->api.ptr = d;
    d->api.detect = (int (*)(void*))detector_objecta_detect;
    d->api.destroy = (int (*)(void*))detector_objecta_destroy;
    return &(d->api); // only return the api 
}
