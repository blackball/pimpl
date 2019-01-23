### Pimpl

I was cleaning up a folder with dust overlayed mostly, found this small piece of codes which were writen years ago when I was struggling on searching for *clean && better* ways to implement some detector interfaces for a group of implementations. The idea seems still *OK*, so put here for a backup. 

The first version was writen in C++, the uses cases are something like: 
```c++
Detector da(Detector::Type::ObjectA);
da.Detect(img);

Detector db(Detctor::Type::ObjectB);
db.Detect(img);
```

The interfaces of Detector was something like this:
```
struct Detector 
{
    enum class Type 
    {
        ObjectA, 
        ObjectB, 
    };
    
    struct DetctorImpl; 
    
    Detector(Type t);
    virtual ~Detector();
    int Detect(const Image &img);
    
private:
    std::uniuqe_ptr<DetectorImpl> *m_impl;
};
```

I didn't like above design since it's not as simple as I want, too much cognitive burdern. The internal impl. will also be *not-so-tidy*. 

The output of that attempt was this *C-style* design. Till now, when I need to design the interfaces for similar situations, I always prefer this way and it works just fine. 

The C-style interfaces are like: 
```c
#define DETECTOR_TYPE_OBJECTA 0
#define DETECTOR_TYPE_OBJECTB 1
struct detector;
struct detector* detector_create(int type);
int detector_destroy(struct detector **pp);
int detector_detect(struct detector *p);
```

Please refer to the codes for more details.  
