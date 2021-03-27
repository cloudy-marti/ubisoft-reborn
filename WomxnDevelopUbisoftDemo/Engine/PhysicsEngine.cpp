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
    m_Colliders.push_back(bBox);
}

void PhysicsEngine::Update()
{
    for (BoxCollideable* bbox : m_Colliders)
    {
        for (BoxCollideable* bbox1 : m_Colliders)
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