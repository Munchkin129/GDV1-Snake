#include "game.h"

CGame::CGame()
    : m_LastXDirection(0)
    , m_LastYDirection(1)
    , m_MinBorder(-10)
    , m_MaxBorder(10)
    , m_IsGameOver(false)
    , m_Scale(0.5f)
    , m_SpeedUpInterval(2)
    , m_SpeedUpValue(0.05f)
    , m_pWallMesh(nullptr)
    , m_pFoodMesh(nullptr)
    , m_pSnakeMesh(nullptr)
    , m_pSnakeHeadMesh(nullptr)
    , m_pGameOverMesh(nullptr)
    , m_pWallTexture(nullptr)
    , m_pFoodTexture(nullptr)
    , m_pSnakeTexture(nullptr)
    , m_pSnakeHeadTexture(nullptr)
    , m_pGameOverTexture(nullptr)
    , m_StartTickSpeed(0.5f)
    , m_TickSpeed(m_StartTickSpeed)
    , m_TickSpeedLimit(0.1f)
    , m_ThisTime(clock())
    , m_LastTime(m_ThisTime)
    , m_TimeCounter(0.0f)
    , m_StartPositionSnake{}
    , m_StartPositionFood{}
    , m_Snake{}
    , m_LastSnakePosition{}
    , m_Food{}
{
    m_StartPositionSnake[0] = 0.0f;
    m_StartPositionSnake[1] = 0.0f;
    m_StartPositionSnake[2] = 0.0f;

    m_Snake.InitializeSnake(m_StartPositionSnake);

    m_StartPositionFood[0] = 5.0f;
    m_StartPositionFood[1] = 7.0f;
    m_StartPositionFood[2] = 0.0f;

    m_Food.InitializeFood(m_StartPositionFood);
}

CGame::~CGame()
{
}

void CGame::SetLastXDirection(float _XDirection)
{
    m_LastXDirection = _XDirection;
}

void CGame::SetLastYDirection(float _YDirection)
{
    m_LastYDirection = _YDirection;
}

float CGame::GetLastXDirection()
{
    return m_LastXDirection;
}

float CGame::GetLastYDirection()
{
    return m_LastYDirection;
}

void CGame::SetThisTime(clock_t _ThisTime)
{
    m_ThisTime = _ThisTime;
}

void CGame::SetLastTime(clock_t _LastTime)
{
    m_LastTime = _LastTime;
}
void CGame::SetTimeCounter(float _TimeCounter)
{
    m_TimeCounter = _TimeCounter;
}

clock_t CGame::GetThisTime()
{
    return m_ThisTime;
}

clock_t CGame::GetLastTime()
{
    return m_LastTime;
}

float CGame::GetTimeCounter()
{
    return m_TimeCounter;
}

int CGame::GetMinBorder()
{
    return m_MinBorder;
}

int CGame::GetMaxBorder()
{
    return m_MaxBorder;
}

float CGame::GetScale()
{
    return m_Scale;
}

int CGame::GetSpeedUpInterval()
{
    return m_SpeedUpInterval;
}

float CGame::GetSpeedUpValue()
{
    return m_SpeedUpValue;
}


void CGame::SetIsGameOver(bool _IsGameOver)
{
    m_IsGameOver = _IsGameOver;
}

bool CGame::GetIsGameOver()
{
    return m_IsGameOver;
}

void CGame::SetTickSpeed(float _TickSpeed)
{
    m_TickSpeed = _TickSpeed;
}

float CGame::GetTickSpeed()
{
    return m_TickSpeed;
}

float CGame::GetStartTickSpeed()
{
    return m_StartTickSpeed;
}

float CGame::GetTickSpeedLimit()
{
    return m_TickSpeedLimit;
}

bool CGame::OnStartup()
{
    float ClearColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f, };

    SetClearColor(ClearColor);

    return true;
}

bool CGame::OnShutdown()
{
    return true;
}

