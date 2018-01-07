#include "plot.h"
#include <iostream>

const sf::Color Plot::FONT_COLOR = sf::Color::White;
const sf::Color Plot::POINT_COLOR = sf::Color::Green;
const sf::Color Plot::LINE_COLOR = sf::Color::Red;

Plot::Plot(const Matrix<int>& vertices)
	: m_window()
	, m_vertices(sf::Points)
	, m_current(0)
	, m_visible(true)
{
	m_font.loadFromFile(FONT_NAME);
	m_scale_x = static_cast<float>(WIDTH - FONT_SIZE) / vertices.width();
	m_scale_y = static_cast<float>(HEIGHT - FONT_SIZE) / vertices.height();

	fillData(vertices);
}

sf::Vector2f Plot::translate(int x, int y) const
{
	return sf::Vector2f(x * m_scale_x + 1, HEIGHT - y * m_scale_y - 1);
}

sf::Vertex Plot::createPoint(int x, int y) const
{
	sf::Vertex vertex(translate(x, y));
	vertex.color = POINT_COLOR;
	return vertex;
}

sf::Text Plot::createText(int x, int y, int weight) const
{
	sf::Text text(std::to_string(weight), m_font);
	text.setCharacterSize(FONT_SIZE);
	text.setFillColor(FONT_COLOR);
	text.setPosition(translate(x, y));
	text.move(1, static_cast<float>(-FONT_SIZE));
	return text;
}

sf::Vertex Plot::createLine(int x, int y) const
{
	sf::Vertex vertex(translate(x, y));
	vertex.color = LINE_COLOR;
	return vertex;
}

void Plot::fillData(const Matrix<int>& vertices)
{
	for (int x = 0; x < vertices.width(); ++x) {
		for (int y = 0; y < vertices.height(); ++y) {
			if (vertices(x, y) != -1) {
				m_vertices.append(createPoint(x, y));
				m_weights.push_back(createText(x, y, vertices(x, y)));
			}
		}
	}
}

void Plot::drawFrame()
{
	m_window.clear();
	m_window.draw(m_solutions[m_current]);
	m_window.draw(m_vertices);
	if (m_visible) {
		std::for_each(m_weights.begin(), m_weights.end(), [&](const sf::Text& text) { m_window.draw(text); });
	}
	m_window.display();
}

void Plot::changeSolution()
{
	m_current = (m_current + 1) % m_solutions.size();
	std::cout << "\rShowing solution " + std::to_string(m_current + 1);
}

void Plot::toggleVisibility()
{
	m_visible = !m_visible;
}

void Plot::handleEvents(const sf::Event& event)
{
	switch (event.type) {
		case sf::Event::Closed:
			m_window.close();
			break;

		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left) {
				changeSolution();
			}
			else if (event.mouseButton.button == sf::Mouse::Right) {
				toggleVisibility();
			}
			break;
	}
}

void Plot::addSolution(const Solution& solution)
{
	sf::VertexArray line(sf::LinesStrip);
	auto points = solution.getPoints();
	std::for_each(points.begin(), points.end(), [&](const Point& point) { line.append(createLine(point.x(), point.y())); });
	m_solutions.push_back(line);
}

void Plot::show()
{
	m_window.create(sf::VideoMode(WIDTH, HEIGHT), NAME);
	m_window.setFramerateLimit(FPS);
	std::cout << "****************\nUse left mouse button to cycle through solutions\nUse right mouse button to toggle weights\n\nShowing solution 1";
	sf::Event event;

	while (m_window.isOpen()) {
		drawFrame();
		while (m_window.pollEvent(event)) {
			handleEvents(event);
		}
	}
}
