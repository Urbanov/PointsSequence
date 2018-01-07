#pragma once

#include <vector>
#include <string>
#include <sstream>

template <typename Type>
class Matrix {
private:
	std::vector<std::vector<Type>> m_matrix;
	int m_width;
	int m_height;

public:
	Matrix(int width, int height)
		: m_width(width)
		, m_height(height)
	{
		m_matrix.resize(width);
		for (auto& col : m_matrix) {
			col.resize(height, -1);
		}
	}

	Matrix(std::istream& is)
	{
		std::string line, rest;
		std::stringstream ss;
		getline(is, line);
		ss.str(line);
		if (!(ss >> m_width >> m_height) || ss >> rest) {
			throw std::runtime_error("Parsing error in line '" + line + "'");
		}
		if (m_width <= 0 || m_height <= 0) {
			throw std::runtime_error("Incorrect size '" + line + "'");
		}

		m_matrix.resize(m_width);
		for (auto& col : m_matrix) {
			col.resize(m_height, -1);
		}

		int x, y, weight;
		while (getline(is, line)) {
			ss.clear();
			ss.str(line);
			if (!(ss >> x >> y >> weight) || ss >> rest) {
				throw std::runtime_error("Parsing error in line '" + line + "'");
			}
			if (operator()(x, y) == -1) {
				operator()(x, y) = weight;
			}
			else {
				throw std::runtime_error("Point (" + std::to_string(x) + "," + std::to_string(y) + ") is already defined");
			}
		}
	}

	Type& operator()(int x, int y)
	{
		if (x >= m_width || y >= m_height) {
			throw std::runtime_error("Point (" + std::to_string(x) + "," + std::to_string(y) + ") exceeds boundaries");
		}
		return m_matrix[x][y];
	}

	const Type& operator()(int x, int y) const
	{
		if (x >= m_width || y >= m_height) {
			throw std::runtime_error("Point (" + std::to_string(x) + "," + std::to_string(y) + ") exceeds boundaries");
		}
		return m_matrix[x][y];
	}

	int height() const
	{
		return m_height;
	}

	int width() const
	{
		return m_width;
	}
};