bool CGame::OnCreateTextures()
{
    CreateTexture("..\\data\\images\\cube.dds", &m_pWallTexture);
    CreateTexture("..\\data\\images\\food.dds", &m_pFoodTexture);
    CreateTexture("..\\data\\images\\snake.dds", &m_pSnakeTexture);
    CreateTexture("..\\data\\images\\snake_head.dds", &m_pSnakeHeadTexture);
    CreateTexture("..\\data\\images\\game_over.dds", &m_pGameOverTexture);

    return true;
}

// -----------------------------------------------------------------------------

bool CGame::OnReleaseTextures()
{
    ReleaseTexture(m_pWallTexture);
    ReleaseTexture(m_pFoodTexture);
    ReleaseTexture(m_pSnakeTexture);
    ReleaseTexture(m_pSnakeHeadTexture);
    ReleaseTexture(m_pGameOverTexture);

    return true;
}

void CGame::CreateCube(BHandle* _ppMesh, BHandle _pTexture, float _EdgeLength)
{
    float s_HalfEdgeLength = 1.0f * _EdgeLength;

    float s_CubeVertices[][3] =
    {
        { -s_HalfEdgeLength, -s_HalfEdgeLength, -s_HalfEdgeLength, },
        {  s_HalfEdgeLength, -s_HalfEdgeLength, -s_HalfEdgeLength, },
        {  s_HalfEdgeLength,  s_HalfEdgeLength, -s_HalfEdgeLength, },
        { -s_HalfEdgeLength,  s_HalfEdgeLength, -s_HalfEdgeLength, },

        {  s_HalfEdgeLength, -s_HalfEdgeLength, -s_HalfEdgeLength, },
        {  s_HalfEdgeLength, -s_HalfEdgeLength,  s_HalfEdgeLength, },
        {  s_HalfEdgeLength,  s_HalfEdgeLength,  s_HalfEdgeLength, },
        {  s_HalfEdgeLength,  s_HalfEdgeLength, -s_HalfEdgeLength, },

        {  s_HalfEdgeLength, -s_HalfEdgeLength,  s_HalfEdgeLength, },
        { -s_HalfEdgeLength, -s_HalfEdgeLength,  s_HalfEdgeLength, },
        { -s_HalfEdgeLength,  s_HalfEdgeLength,  s_HalfEdgeLength, },
        {  s_HalfEdgeLength,  s_HalfEdgeLength,  s_HalfEdgeLength, },

        { -s_HalfEdgeLength, -s_HalfEdgeLength,  s_HalfEdgeLength, },
        { -s_HalfEdgeLength, -s_HalfEdgeLength, -s_HalfEdgeLength, },
        { -s_HalfEdgeLength,  s_HalfEdgeLength, -s_HalfEdgeLength, },
        { -s_HalfEdgeLength,  s_HalfEdgeLength,  s_HalfEdgeLength, },

        { -s_HalfEdgeLength,  s_HalfEdgeLength, -s_HalfEdgeLength, },
        {  s_HalfEdgeLength,  s_HalfEdgeLength, -s_HalfEdgeLength, },
        {  s_HalfEdgeLength,  s_HalfEdgeLength,  s_HalfEdgeLength, },
        { -s_HalfEdgeLength,  s_HalfEdgeLength,  s_HalfEdgeLength, },

        { -s_HalfEdgeLength, -s_HalfEdgeLength,  s_HalfEdgeLength, },
        {  s_HalfEdgeLength, -s_HalfEdgeLength,  s_HalfEdgeLength, },
        {  s_HalfEdgeLength, -s_HalfEdgeLength, -s_HalfEdgeLength, },
        { -s_HalfEdgeLength, -s_HalfEdgeLength, -s_HalfEdgeLength, },
    };

    float s_U[] =
    {
        0.0f / 4.0f,
        1.0f / 4.0f,
        2.0f / 4.0f,
        3.0f / 4.0f,
        4.0f / 4.0f,
    };

    float s_V[] =
    {
        3.0f / 3.0f,
        2.0f / 3.0f,
        1.0f / 3.0f,
        0.0f / 3.0f,
    };

    float s_CubeTexCoords[][2] =
    {
        { s_U[1], s_V[1], },
        { s_U[2], s_V[1], },
        { s_U[2], s_V[2], },
        { s_U[1], s_V[2], },

        { s_U[2], s_V[1], },
        { s_U[3], s_V[1], },
        { s_U[3], s_V[2], },
        { s_U[2], s_V[2], },

        { s_U[3], s_V[1], },
        { s_U[4], s_V[1], },
        { s_U[4], s_V[2], },
        { s_U[3], s_V[2], },

        { s_U[0], s_V[1], },
        { s_U[1], s_V[1], },
        { s_U[1], s_V[2], },
        { s_U[0], s_V[2], },

        { s_U[1], s_V[2], },
        { s_U[2], s_V[2], },
        { s_U[2], s_V[3], },
        { s_U[1], s_V[3], },

        { s_U[1], s_V[0], },
        { s_U[2], s_V[0], },
        { s_U[2], s_V[1], },
        { s_U[1], s_V[1], },
    };

    int s_CubeIndices[][3] =
    {
        {  0,  1,  2, },
        {  0,  2,  3, },

        {  4,  5,  6, },
        {  4,  6,  7, },

        {  8,  9, 10, },
        {  8, 10, 11, },

        { 12, 13, 14, },
        { 12, 14, 15, },

        { 16, 17, 18, },
        { 16, 18, 19, },

        { 20, 21, 22, },
        { 20, 22, 23, },
    };

    SMeshInfo MeshInfo;

    MeshInfo.m_pVertices = &s_CubeVertices[0][0];
    MeshInfo.m_pNormals = nullptr;
    MeshInfo.m_pColors = nullptr;
    MeshInfo.m_pTexCoords = &s_CubeTexCoords[0][0];
    MeshInfo.m_NumberOfVertices = 24;
    MeshInfo.m_NumberOfIndices = 36;
    MeshInfo.m_pIndices = &s_CubeIndices[0][0];
    MeshInfo.m_pTexture = _pTexture;

    CreateMesh(MeshInfo, _ppMesh);
}

