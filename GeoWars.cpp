
#include "Resources.h"
#include "GeoWars.h"
#include "Engine.h"    
#include "Delay.h" 

Player * BasicAI::player  = nullptr;
Audio  * BasicAI::audio   = nullptr;
Scene  * BasicAI::scene   = nullptr;
bool     BasicAI::viewHUD = false;
Image  * BasicAI::blue    = nullptr;
Image  * BasicAI::green   = nullptr;
Image  * BasicAI::magenta = nullptr;
Image  * BasicAI::orange  = nullptr; 

void BasicAI::Init() 
{ 
    audio = new Audio();
    audio->Add(START, "Resources/Start.wav");
    audio->Add(THEME, "Resources/Theme.wav");
    audio->Add(FIRE, "Resources/Fire.wav", 2);
    audio->Add(HITWALL, "Resources/Hitwall.wav", 5);
    audio->Add(EXPLODE, "Resources/Explode.wav", 3);
    audio->Add(ORANGE, "Resources/Orange.wav", 1);
    audio->Add(MAGENTA, "Resources/Magenta.wav", 2);
    audio->Add(BLUE, "Resources/Blue.wav", 2);
    audio->Add(GREEN, "Resources/Green.wav", 2); 
    audio->Volume(START, 0.30f);
    audio->Volume(THEME, 0.60f);
    audio->Volume(FIRE, 0.10f);
    audio->Volume(EXPLODE, 0.15f);
    audio->Volume(ORANGE, 0.90f);
    audio->Volume(MAGENTA, 0.40f);
    audio->Volume(BLUE, 0.20f);
    audio->Volume(GREEN, 0.75f); 
    blue    = new Image("Resources/Blue.png");
    green   = new Image("Resources/Green.png");
    magenta = new Image("Resources/Magenta.png");
    orange  = new Image("Resources/Orange.png"); 
    backg   = new Background("Resources/Space.jpg");
    player  = new Player();
    scene   = new Scene();  
    hud     = new Hud(); 
    scene->Add(player, MOVING);
    scene->Add(new Delay(), STATIC);    
    float difx = (game->Width() - window->Width()) / 2.0f;
    float dify = (game->Height() - window->Height()) / 2.0f; 
    viewport.left = 0.0f + difx;
    viewport.right = viewport.left + window->Width();
    viewport.top = 0.0f + dify;
    viewport.bottom = viewport.top + window->Height();
} 

void BasicAI::Update()
{ 
    if (window->KeyDown(VK_ESCAPE))
        window->Close(); 
    scene->Update();
    scene->CollisionDetection();   

    viewport.left   = player->X() - window->CenterX();
    viewport.right  = player->X() + window->CenterX();
    viewport.top    = player->Y() - window->CenterY();
    viewport.bottom = player->Y() + window->CenterY();
            
    if (viewport.left < 0)
    {
        viewport.left  = 0;
        viewport.right = window->Width();
    }
    else if (viewport.right > game->Width())
    {  
        viewport.left  = game->Width() - window->Width();
         viewport.right = game->Width();
    }
                  
    if (viewport.top < 0)
    {
        viewport.top  = 0;
        viewport.bottom = window->Height();
    }
    else if (viewport.bottom > game->Height())
    {
        viewport.top = game->Height() - window->Height();
        viewport.bottom = game->Height();
    }  
    hud->Update(); 
    if (window->KeyPress('B'))
        viewBBox = !viewBBox; 
    if (window->KeyPress('H'))
        viewHUD = !viewHUD;
} 

void BasicAI::Draw()
{ 
    backg->Draw(viewport); 
    scene->Draw(); 
    if (viewHUD)
        hud->Draw(); 
    if (viewBBox)
        scene->DrawBBox();
} 

void BasicAI::Finalize()
{
    delete audio;
    delete hud;
    delete scene;
    delete backg;

    delete blue;
    delete green;
    delete magenta;
    delete orange;
}   

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
                     _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{ 
    Engine * engine = new Engine(); 
    engine->window->Mode(FULLSCREEN);
    engine->window->Color(0, 0, 0);
    engine->window->Title("BasicAI");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);
    engine->window->HideCursor(true); 
    Game * game = new BasicAI(); 
    game->Size(1280,720); 
    int status = engine->Start(game); 
    delete engine; 
    return status;
} 