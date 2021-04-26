#include <stdafx.h>

PhysicsEngine* PhysicsEngine::_Instance = nullptr;

PhysicsEngine::PhysicsEngine()
{}

PhysicsEngine* PhysicsEngine::GetInstance()
{
    if (_Instance == nullptr)
    {
        _Instance = new PhysicsEngine();
    }
    return _Instance;
}

void PhysicsEngine::RegisterCollider(BoxCollideable* bBox)
{
    m_Colliders.emplace_back(bBox);
}

void PhysicsEngine::Update()
{
    m_Colliders.erase(std::remove_if(m_Colliders.begin(), m_Colliders.end(), [](std::unique_ptr<BoxCollideable>& bbox) { return bbox->getTag() == BoxCollideable::Tag::OUT_OF_SIM; }),
        m_Colliders.end());

    for (auto& bbox : m_Colliders)
    {
        for (auto& bbox1 : m_Colliders)
        {
            // this is the most common use case
            if (bbox->getTag() == BoxCollideable::Tag::WALL
                && bbox1->getTag() == BoxCollideable::Tag::WALL)
            {
                continue;
            }
            else if (bbox->IsColliding(*bbox1))
            {
                bbox->onCollision(*bbox1);
                bbox1->onCollision(*bbox);
            }
        }
    }
}