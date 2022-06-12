#ifndef HittableList_hpp
#define HittableList_hpp

#include "Hittable.hpp"

#include <memory>
#include <vector>

class HittableList : public Hittable
{
public:
    HittableList();
    HittableList(std::shared_ptr<Hittable> object);

    void Clear();
    void Add(std::shared_ptr<Hittable> object);

    virtual bool IsHit(const Ray& ray, float tMin, float tMax, HitData& hitData) const override;

public:
    std::vector<std::shared_ptr<Hittable>> Objects;
};

#endif /* HittableList_hpp */
