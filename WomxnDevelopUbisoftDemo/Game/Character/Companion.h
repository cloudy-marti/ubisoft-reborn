#pragma once

class Companion : public Character
{
public:
	Companion(const Character&, const std::string&);
	void Update(float) override;
	bool IsNearLeader() const;

	bool IsAttached() const;
	void AttachToLeader();
	void CollidesLeader(float) const;

protected:
private:
	const Character& m_Leader;
	bool m_IsAttachedToLeader;

	float m_Distance;

	void DetachFromLeader();
};