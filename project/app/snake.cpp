#include "snake.h"

CSnake::CSnake()
{
}

CSnake::~CSnake()
{
}

// Initialize a Snake with 3 Parts Moving Up
void CSnake::InitializeSnake(float _StartPosition[3])
{
    m_Snake.push_back(CSnakePart());
    m_Snake.push_back(CSnakePart());
    m_Snake.push_back(CSnakePart());

    m_Snake[0].SetXPosition(_StartPosition[0]);
    m_Snake[0].SetYPosition(_StartPosition[1]);
    m_Snake[0].SetZPosition(_StartPosition[2]);

    m_Snake[0].SetXDirection(0.0f);
    m_Snake[0].SetYDirection(1.0f);
    m_Snake[0].SetZDirection(0.0f);

    m_Snake[1].SetXPosition(_StartPosition[0]);
    m_Snake[1].SetYPosition(_StartPosition[1] - 1.0f);
    m_Snake[1].SetZPosition(_StartPosition[2]);

    m_Snake[1].SetXDirection(0.0f);
    m_Snake[1].SetYDirection(1.0f);
    m_Snake[1].SetZDirection(0.0f);

    m_Snake[2].SetXPosition(_StartPosition[0]);
    m_Snake[2].SetYPosition(_StartPosition[1] - 2.0f);
    m_Snake[2].SetZPosition(_StartPosition[2]);

    m_Snake[2].SetXDirection(0.0f);
    m_Snake[2].SetYDirection(1.0f);
    m_Snake[2].SetZDirection(0.0f);
}

// Add a Snakepart to the Snake
void CSnake::AddSnakePart(float _XPosition, float _YPosition, float _XDirection, float _YDirection)
{
    m_Snake.push_back(CSnakePart());

    m_Snake[m_Snake.size() - 1].SetXPosition(_XPosition);
    m_Snake[m_Snake.size() - 1].SetYPosition(_YPosition);
    m_Snake[m_Snake.size() - 1].SetZPosition(0.0f);

    m_Snake[m_Snake.size() - 1].SetXDirection(_XDirection);
    m_Snake[m_Snake.size() - 1].SetYDirection(_YDirection);
    m_Snake[m_Snake.size() - 1].SetZDirection(0.0f);
}

// Update Position of the snake per 1 Frame
void CSnake::UpdateSnakePosition(float _XDirection, float _YDirection)
{
    // Loop throuh the Parts of the snake backwards, n gets Attributes from n-1
    for (int counter = m_Snake.size() - 1; counter >= 1; counter--)
    {
        m_Snake[counter].SetXPosition(m_Snake[counter - 1].GetXPosition());
        m_Snake[counter].SetYPosition(m_Snake[counter - 1].GetYPosition());
        m_Snake[counter].SetZPosition(m_Snake[counter - 1].GetZPosition());

        m_Snake[counter].SetXDirection(m_Snake[counter - 1].GetXDirection());
        m_Snake[counter].SetYDirection(m_Snake[counter - 1].GetYDirection());
        m_Snake[counter].SetZDirection(m_Snake[counter - 1].GetZDirection());
    }

    // First part needs direction
    m_Snake[0].SetXPosition(m_Snake[0].GetXPosition() + _XDirection);
    m_Snake[0].SetYPosition(m_Snake[0].GetYPosition() + _YDirection);

    m_Snake[0].SetXDirection(_XDirection);
    m_Snake[0].SetYDirection(_YDirection);
}

// Return Size of the Snake
int CSnake::GetSnakeSize()
{
    return m_Snake.size();
}

void CSnake::ResetSnake()
{
    m_Snake.clear();
}

float CSnake::GetSnakePartXPosition(int _SnakePart)
{
    return m_Snake[_SnakePart].GetXPosition();
}

float CSnake::GetSnakePartYPosition(int _SnakePart)
{
    return m_Snake[_SnakePart].GetYPosition();
}

float CSnake::GetSnakePartZPosition(int _SnakePart)
{
    return m_Snake[_SnakePart].GetZPosition();
}

void CSnake::SetSnakePartXDirection(int _SnakePart, float _XDirection)
{
    m_Snake[_SnakePart].SetXDirection(_XDirection);
}

void CSnake::SetSnakePartYDirection(int _SnakePart, float _YDirection)
{
    m_Snake[_SnakePart].SetYDirection(_YDirection);
}

float CSnake::GetSnakePartXDirection(int _SnakePart)
{
    return m_Snake[_SnakePart].GetXDirection();
}

float CSnake::GetSnakePartYDirection(int _SnakePart)
{
    return m_Snake[_SnakePart].GetYDirection();
}