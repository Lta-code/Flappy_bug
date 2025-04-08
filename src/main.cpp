#include "Gameloop.h"

int main(int argc, char *argv[])
{
    Gameloop* g = new Gameloop();

    g->Init();

    while (g->get_GameState()) // lặp đến khi GameState == false
    {
        g->Event();
        g->Update();
        g->Render();
    }

    g->Clear();

    delete g;

    return 0; // @_@ -> Lta
}
