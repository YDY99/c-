

#include "windows.h"
#include <iostream>

#include <consoleaoi2.h>
#include <tchar.h>
#include <string>
#include <strsafe.h>
#include <stdio.h>
#include "parser.h"
#include <conio.h>
#include "GameCore.h"






int main()
{
    TCHAR but[256];
    stringcchprintfw(buf, 256, TEXT(" % s 콘솔 텍스트 게임 버전 % f"))
    setconsoletitlew(buf);

    PlayerState player;
    WorldState world;
    InitializeGame(player, world);






    while (true)
    {
        RenderGame(player, world);// player의 x,y 좌표를 이동시켰습니다. y-1;
        GetInput(player, world);
        UpdateGame(player, world);
        // 플레이어의 입력 : if(Async wasd) -> if() -> if( )
        // Rendering : 이미지(맵)를 그려주는 것
        // Update    : 특정 위치에 도착하면 다음 맵으로 이동한다. 플레이어의 위치, 특정 장소의 위치 같은지 아닌지

        // Quit : 게임 종료 기능 함수, Bool Quit = true => break Exit(0);
    }

}