void CGame::CreateGameOverMesh(BHandle* _ppMesh, BHandle _pTexture, float _Height, float _AspectRatio)
{
    float Width = _Height / _AspectRatio;

    static float s_QuadVertices[][3] =
    {
        { -_Height / 2, -Width / 2, 0.0f, },
        {  _Height / 2, -Width / 2, 0.0f, },
        {  _Height / 2,  Width / 2, 0.0f, },
        { -_Height / 2,  Width / 2, 0.0f, },
    };

    static float s_QuadTexCoords[][2] =
    {
        { 0.0f, 1.0f, },
        { 1.0f, 1.0f, },
        { 1.0f, 0.0f, },
        { 0.0f, 0.0f, },
    };

    static int s_QuadIndices[][3] =
    {
        { 0, 1, 2, },
        { 0, 2, 3, },
    };

    SMeshInfo MeshInfo;

    MeshInfo.m_pVertices = &s_QuadVertices[0][0];
    MeshInfo.m_pNormals = nullptr;                      // No normals.
    MeshInfo.m_pColors = nullptr;                      // No colors.
    MeshInfo.m_pTexCoords = &s_QuadTexCoords[0][0];
    MeshInfo.m_NumberOfVertices = 4;
    MeshInfo.m_NumberOfIndices = 6;
    MeshInfo.m_pIndices = &s_QuadIndices[0][0];
    MeshInfo.m_pTexture = _pTexture;

    CreateMesh(MeshInfo, _ppMesh);
}

