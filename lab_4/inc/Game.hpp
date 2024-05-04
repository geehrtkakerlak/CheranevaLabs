#pragma once
#include <string>

#include <vector>
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"

namespace mt
{

    class Game
    {
        int m_width;
        int m_height;
        std::string m_capture;

        std::vector<mt::Circle> m_circles;
        std::vector<mt::Rectangle> m_rectangles;
        std::vector<mt::Triangle> m_triangels;
        std::vector<mt::Rectangle> m_lines;

        int m_n;
        sf::RenderWindow m_window;

    public:
        Game(int width, int height, const std::string &capture)
        {
            m_width = width;
            m_height = height;
            m_capture = capture;
        }

        void Setup(int n)
        {
            m_n = n;
            m_window.create(sf::VideoMode(m_width, m_height), m_capture);

            srand(time(0));

            for (int i = 0; i < m_n; i++)
            {
                int x = rand() % 1000;
                int y = rand() % 600;
                int r = rand() % 100 + 1;
                m_circles.push_back(mt::Circle(sf::Vector2f(x, y), r));
            }

            for (int i = 0; i < m_n; i++)
            {
                m_rectangles.push_back(mt::Rectangle(sf::Vector2f(10 + 20 * i, 10), sf::Vector2f{10.f, 15.f}));
            }

            for (int i = 0; i < m_n; i++)
            {
                m_triangels.push_back(mt::Triangle(sf::Vector2f(100 + 100 * i, 100), 20));
            }

            for (int i = 0; i < m_n; i++)
            {
                m_lines.push_back(mt::Rectangle(sf::Vector2f(500 + 100 * i, 200), sf::Vector2f{4, 50}));
            }
        }

        void LifeCycle()
        {
            while (m_window.isOpen())
            {
                // Îáðàáîòêà ñîáûòèé
                sf::Event event;
                while (m_window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        m_window.close();
                }

                m_window.clear();
                for (int i = 0; i < m_n; i++)
                {
                    m_window.draw(m_circles[i].Get());
                    m_window.draw(m_rectangles[i].Get());
                    m_window.draw(m_triangels[i].Get());
                    m_window.draw(m_lines[i].Get());
                }

                m_window.display();
            }
        }
    };

}