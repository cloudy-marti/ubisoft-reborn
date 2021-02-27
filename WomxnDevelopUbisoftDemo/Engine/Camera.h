#pragma once
class Camera
{
public:
	Camera(const sf::View&);

	inline const sf::View& getView() const { return m_View; }
	inline const sf::Vector2f getCenter() const { return m_View.getCenter(); }
	
	inline void ZoomIn() { m_View.zoom(0.9f); }
	inline void ZoomOut() { m_View.zoom(1.1f); }
	
	inline void setCenter(const sf::Vector2f& newCenter) { m_View.setCenter(newCenter); }

protected:
private:
	sf::View m_View;
};

