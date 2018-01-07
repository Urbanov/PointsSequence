#pragma once

#include <vector>
#include "point.h"

class Solution {
private:
	mutable bool m_valid;
	mutable int m_sum;
	std::vector<Point> m_points;

public:
	Solution();
	explicit Solution(const Point& point);
	explicit Solution(const std::vector<Point>& points);
	int sum() const;
	bool operator>(const Solution& other) const;
	const std::vector<Point>& getPoints() const;
	Solution& insert(const Point& point);
	Solution& merge(const Solution& other);

	friend std::ostream& operator<<(std::ostream& os, const Solution& solution);
};


