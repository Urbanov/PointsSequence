#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "../structures/matrix.h"
#include "../structures/solution.h"

class Plot {
private:
	static constexpr char NAME[4] = "AAL";
	static constexpr int WIDTH = 800;
	static constexpr int HEIGHT = 600;
	static constexpr int FPS = 60;
	static constexpr char FONT_NAME[20] = "resources/arial.ttf";
	static constexpr int FONT_SIZE = 14;
	static const sf::Color FONT_COLOR; // sf::Color::White;
	static const sf::Color POINT_COLOR; // sf::Color::Green;
	static const sf::Color LINE_COLOR; // sf::Color::Red;

	sf::RenderWindow m_window;
	sf::VertexArray m_vertices;
	std::vector<sf::Text> m_weights;
	std::vector<sf::VertexArray> m_solutions;
	float m_scale_x;
	float m_scale_y;
	sf::Font m_font;
	int m_current;
	bool m_visible;

	sf::Vector2f translate(int x, int y) const;
	sf::Vertex createPoint(int x, int y) const;
	sf::Text createText(int x, int y, int weight) const;
	sf::Vertex createLine(int x, int y) const;
	void fillData(const Matrix<int>& vertices);
	void drawFrame();
	void changeSolution();
	void toggleVisibility();
	void handleEvents(const sf::Event& event);

public:
	explicit Plot(const Matrix<int>& vertices);
	void addSolution(const Solution& solution);
	void show();
};
