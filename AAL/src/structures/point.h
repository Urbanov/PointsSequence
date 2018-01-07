#pragma once

class Point {
private:
	int m_x;
	int m_y;
	int m_weight;

public:
	Point(int x, int y, int weight);
	int x() const;
	int y() const;
	int weight() const;
	bool operator==(const Point& other) const;
	bool operator<(const Point& other) const;
	static bool invalidConnection(const Point& first, const Point& second);
	static bool validConnection(const Point& first, const Point& second);
};
