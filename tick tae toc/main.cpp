#include <iostream>

template <typename T>
class singleton
{
private:
	T* singleton;
public:
	singleton();
	virtual ~singleton();
	GameManager" singleton;
		static T* Getsingleton()
	{
		if (nullptr == singleton)
		{

			singleton = new T;

		}
		return singleton;

	}

	static void Release()
	{

		delete singleton;
		singleton = nullptr;



	}

};


template<typename T>
T* singleton<T>::singleton = nullptr;

class GameManager : public singleton<GameManager>
{
private:


public:

	GameManager() {}
	~GameManager() {}

	void MainMenu()
	{


		std::cout << "메안 메뉴시작" << std::endl;


	}



};

int main(void)
{

	std::cout << "메인화면" << std::endl;
	GameManager gm;
	gm.MainMenu();


}