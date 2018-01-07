#include "point.h"

Point::Point(int x, int y, int weight)
	: m_x(x)
	, m_y(y)
	, m_weight(weight)
{}

int Point::x() const
{
	return m_x;
}

int Point::y() const
{
	return m_y;
}

int Point::weight() const
{
	return m_weight;
}

bool Point::operator==(const Point& other) const
{
	return m_x == other.x() && m_y == other.y();
}

bool Point::operator<(const Point& other) const
{
	return (m_x < other.x()) || (m_x == other.x() && m_y < other.y());
}

bool Point::invalidConnection(const Point& first, const Point& second)
{
	return first.x() > second.x() || first.y() > second.y();
}

bool Point::validConnection(const Point& first, const Point& second)
{
	return !invalidConnection(first, second);
}
