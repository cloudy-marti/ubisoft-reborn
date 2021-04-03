#pragma once

// class forwarding to avoid diamond inclusion
class BoxCollideable;

class PhysicsEngine
{
public:
	static PhysicsEngine* GetInstance();
	void RegisterCollider(BoxCollideable*);

	void Update();

	std::vector<BoxCollideable*> m_Colliders;
private:
	PhysicsEngine();
	static PhysicsEngine* _Instance;

};

