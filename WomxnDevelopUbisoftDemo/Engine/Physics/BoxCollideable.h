#pragma once

template<class T>
using onCollisionCallback = void(T::*)(const BoxCollideable&);

class BoxCollideable
{
public:
    enum class Tag
    {
        DEFAULT,
        PLAYER,
        COMPANION,
        ENEMY,
        CHECKPOINT,
        WALL,
        DAMAGING_OBJECT,
        HOLE,
        OUT_OF_SIM
    };

public:
    BoxCollideable()
        : m_Tag { Tag::DEFAULT }
    {
        PhysicsEngine::GetInstance()->RegisterCollider(this);
    }

    BoxCollideable(const BoxCollideable& other) = delete;
    BoxCollideable& operator=(const BoxCollideable&) = delete;
    ~BoxCollideable() = default;

    template<class T>
    inline void BindOnCollisionFunc(T& instance, onCollisionCallback<T> callBack)
    {
        m_OnCollisionFunc = std::bind(callBack, &instance, std::placeholders::_1);
    }


    inline const sf::FloatRect& GetBoundingBox() const { return m_BoundingBox; }

    inline const bool IsColliding(const BoxCollideable& other) const 
    { 
        return m_BoundingBox.intersects(other.GetBoundingBox());
    }
    inline const bool Contains(float x, float y) const { return m_BoundingBox.contains(x, y); }
    inline const bool Contains(const sf::Vector2f& pos) const { return m_BoundingBox.contains(pos); }
    inline const bool Contains(const BoxCollideable& other) const
    {
        auto bbox = other.GetBoundingBox();
        return m_BoundingBox.contains(bbox.left, bbox.top) && m_BoundingBox.contains(bbox.left + bbox.width, bbox.top + bbox.height);
    }

    inline const sf::Vector2f GetCenter() const
    {
        return sf::Vector2f(m_BoundingBox.left + (m_BoundingBox.width / 2.0f), m_BoundingBox.top + (m_BoundingBox.height / 2.0f));
    }

    inline const Tag getTag() const { return m_Tag; }
    inline void setTag(Tag tag) { m_Tag = tag; }

    inline void onCollision(const BoxCollideable& other) { m_OnCollisionFunc(other); }

    inline void SetBoundingBox(const sf::Vector2f& center, const sf::Vector2f& size)
    {
        m_BoundingBox.left = center.x - (size.x / 2.0f);
        m_BoundingBox.top = center.y - (size.y / 2.0f);
        m_BoundingBox.width = size.x;
        m_BoundingBox.height = size.y;
    }

    inline void SetCenter(const sf::Vector2f& center)
    {
        m_BoundingBox.left = center.x - (m_BoundingBox.width / 2.0f);
        m_BoundingBox.top = center.y - (m_BoundingBox.height / 2.0f);
    }

    //inline void setTag(Tag tag) { m_Tag = tag; }

protected:

    inline void SetBoundingBox(float left, float top, float width, float height)
    {
        m_BoundingBox.left = left;
        m_BoundingBox.top = top;
        m_BoundingBox.width = width;
        m_BoundingBox.height = height;
    }

    sf::FloatRect m_BoundingBox;
    Tag m_Tag;
    //void(*m_OnCollisionFunc)(const BoxCollideable&);
    std::function<void(const BoxCollideable&)> m_OnCollisionFunc;
};
