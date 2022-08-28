#pragma once

class CFood
{

public:

    CFood();
    CFood(float _Translation[3], int _FoodCounter);
    CFood(const CFood& _Food);
    ~CFood();

private:

    int m_FoodCounter;

    float m_Translation[3];

public:

    void AddOneFoodToCounter();

    void SetFoodCounter(int _FoodCounter);

    int GetFoodCounter();

    void InitializeFood(float _StartPosition[3]);

    void SetXPosition(float _XPosition);
    void SetYPosition(float _YPosition);
    void SetZPosition(float _ZPosition);

    float GetXPosition();
    float GetYPosition();
    float GetZPosition();
};