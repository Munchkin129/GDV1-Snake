#include "snakepart.h"

CSnakePart::CSnakePart()
    : m_Translation{}
    , m_TranslationDelta{}
{
    m_Translation[0] = 0.0f;
    m_Translation[1] = 0.0f;
    m_Translation[2] = 0.0f;

    m_TranslationDelta[0] = 0.0f;
    m_TranslationDelta[1] = 0.0f;
    m_TranslationDelta[2] = 0.0f;
}

CSnakePart::CSnakePart(float _Translation[3], float _TranslationDelta[3])
    : m_Translation{}
    , m_TranslationDelta{}
{
    m_Translation[0] = _Translation[0];
    m_Translation[1] = _Translation[1];
    m_Translation[2] = _Translation[2];

    m_TranslationDelta[0] = _TranslationDelta[0];
    m_TranslationDelta[1] = _TranslationDelta[1];
    m_TranslationDelta[2] = _TranslationDelta[2];
}

CSnakePart::CSnakePart(const CSnakePart& _SnakePart)
{
    m_Translation[0] = _SnakePart.m_Translation[0];
    m_Translation[1] = _SnakePart.m_Translation[1];
    m_Translation[2] = _SnakePart.m_Translation[2];

    m_TranslationDelta[0] = _SnakePart.m_TranslationDelta[0];
    m_TranslationDelta[1] = _SnakePart.m_TranslationDelta[1];
    m_TranslationDelta[2] = _SnakePart.m_TranslationDelta[2];
}

CSnakePart::~CSnakePart()
{
}

void CSnakePart::SetXPosition(float _XPosition)
{
    m_Translation[0] = _XPosition;
}

void CSnakePart::SetYPosition(float _YPosition)
{
    m_Translation[1] = _YPosition;
}

void CSnakePart::SetZPosition(float _ZPosition)
{
    m_Translation[2] = _ZPosition;
}

float CSnakePart::GetXPosition()
{
    return m_Translation[0];
}

float CSnakePart::GetYPosition()
{
    return m_Translation[1];
}

float CSnakePart::GetZPosition()
{
    return m_Translation[2];
}

void CSnakePart::SetXDirection(float _XTranslation)
{
    m_TranslationDelta[0] = _XTranslation;
}

void CSnakePart::SetYDirection(float _YTranslation)
{
    m_TranslationDelta[1] = _YTranslation;
}

void CSnakePart::SetZDirection(float _ZTranslation)
{
    m_TranslationDelta[2] = _ZTranslation;
}

float CSnakePart::GetXDirection()
{
    return m_TranslationDelta[0];
}

float CSnakePart::GetYDirection()
{
    return m_TranslationDelta[1];
}

float CSnakePart::GetZDirection()
{
    return m_TranslationDelta[2];
}
