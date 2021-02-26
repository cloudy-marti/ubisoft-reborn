#pragma once
class Camera
{
public:
	Camera(const sf::View&);

	inline const sf::View& getView() const { return m_View; }
	inline const sf::Vector2f getCenter() const { return m_View.getCenter(); }
	
	inline void zoom(float factor) { m_View.zoom(factor); }
	inline void setCenter(sf::Vector2f newCenter) { m_View.setCenter(newCenter); }

protected:
private:
	sf::View m_View;
};

