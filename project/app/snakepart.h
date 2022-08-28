#pragma once

class CSnakePart
{

public:

    CSnakePart();
    CSnakePart(float _Translation[3], float _TranslationDelta[3]);
    CSnakePart(const CSnakePart& _SnakePart);
    ~CSnakePart();

private:

    float m_Translation[3];
    float m_TranslationDelta[3];

public:

    void SetXPosition(float _XPosition);
    void SetYPosition(float _YPosition);
    void SetZPosition(float _ZPosition);

    float GetXPosition();
    float GetYPosition();
    float GetZPosition();

    void SetXDirection(float _XDirection);
    void SetYDirection(float _YDirection);
    void SetZDirection(float _ZDirection);

    float GetXDirection();
    float GetYDirection();
    float GetZDirection();
};