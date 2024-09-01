#include "GameCore.h"
#include "Parser.h"
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>



namespace TextConsole
{
	MapData CreateRoom(const std::string & inName, const std::string & inDescription)
	{
		MapData room = {};
		room.Name = inName;
		room.Description = inDescription;

		return room;
	}
	ItemData CreateItem(ItemType type, int xPosition, int yPosition)
	{
		ItemData item = {};
		item.Type = type;
		item.ItemPosition.X = xPosition;
		item.ItemPosition.Y = yPosition;
		item.Quantity = 1;

		return item;
	}
	LockedDoorData CreateLockedDoor(int xPosition, int yPosition)
	{
		LockedDoorData lockedDoor = {};
		lockedDoor.DoorPosition.X = xPosition;
		lockedDoor.DoorPosition.Y = yPosition;

		return lockedDoor;
	}

	
	
	void InitializeGame(PlayerState& playerState, WorldState& worldState)
{
	std::cout << "??? 섬에 오신것을 환영합니다." << std::endl;
	std::cout << "이 섬에 대한 추가 정보를 입력해주세요." << std::endl;

	playerState.CurrentPosition.posX = playerState.NewPosition.posX = 3;
	playerState.CurrentPosition.posY = playerState.NewPosition.posY = 3;

	// 첫번째 맵에 대한 정보
	// 0
	{
		std::string MapInfo =
			"###..###"
			"#......#"
			"#......#"
			"#......#"
			"########";

		MapData map = MapData("초원", "경치가 아름다운 곳이다. 앞에 이동할 수 있는 문이 보이는 것 같다.", MapInfo);
		map.MapPosition.posX = 0;
		map.MapPosition.posY = 0;

		
		
		
		
		worldState.Mapdatas.push_back(map);


		void InitializeGame(PlayerState & playerState, WorldState & worldState)
		{
			printf("???섬에 오신 것을 환영합니다.\n");
			printf("텍스트 어드벤쳐 에디션\n\n");

			playerState.WantsDescription = true;
			playerState.CurrentRoomIndex = 0;
			playerState.CurrentPosition.X = playerState.NewPosition.X = 3;
			playerState.CurrentPosition.Y = playerState.NewPosition.Y = 2;

			worldState.Rooms.clear();

			// 0
			{
				MapData room = CreateRoom("해변", "경치가 아름다운 곳이지만 생명체의 흔적을 전혀 찾을 수 없어 공허하게 느껴지는 곳이다.");

				room.RoomMapWidth = 8;
				room.RoomMap =
					"###..###"
					"#......#"
					"#......#"
					"#......#"
					"########";
				room.MapPosition.X = 0;
				room.MapPosition.Y = 0;

				/*LockedDoorData lockedDoor = {};
				lockedDoor.DoorPosition.X = 2;
				lockedDoor.DoorPosition.Y = 3;*/

				worldState.Rooms.push_back(room);

			}

			// 1
			{
				MapData room = CreateRoom("숲속", "울창한 수림에 둘러 쌓여 있다. 나뭇잎 사이로 빗살 같은 스며드는 볕이 보인다.");

				room.RoomMapWidth = 8;
				room.RoomMap =
					"###==###"
					"#%.....#"
					"....%%.."
					"#.%..%.#"
					"###..###";
				room.MapPosition.X = 0;
				room.MapPosition.Y = -1;

				worldState.Rooms.push_back(room);
			}

			// 2
			{
				MapData room = CreateRoom("흉가", "이 집은 함정이야!");

				room.RoomMapWidth = 8;
				room.RoomMap =
					"########"
					"#%%%%%%#"
					"#..||..."
					"#......#"
					"########";
				room.MapPosition.X = -1;
				room.MapPosition.Y = -1;

				ItemData key = CreateItem(ItemType_KEY, 1, 2);
				room.Inventory.push_back(key);

				LockedDoorData lockedDoor = CreateLockedDoor(7, 2);
				room.LockedDoor.push_back(lockedDoor);

				worldState.Rooms.push_back(room);
			}
			// 3
			{
				MapData room = CreateRoom("숲속 ", "울창한 수림에 둘러 쌓여 있다. 나뭇잎 사이로 빗살 같은 스며드는 볕이 보인다.");

				room.RoomMapWidth = 8;
				room.RoomMap =
					"###..###"
					"#%%%...#"
					"..%%%%.#"
					"#......#"
					"########";
				room.MapPosition.X = 1;
				room.MapPosition.Y = -1;

				worldState.Rooms.push_back(room);
			}
			// 4
			{
				MapData room = CreateRoom("숲속", "울창한 수림에 둘러 쌓여 있다. 나뭇잎 사이로 빗살 같은 스며드는 볕이 보인다.");

				room.RoomMapWidth = 8;
				room.RoomMap =
					"###..###"
					"#......#"
					"#.%%%%.#"
					"#......#"
					"###..###";
				room.MapPosition.X = 1;
				room.MapPosition.Y = -2;

				ItemData item = CreateItem(ItemType_BOOK, 3, 1);
				room.Inventory.push_back(item);

				worldState.Rooms.push_back(room);
			}
			// 5
			{
				MapData room = CreateRoom("어둠의 숲", "주위가 매우 어둡다. 어둠에 서서히 잠식 당하는 느낌이다. ");

				room.RoomMapWidth = 8;
				room.RoomMap =
					"########"
					"#%....%#"
					"...||..#"
					"#%....%#"
					"###..###";
				room.MapPosition.X = 1;
				room.MapPosition.Y = -3;

				ItemData item = CreateItem(ItemType_BOOK, 3, 1);
				room.Inventory.push_back(item);

				ItemData item2 = CreateItem(ItemType_COIN, 4, 1);
				room.Inventory.push_back(item2);

				worldState.Rooms.push_back(room);
			}
			// 6
			{
				MapData room = CreateRoom("보스 등장", "거대한 위험이 다가오는 것을 느낄 수 있다. ");

				room.RoomMapWidth = 8;
				room.RoomMap =
					"########"
					"#%.....#"
					"#%%.%%.."
					"#%....%#"
					"###..###";
				room.MapPosition.X = 0;
				room.MapPosition.Y = -3;

				ItemData key = CreateItem(ItemType_KEY, 4, 3);
				room.Inventory.push_back(key);

				LockedDoorData lockedDoor = CreateLockedDoor(3, 4);
				room.LockedDoor.push_back(lockedDoor);
				LockedDoorData lockedDoor2 = CreateLockedDoor(4, 4);
				room.LockedDoor.push_back(lockedDoor2);

				worldState.Rooms.push_back(room);
			}
			// 7
			{
				MapData room = CreateRoom("보스 방", "축하합니다! quit을 입력해서 게임을 종료하세요.");

				room.RoomMapWidth = 8;
				room.RoomMap =
					"###==###"
					"#......#"
					"#......#"
					"#......#"
					"###==###";
				room.MapPosition.X = 0;
				room.MapPosition.Y = -2;


				ItemData item3 = CreateItem(ItemType_SWORD, 4, 3);
				room.Inventory.push_back(item3);

				worldState.Rooms.push_back(room);
			}
		}

		void GetInput(PlayerState & playerState, const WorldState & worldState)
		{
			playerState.WantsToExit = false;
			playerState.WantsDescription = false;
			playerState.WantsInventoryListed = false;
			playerState.WantsToGet = false;

			printf("다음 행동을 입력하세요.\n");
			printf("> ");
			ConsoleTextCommand command = ParseCommand();

			if (command.commandType == CommandTypeQuit)
			{
				playerState.WantsToExit = true;
			}
			else if (command.commandType == CommandTypeNorth)
			{
				playerState.NewPosition.Y = playerState.CurrentPosition.Y - 1;
			}
			else if (command.commandType == CommandTypeSouth)
			{
				playerState.NewPosition.Y = playerState.CurrentPosition.Y + 1;
			}
			else if (command.commandType == CommandTypeWest)
			{
				playerState.NewPosition.X = playerState.CurrentPosition.X - 1;
			}
			else if (command.commandType == CommandTypeEast)
			{
				playerState.NewPosition.X = playerState.CurrentPosition.X + 1;
			}
			else if (command.commandType == CommandTypeInfo)
			{
				playerState.WantsDescription = true;
			}
			else if (command.commandType == CommandTypeInventory)
			{
				playerState.WantsInventoryListed = true;
			}
			else if (command.commandType == CommandTypeGet)
			{
				playerState.WantsToGet = true;

			}
			else if (command.commandType == CommandTypeHelp)
			{
				printf("명령어 목록: look, quit, inventory, get, north, south, west, east\n");
				printf("Key:\n");
				printf("  @ - 플레이어\n");
				printf("  A - Altar (Next Patch!)\n");
				printf("  B, C, S, K - 아이템\n");
				printf("  . - 바닥\n");
				printf("  #, &, |, = - 벽\n");
				printf("  L - 문 (잠김)\n");
			}

			if (command.commandType == CommandTypeNone)
			{
				std::cout << "알 수 없는 명령입니다." << std::endl;
			}
			std::cout << std::endl;

		}

		void RenderGame(const PlayerState & playerState, const WorldState & worldState)
		{
			if (playerState.WantsDescription)
			{
				const MapData& currRoom = worldState.Rooms[playerState.CurrentRoomIndex];
				printf("================================================\n");
				printf("위치: %s\n", currRoom.Name.c_str());
				printf("%s\n\n", currRoom.Description.c_str());

				std::string mapString = "";
				unsigned int currentSpace = 0;
				while (currentSpace < currRoom.RoomMap.size())
				{
					char characterToDisplay = currRoom.RoomMap[currentSpace];

					//Inventory Rendering Code
					for (unsigned int i = 0; i < currRoom.Inventory.size(); i++)
					{
						const ItemData& currItem = currRoom.Inventory[i];
						if (currentSpace == PositionToIndex(currItem.ItemPosition, currRoom.RoomMapWidth))
						{
							characterToDisplay = GetItemIcon(currItem.Type);
						}
					}

					//Locked Door Rendering Code
					for (unsigned int i = 0; i < currRoom.LockedDoor.size(); i++)
					{
						const LockedDoorData& currDoor = currRoom.LockedDoor[i];
						if (currentSpace == PositionToIndex(currDoor.DoorPosition, currRoom.RoomMapWidth))
						{
							characterToDisplay = 'L';
						}
					}


					if (currentSpace == PositionToIndex(playerState.CurrentPosition, currRoom.RoomMapWidth))
					{
						characterToDisplay = '@';
					}

					mapString += characterToDisplay;

					if (currentSpace % currRoom.RoomMapWidth == (currRoom.RoomMapWidth - 1))
					{
						mapString += '\n';
					}

					currentSpace++;
				}
				printf("%s\n", mapString.c_str());

				printf("\n");
			}
			else if (playerState.WantsInventoryListed)
			{
				printf("================================================\n");
				printf("인벤토리:\n");

				if (playerState.Inventory.size() == 0)
				{
					printf("가지고 있는 아이템이 없습니다...\n");
				}
				else
				{
					for (unsigned int i = 0; i < playerState.Inventory.size(); i++)
					{
						const ItemData& currItem = playerState.Inventory[i];
						printf("%s (x%d)\n", GetItemName(currItem.Type).c_str(), currItem.Quantity);
					}
				}



				printf("\n");
			}
		}

		void UpdateGame(PlayerState & playerState, WorldState & worldState)
		{
			MapData& currRoom = worldState.Rooms[playerState.CurrentRoomIndex];

			if (playerState.NewPosition != playerState.CurrentPosition)
			{

				TryToUnlockDoors(playerState, currRoom);

				if (IsSpaceOutsideMap(playerState.NewPosition, currRoom))
				{
					int newRoomIndex = 0;

					int playerExitType = 0;
					Position targetRoomPosition = currRoom.MapPosition;
					if (playerState.NewPosition.X < 0)
					{
						//Exited West
						targetRoomPosition.X--;
						playerExitType = 1;
					}
					else if (playerState.NewPosition.X >= (int)currRoom.RoomMapWidth)
					{
						//Exited East
						targetRoomPosition.X++;
						playerExitType = 2;
					}
					else if (playerState.NewPosition.Y < 0)
					{
						//Exited North
						targetRoomPosition.Y--;
						playerExitType = 3;
					}
					else if (playerState.NewPosition.Y >= (int)(currRoom.RoomMap.size() / currRoom.RoomMapWidth))
					{
						//Exited South
						targetRoomPosition.Y++;
						playerExitType = 4;
					}

					bool foundNewRoom = false;
					for (unsigned int i = 0; i < worldState.Rooms.size(); ++i)
					{
						if (worldState.Rooms[i].MapPosition == targetRoomPosition)
						{
							foundNewRoom = true;
							newRoomIndex = i;
							break;
						}
					}

					if (foundNewRoom)
					{
						system("cls");
						playerState.CurrentRoomIndex = newRoomIndex;
						playerState.WantsDescription = true;

						switch (playerExitType)
						{
						case 1:
							playerState.CurrentPosition.X = worldState.Rooms[playerState.CurrentRoomIndex].RoomMapWidth - 1;
							break;
						case 2:
							playerState.CurrentPosition.X = 0;
							break;
						case 3:
							playerState.CurrentPosition.Y = (worldState.Rooms[playerState.CurrentRoomIndex].RoomMap.size() / worldState.Rooms[playerState.CurrentRoomIndex].RoomMapWidth) - 1;
							break;
						case 4:
							playerState.CurrentPosition.Y = 0;
							break;
						default:
							break;
						}
					}
					else
					{
						printf("할 수 있는 것이 아무것도 없습니다...\n");
						playerState.NewPosition = playerState.CurrentPosition;
					}
				}
				else if (IsSpaceOpenForMovement(playerState.NewPosition, currRoom))
				{
					playerState.CurrentPosition = playerState.NewPosition;
					playerState.WantsDescription = true;
				}
				else
				{
					printf("갈 수 없는 길입니다! 저주!\n");
					playerState.NewPosition = playerState.CurrentPosition;
				}
			}
			if (playerState.WantsToGet)
			{
				for (unsigned int i = 0; i < currRoom.Inventory.size(); i++)
				{
					const ItemData& currItem = currRoom.Inventory[i];
					if (currItem.ItemPosition == playerState.CurrentPosition)
					{
						printf("You got %s\n", GetItemName(currItem.Type).c_str());

						bool foundItemInPlayerInventory = false;
						for (unsigned int z = 0; z < playerState.Inventory.size(); z++)
						{
							ItemData& currPlayerItem = playerState.Inventory[z];
							if (currPlayerItem.Type == currItem.Type)
							{
								currPlayerItem.Quantity += currItem.Quantity;
								foundItemInPlayerInventory = true;
							}
						}

						if (!foundItemInPlayerInventory)
						{
							playerState.Inventory.push_back(currItem);
						}

						currRoom.Inventory.erase(currRoom.Inventory.begin() + i);
						break;
					}

				}
			}
		}

		void CleanupGame(PlayerState & playerState, WorldState & worldState)
		{
			worldState.Rooms.clear();
		}
		void TryToUnlockDoors(PlayerState & playerState, MapData & currRoom)
		{
			for (unsigned int i = 0; i < currRoom.LockedDoor.size(); i++)
			{
				const LockedDoorData& currDoor = currRoom.LockedDoor[i];
				if (currDoor.DoorPosition == playerState.NewPosition)
				{
					for (unsigned int j = 0; j < playerState.Inventory.size(); j++)
					{
						ItemData& currItem = playerState.Inventory[j];
						if (currItem.Type == ItemType_KEY)
						{
							//Destroy the door
							currRoom.LockedDoor.erase(currRoom.LockedDoor.begin() + i);

							//Remove a key
							currItem.Quantity--;
							if (currItem.Quantity <= 0)
							{
								playerState.Inventory.erase(playerState.Inventory.begin() + j);
							}

							break;
						}
					}
				}
			}
		}


		int PositionToIndex(const Position & position, int roomWidth)
		{
			return position.Y * roomWidth + position.X;
		}

		bool IsSpaceOutsideMap(const Position & position, const MapData & currRoom)
		{
			return position.Y < 0 ||
				position.X < 0 ||
				position.X >= (int)currRoom.RoomMapWidth ||
				position.Y >= (int)(currRoom.RoomMap.size() / currRoom.RoomMapWidth);
		}

		bool IsSpaceOpenForMovement(const Position & position, const MapData & currRoom)
		{
			for (unsigned int i = 0; i < currRoom.LockedDoor.size(); i++)
			{
				const LockedDoorData& currDoor = currRoom.LockedDoor[i];
				if (position == currDoor.DoorPosition)
				{
					return false;
				}
			}
			int spaceIndex = PositionToIndex(position, currRoom.RoomMapWidth);
			char currentSpace = currRoom.RoomMap[spaceIndex];

			/*
			if(currentSpace == '.')
			{
				return true;
			}
			else
			{
				return false;
			}
			*/
			return currentSpace == '.';
		}
		char GetItemIcon(ItemType itemType)
		{
			switch (itemType)
			{
			case TextConsole::ItemType_BOOK:
				return 'B';
				break;
			case TextConsole::ItemType_COIN:
				return 'C';
				break;
			case TextConsole::ItemType_SWORD:
				return 'S';
				break;
			case TextConsole::ItemType_KEY:
				return 'K';
				break;
			default:
				break;
			}
			return 'i';
		}
		std::string GetItemName(ItemType itemType)
		{
			switch (itemType)
			{
			case TextConsole::ItemType_BOOK:
				return "상실의 서";
				break;
			case TextConsole::ItemType_COIN:
				return "부자의 금화";
				break;
			case TextConsole::ItemType_SWORD:
				return "학살자의 검";
				break;
			case TextConsole::ItemType_KEY:
				return "보스방 열쇠";
				break;
			default:
				break;
			}

			return "알려지지 않은 아이템";




	}
	//

	//
}
