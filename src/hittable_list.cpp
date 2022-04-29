#include "hittable_list.hpp"
#include "hittable.hpp"

HittableList::HittableList()
{ }

HittableList::HittableList(std::shared_ptr<Hittable> object)
{
    Add(object);
}

void HittableList::Clear()
{
    Objects.clear();
}

void HittableList::Add(std::shared_ptr<Hittable> object)
{
    Objects.push_back(object);
}

bool HittableList::IsHit(const Ray& ray, float tMin, float tMax, HitData& hitData) const
{
    HitData tempData;
    bool isHit = false;
    auto closestSoFar = tMax;
    
    for (const auto& object : Objects) {
        if (object->IsHit(ray, tMin, closestSoFar, tempData)) {
            isHit = true;
            closestSoFar = tempData.t;
            hitData = tempData;
        }
    }

    return isHit;
}
