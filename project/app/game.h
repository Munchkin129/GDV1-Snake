#pragma once

#include "yoshix_fix_function.h"
#include "food.h"
#include "snakepart.h"
#include "snake.h"

#include <time.h>
#include <random>
#include <iostream>

using namespace gfx;

class CGame
{
public:
	CGame();
	~CGame();

private:

	float m_LastXDirection;
	float m_LastYDirection;

	int m_MinBorder;
	int m_MaxBorder;

	bool m_IsGameOver;

	float m_Scale;

	int m_SpeedUpInterval;

	float m_SpeedUpValue;

	float m_StartPositionSnake[3];
	float m_StartPositionFood[3];

	CSnake m_Snake;
	CSnakePart m_LastSnakePosition;
	CFood m_Food;

	float   m_StartTickSpeed;
	float   m_TickSpeed; // in seconds
	float   m_TickSpeedLimit;
	clock_t m_ThisTime;
	clock_t m_LastTime;
	float   m_TimeCounter;

	BHandle m_pWallMesh;
	BHandle m_pFoodMesh;
	BHandle m_pSnakeMesh;
	BHandle m_pSnakeHeadMesh;
	BHandle m_pGameOverMesh;

	BHandle m_pWallTexture;
	BHandle m_pFoodTexture;
	BHandle m_pSnakeTexture;
	BHandle m_pSnakeHeadTexture;
	BHandle m_pGameOverTexture;

private:

	void SetLastXDirection(float _XDirection);
	void SetLastYDirection(float _YDirection);

	float GetLastXDirection();
	float GetLastYDirection();

	void SetThisTime(clock_t _ThisTime);
	void SetLastTime(clock_t _LastTime);
	void SetTimeCounter(float _TimeCounter);

	clock_t GetThisTime();
	clock_t GetLastTime();
	float GetTimeCounter();


	int GetMinBorder();

	int GetMaxBorder();

	float GetScale();

	int GetSpeedUpInterval();

	float GetSpeedUpValue();

	void SetIsGameOver(bool _IsGameOver);

	bool GetIsGameOver();

	void SetTickSpeed(float _TickSpeed);

	float GetTickSpeed();

	float GetStartTickSpeed();

	float GetTickSpeedLimit();

	bool IsCollision(float _XPosition, float _YPosition, int _Start = 0);

	int GetRandomIntInRange(int _LowestNumber, int _HightesNumber);

	void AdjustTickSpeed(int _FoodCounter);

	void OutputGameScore();

	void RestartGame();

public:

	bool OnStartup();
	bool OnShutdown();

	bool OnCreateTextures();
	bool OnReleaseTextures();

	bool OnCreateMeshes();
	bool OnReleaseMeshes();

	bool OnUpdate();
	bool OnFrame();
	bool OnKeyEvent(unsigned int _Key, bool _IsKeyDown);

private:

	void OnCreateMesh(BHandle* _ppMesh, BHandle _pTexture);

	void CreateCube(BHandle* _ppMesh, BHandle _pTexture, float _EdgeLength);

	void CreateGameOverMesh(BHandle* _ppMesh, BHandle _pTexture, float _Height, float _AspectRatio);
};