bool CGame::OnCreateMeshes()
{
    CreateCube(&m_pWallMesh, m_pWallTexture, GetScale());
    CreateCube(&m_pFoodMesh, m_pFoodTexture, GetScale());
    CreateCube(&m_pSnakeMesh, m_pSnakeTexture, GetScale());
    CreateCube(&m_pSnakeHeadMesh, m_pSnakeHeadTexture, GetScale());

    CreateGameOverMesh(&m_pGameOverMesh, m_pGameOverTexture, 5, 1903 / 928);

    return true;
}

bool CGame::OnReleaseMeshes()
{
    ReleaseMesh(m_pWallMesh);
    ReleaseMesh(m_pFoodMesh);
    ReleaseMesh(m_pSnakeMesh);
    ReleaseMesh(m_pSnakeHeadMesh);
    ReleaseMesh(m_pGameOverMesh);

    return true;
}

int CGame::GetRandomIntInRange(int _LowestNumber, int _HightesNumber)
{
    std::random_device random;
    std::mt19937 gen(random());
    std::uniform_int_distribution<> distr(_LowestNumber, _HightesNumber);

    return distr(gen);
}

// Returns for a given Position true or false, if Snake has Collision with Position. _Start defines Starting Index from Snake
bool CGame::IsCollision(float _XPosition, float _YPosition, int _Start)
{
    for (int counter = _Start; counter < m_Snake.GetSnakeSize(); counter++)
    {
        if ((m_Snake.GetSnakePartXPosition(counter) == _XPosition) && (m_Snake.GetSnakePartYPosition(counter) == _YPosition))
        {
            return true;
        }
    }

    return false;
}

bool CGame::OnUpdate()
{
    SetThisTime(clock());

    SetTimeCounter(GetTimeCounter() + (GetThisTime() - GetLastTime()));

    SetLastTime(GetThisTime());

    if (GetIsGameOver()) {
        // Ensures TimeCounter still works
        if (GetTimeCounter() > (GetTickSpeed() * CLOCKS_PER_SEC))
        {
            SetTimeCounter(GetTimeCounter() - (GetTickSpeed() * CLOCKS_PER_SEC));
        }

        return true;
    }

    // Ensures a Game Update with Tick Speed
    if (GetTimeCounter() > (GetTickSpeed() * CLOCKS_PER_SEC))
    {
        // Saves Position of Last Part of the Snake if it eats 
        m_LastSnakePosition.SetXPosition(m_Snake.GetSnakePartXPosition(m_Snake.GetSnakeSize() - 1));
        m_LastSnakePosition.SetYPosition(m_Snake.GetSnakePartYPosition(m_Snake.GetSnakeSize() - 1));

        // Updates Snake Position
        m_Snake.UpdateSnakePosition(m_Snake.GetSnakePartXDirection(0), m_Snake.GetSnakePartYDirection(0));

        // Updates Last Directions
        SetLastXDirection(m_Snake.GetSnakePartXDirection(0));
        SetLastYDirection(m_Snake.GetSnakePartYDirection(0));

        // Looks for Collsion with Border
        if (m_Snake.GetSnakePartXPosition(0) <= GetMinBorder() || m_Snake.GetSnakePartXPosition(0) >= GetMaxBorder() || m_Snake.GetSnakePartYPosition(0) <= GetMinBorder() || m_Snake.GetSnakePartYPosition(0) >= GetMaxBorder())
        {
            OutputGameScore();
            SetIsGameOver(true);
        }

        // Looks for Food Collsion
        if (m_Snake.GetSnakePartXPosition(0) == m_Food.GetXPosition() && m_Snake.GetSnakePartYPosition(0) == m_Food.GetYPosition())
        {
            m_Food.AddOneFoodToCounter();

            int tempXPosition;
            int tempYPosition;
            do
            {
                tempXPosition = GetRandomIntInRange(GetMinBorder() + 1, GetMaxBorder() - 1);
                tempYPosition = GetRandomIntInRange(GetMinBorder() + 1, GetMaxBorder() - 1);
            } while (IsCollision(tempXPosition, tempYPosition, 0));

            m_Food.SetXPosition(tempXPosition);
            m_Food.SetYPosition(tempYPosition);

            m_Snake.AddSnakePart(m_LastSnakePosition.GetXPosition(), m_LastSnakePosition.GetYPosition(), m_LastSnakePosition.GetXDirection(), m_LastSnakePosition.GetXDirection());

            AdjustTickSpeed(m_Food.GetFoodCounter());
        }

        // Looks for Snake Collsion, Starting with Index One, otherwise always true
        if (IsCollision(m_Snake.GetSnakePartXPosition(0), m_Snake.GetSnakePartYPosition(0), 1))
        {
            OutputGameScore();
            SetIsGameOver(true);
        }

        // Resets TimeCounter
        SetTimeCounter(GetTimeCounter() - (GetTickSpeed() * CLOCKS_PER_SEC));
    }


    return true;
}

