#include "yoshix_fix_function.h"

#include "game.h"

using namespace gfx;

namespace
{
    class CApplication : public IApplication
    {
    public:

        CApplication();
        virtual ~CApplication();

    private:

        float   m_FieldOfViewY;

        CGame   m_pGame;

    private:

        virtual bool InternOnCreateTextures();
        virtual bool InternOnReleaseTextures();
        virtual bool InternOnCreateMeshes();
        virtual bool InternOnReleaseMeshes();
        virtual bool InternOnResize(int _Width, int _Height);
        virtual bool InternOnUpdate();
        virtual bool InternOnFrame();

        virtual bool InternOnKeyEvent(unsigned int _Key, bool _IsKeyDown, bool _IsAltDown);
        virtual bool InternOnMouseEvent(int _X, int _Y, int _Button, bool _IsButt6onDown, bool _IsDoubleClick, int _WheelDelta);

    };
} // namespace

namespace
{
    CApplication::CApplication()
        : m_FieldOfViewY(60.0f)
        , m_pGame()
    {
    }

    CApplication::~CApplication()
    {
    }

    bool CApplication::InternOnCreateTextures()
    {
        m_pGame.OnCreateTextures();

        return true;
    }

    bool CApplication::InternOnReleaseTextures()
    {
        m_pGame.OnReleaseTextures();

        return true;
    }

    bool CApplication::InternOnCreateMeshes()
    {
        m_pGame.OnCreateMeshes();

        return true;
    }

    bool CApplication::InternOnReleaseMeshes()
    {
        m_pGame.OnReleaseMeshes();

        return true;
    }

    bool CApplication::InternOnResize(int _Width, int _Height)
    {
        float ProjectionMatrix[16];

        GetProjectionMatrix(m_FieldOfViewY, static_cast<float>(_Width) / static_cast<float>(_Height), 0.1f, 100.0f, ProjectionMatrix);

        SetProjectionMatrix(ProjectionMatrix);

        return true;
    }

    bool CApplication::InternOnUpdate()
    {
        float Eye[3];
        float At[3];
        float Up[3];

        float ViewMatrix[16];

        Eye[0] =   0.0f; At[0] = 0.0f; Up[0] = 0.0f;
        Eye[1] =   0.0f; At[1] = 0.0f; Up[1] = 2.0f;
        Eye[2] = -20.0f; At[2] = 0.0f; Up[2] = 0.0f;

        GetViewMatrix(Eye, At, Up, ViewMatrix);

        SetViewMatrix(ViewMatrix);

        m_pGame.OnUpdate();

        return true;
    }

    bool CApplication::InternOnFrame()
    {
        m_pGame.OnFrame();

        return true;
    }
    bool CApplication::InternOnKeyEvent(unsigned int _Key, bool _IsKeyDown, bool _IsAltDown)
    {
        m_pGame.OnKeyEvent(_Key, _IsKeyDown);

        return false;
    }
    bool CApplication::InternOnMouseEvent(int _X, int _Y, int _Button, bool _IsButtonDown, bool _IsDoubleClick, int _WheelDelta)
    {
        return false;
    }
} // namespace

void main()
{
    CApplication Application;

    RunApplication(800, 600, "Snake | Dirk Hofmann", &Application);
}