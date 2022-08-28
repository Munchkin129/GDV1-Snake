#pragma once

#include "snakepart.h"

#include <vector>

class CSnake
{
public:
	CSnake();
	~CSnake();

private:

	std::vector<CSnakePart> m_Snake;

public:

	void InitializeSnake(float _StartPosition[3]);

	void AddSnakePart(float _XPosition, float _YPosition, float _XDirection, float _YDirection);

	void UpdateSnakePosition(float _XDirection, float _YDirection);

	int GetSnakeSize();

	void ResetSnake();

	float GetSnakePartXPosition(int _SnakePart);
	float GetSnakePartYPosition(int _SnakePart);
	float GetSnakePartZPosition(int _SnakePart);

	void SetSnakePartXDirection(int _SnakePart, float _XDirection);
	void SetSnakePartYDirection(int _SnakePart, float _YDirection);

	float GetSnakePartXDirection(int _SnakePart);
	float GetSnakePartYDirection(int _SnakePart);
};