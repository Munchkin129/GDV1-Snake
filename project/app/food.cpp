#include "food.h"

CFood::CFood()
    : m_FoodCounter(0)
    , m_Translation{}
{
    m_Translation[0] = 0.0f;
    m_Translation[1] = 0.0f;
    m_Translation[2] = 0.0f;
}

CFood::CFood(float _Translation[3], int _FoodCounter)
    : m_FoodCounter(_FoodCounter)
    , m_Translation{}
{
    m_Translation[0] = _Translation[0];
    m_Translation[1] = _Translation[1];
    m_Translation[2] = _Translation[2];
}

CFood::CFood(const CFood& _Food)
{
    m_FoodCounter = _Food.m_FoodCounter;

    m_Translation[0] = _Food.m_Translation[0];
    m_Translation[1] = _Food.m_Translation[1];
    m_Translation[2] = _Food.m_Translation[2];
}

CFood::~CFood()
{
}

void CFood::SetFoodCounter(int _FoodCounter)
{
    m_FoodCounter = _FoodCounter;
}

void CFood::AddOneFoodToCounter()
{
    m_FoodCounter++;
}

int CFood::GetFoodCounter()
{
    return m_FoodCounter;
}

// Sets FoodCounter to Zero and Places Food at the given Position
void CFood::InitializeFood(float _StartPosition[3])
{
    SetXPosition(_StartPosition[0]);
    SetYPosition(_StartPosition[1]);
    SetZPosition(_StartPosition[2]);

    SetFoodCounter(0);
}

void CFood::SetXPosition(float _XPosition)
{
    m_Translation[0] = _XPosition;
}

void CFood::SetYPosition(float _YPosition)
{
    m_Translation[1] = _YPosition;
}

void CFood::SetZPosition(float _ZPosition)
{
    m_Translation[2] = _ZPosition;
}

float CFood::GetXPosition()
{
    return m_Translation[0];
}

float CFood::GetYPosition()
{
    return m_Translation[1];
}

float CFood::GetZPosition()
{
    return m_Translation[2];
}