#define SDL_MAIN_HANDLED
#include"ball.h"
using namespace std;
ball :: ball()
{
    idle = true;
    facingLeft = false;
    frameClip = 0;
    FRAME_Idle = 10;
	DELAY_Idle = 6;
	setIdle();

	FRAME_MOVING = 8;
	DELAY_MOVING = 6;
	setMoving();



    x = 200;
    y = 200;
    playerdesRect = {x,y,50,43 };

    CatdesRect = {10,460,300,290};
    DogdesRect = {310,460,300,290};
    countdead = 0;
}
void ball::setMoving()
{
    for (int i = 0; i < FRAME_MOVING; i++)
	{
		clipsMOVING[i].x = i * 189;
		clipsMOVING[i].y = 0;
		clipsMOVING[i].w = 189;
		clipsMOVING[i].h = 165;
	}
}
void ball::setIdle()
{
	for (int i = 0; i < FRAME_Idle; i++)
	{
		clipsIDLE[i].x = i * 169;
		clipsIDLE[i].y = 0;
		clipsIDLE[i].w = 169;
		clipsIDLE[i].h = 147;
	}
}

void ball::animationIDLE()
{
	frameClip++;
	if (frameClip >= FRAME_Idle * DELAY_Idle) frameClip = 0;
	playersourceRect = clipsIDLE[frameClip / DELAY_Idle];
}
void ball:: animationMOVING()
{
    frameClip++;
    if (frameClip >= FRAME_MOVING * DELAY_MOVING) frameClip = 0;
	playersourceRect = clipsMOVING[frameClip / DELAY_MOVING];
}

void ball::MoveLeft()
{
    facingLeft = false;
	idle = false;
	if(x >=0 )
	x -= 4;
}

void ball::MoveRight()
{
    facingLeft = true;
	idle = false;
	if(x < 560)
	x += 4;
}
void ball::getinput()
{
	const Uint8* key = SDL_GetKeyboardState(NULL);
	idle = true;
	if (key[SDL_SCANCODE_A]) {
		ball::MoveLeft();
	}
	if (key[SDL_SCANCODE_D]) {

		ball::MoveRight();
	}
}
void ball::setdesrect() {
	playerdesRect.x = x;
	playerdesRect.y = y += 4;
}
void ball:: ballup()
{
    playerdesRect.x = x;
	playerdesRect.y = y -= 4 * 2;
}
void ball :: isDie()
{
     playerdesRect.x = x;
	playerdesRect.y = y -= 4 ;
}
