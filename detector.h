#ifndef DETECTOR_H
#define DETECTOR_H

#define DETECTOR_TYPE_OBJECTA 0
#define DETECTOR_TYPE_OBJECTB 1

struct detector;
struct detector * detector_create(int mode);
int detector_destroy(struct detector **pp);
int detector_detect(struct detector *p);

#endif /* DETECTOR_H */