bool CGame::OnFrame()
{
    float TranslationMatrix[16];
    float ScaleMatrix[16];
    float RotationMatrix[16];

    float WorldMatrix[16];

    // Draw Border
    for (int counterX = GetMinBorder(); counterX <= GetMaxBorder(); counterX++)
    {
        for (int counterY = GetMinBorder(); counterY <= GetMaxBorder(); counterY++)
        {
            if (counterX == GetMinBorder() || counterX == GetMaxBorder() || counterY == GetMinBorder() || counterY == GetMaxBorder())
            {
                GetTranslationMatrix(counterX, counterY, 0.0f, WorldMatrix);
                SetWorldMatrix(WorldMatrix);
                DrawMesh(m_pWallMesh);
            }
        }
    }

    // Draw Background
    for (int counterX = GetMinBorder() + 1; counterX < GetMaxBorder(); counterX++)
    {
        for (int counterY = GetMinBorder() + 1; counterY < GetMaxBorder(); counterY++)
        {
            GetTranslationMatrix(counterX, counterY, 1.0f, WorldMatrix);
            SetWorldMatrix(WorldMatrix);
            DrawMesh(m_pWallMesh);
        }
    }
    // Draw Snake Head
    GetTranslationMatrix(m_Snake.GetSnakePartXPosition(0), m_Snake.GetSnakePartYPosition(0), m_Snake.GetSnakePartZPosition(0), TranslationMatrix);
    if (m_Snake.GetSnakePartXDirection(0) == -1.0f)
    {
        GetRotationZMatrix(90.0f, RotationMatrix);
        MulMatrix(RotationMatrix, TranslationMatrix, WorldMatrix);
    }
    if (m_Snake.GetSnakePartXDirection(0) == 1.0f)
    {
        GetRotationZMatrix(270.0f, RotationMatrix);
        MulMatrix(RotationMatrix, TranslationMatrix, WorldMatrix);
    }
    if (m_Snake.GetSnakePartYDirection(0) == -1.0f)
    {
        GetRotationZMatrix(180.0f, RotationMatrix);
        MulMatrix(RotationMatrix, TranslationMatrix, WorldMatrix);
    }
    if (m_Snake.GetSnakePartYDirection(0) == 1.0f)
    {
        GetRotationZMatrix(0.0f, RotationMatrix);
        MulMatrix(RotationMatrix, TranslationMatrix, WorldMatrix);
    }
    SetWorldMatrix(WorldMatrix);
    DrawMesh(m_pSnakeHeadMesh);

    // Draw Snake Body
    for (int counter = 1; counter < m_Snake.GetSnakeSize(); counter++)
    {
        GetTranslationMatrix(m_Snake.GetSnakePartXPosition(counter), m_Snake.GetSnakePartYPosition(counter), m_Snake.GetSnakePartZPosition(counter), TranslationMatrix);
        if (m_Snake.GetSnakePartXDirection(counter) == -1.0f)
        {
            GetRotationZMatrix(90.0f, RotationMatrix);
            MulMatrix(RotationMatrix, TranslationMatrix, WorldMatrix);
        }
        if (m_Snake.GetSnakePartXDirection(counter) == 1.0f)
        {
            GetRotationZMatrix(270.0f, RotationMatrix);
            MulMatrix(RotationMatrix, TranslationMatrix, WorldMatrix);
        }
        if (m_Snake.GetSnakePartYDirection(counter) == -1.0f)
        {
            GetRotationZMatrix(180.0f, RotationMatrix);
            MulMatrix(RotationMatrix, TranslationMatrix, WorldMatrix);
        }
        if (m_Snake.GetSnakePartYDirection(counter) == 1.0f)
        {
            GetRotationZMatrix(0.0f, RotationMatrix);
            MulMatrix(RotationMatrix, TranslationMatrix, WorldMatrix);
        }
        SetWorldMatrix(WorldMatrix);
        DrawMesh(m_pSnakeMesh);
    }

    // Draw Food
    GetTranslationMatrix(m_Food.GetXPosition(), m_Food.GetYPosition(), m_Food.GetZPosition(), WorldMatrix);
    SetWorldMatrix(WorldMatrix);
    DrawMesh(m_pFoodMesh);

    // Draw Game Over
    if (GetIsGameOver())
    {
        GetScaleMatrix(3.0f, ScaleMatrix);
        GetTranslationMatrix(0.0f, 0.0f, -1.0f, TranslationMatrix);

        MulMatrix(ScaleMatrix, TranslationMatrix, WorldMatrix);

        SetWorldMatrix(WorldMatrix);
        DrawMesh(m_pGameOverMesh);
    }

    return true;
}

