#pragma once

class BoxCollideable;

class PhysicsEngine : public Manager
{
public:
	static PhysicsEngine* GetInstance();
	void RegisterCollider(BoxCollideable*);

	void Update() override;

	std::vector<std::unique_ptr<BoxCollideable>> m_Colliders;
private:
	PhysicsEngine();
	static PhysicsEngine* _Instance;
};

