#include <iostream>
#include "solution.h"
#include <algorithm>

Solution::Solution()
	: m_valid(false)
	, m_sum(0)
{}

Solution::Solution(const Point& point)
	: m_valid(false)
	, m_sum(0)
{
	m_points.push_back(point);
}

Solution::Solution(const std::vector<Point>& points)
	: m_valid(false)
	, m_sum(0)
	, m_points(points)
{}

int Solution::sum() const
{
	if (m_valid) {
		return m_sum;
	}

	int sum = 0;
	std::for_each(m_points.begin(), m_points.end(), [&](const Point& point) { sum += point.weight(); });
	m_valid = true;
	m_sum = sum;
	return sum;
}

bool Solution::operator>(const Solution& other) const
{
	return sum() > other.sum();
}

const std::vector<Point>& Solution::getPoints() const
{
	return m_points;
}

Solution& Solution::insert(const Point& point)
{
	m_points.push_back(point);
	m_valid = false;
	return *this;
}

Solution& Solution::merge(const Solution& other)
{
	m_points.insert(m_points.end(), other.m_points.begin(), other.m_points.end());
	m_valid = false;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Solution& solution) 
{
	for (const auto& point : solution.getPoints()) {
		os << point.x() << " " << point.y() << " " << point.weight() << std::endl;
	}
	return os;
}
