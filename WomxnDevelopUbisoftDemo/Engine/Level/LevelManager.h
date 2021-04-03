#pragma once
class LevelManager
{
public:
	static LevelManager* GetInstance();

private:
	LevelManager();
	static LevelManager* _Instance;
};