bool CGame::OnKeyEvent(unsigned int _Key, bool _IsKeyDown)
{
    if (_Key == 'W' && GetLastYDirection() != -1.0f)
    {
        m_Snake.SetSnakePartXDirection(0, 0.0f);

        m_Snake.SetSnakePartYDirection(0, 1.0f);
    }

    if (_Key == 'S' && GetLastYDirection() != 1.0f)
    {
        m_Snake.SetSnakePartXDirection(0, 0.0f);

        m_Snake.SetSnakePartYDirection(0, -1.0f);
    }

    if (_Key == 'D' && GetLastXDirection() != -1.0f)
    {
        m_Snake.SetSnakePartXDirection(0, 1.0f);

        m_Snake.SetSnakePartYDirection(0, 0.0f);
    }

    if (_Key == 'A' && GetLastXDirection() != 1.0f)
    {
        m_Snake.SetSnakePartXDirection(0, -1.0f);

        m_Snake.SetSnakePartYDirection(0, 0.0f);
    }

    if (GetIsGameOver() && _IsKeyDown)
        RestartGame();

    return true;
}

void CGame::AdjustTickSpeed(int _FoodCounter)
{
    if (_FoodCounter % GetSpeedUpInterval() == 0)
    {
        if (GetTickSpeed() > GetTickSpeedLimit())
        {
            SetTickSpeed(GetTickSpeed() - GetSpeedUpValue());
        }
    }
}

void CGame::OutputGameScore()
{
    std::cout << "You collected " << m_Food.GetFoodCounter() << " Melons. Congratulations!" << std::endl;
}

void CGame::RestartGame()
{
    SetIsGameOver(false);

    // Reset Snake
    m_Snake.ResetSnake();
    m_Snake.InitializeSnake(m_StartPositionSnake);

    // Reset Food
    m_Food.InitializeFood(m_StartPositionFood);

    // Reset Tickspeed
    SetTickSpeed(GetStartTickSpeed());

    // Reset X and Y Direction
    m_Snake.SetSnakePartXDirection(0, 0.0f);
    m_Snake.SetSnakePartYDirection(0, 1.0f);
    SetLastXDirection(0.0f);
    SetLastYDirection(1.0f);
}