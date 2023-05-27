#include "core/trace.hpp"
#include "core/network.hpp"
#include "../auth.hpp"
#include "../skStr.h"

std::string tm_to_readable_time(tm ctx);
static std::time_t string_to_timet(std::string timestamp);
static std::tm timet_to_tm(time_t timestamp);
const std::string compilation_date = (std::string)skCrypt(__DATE__);
const std::string compilation_time = (std::string)skCrypt(__TIME__);

using namespace KeyAuth;

std::string name = skCrypt("").decrypt(); // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = skCrypt("").decrypt(); // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = skCrypt("").decrypt(); // app secret, the blurred text on licenses tab and other tabs
std::string version = skCrypt("1.0").decrypt(); // leave alone unless you've changed version on website
std::string url = skCrypt("https://keyauth.win/api/1.2/").decrypt(); // change if you're self-hosting



api KeyAuthApp(name, ownerid, secret, version, url);



int main()
{
	int choice;
	std::string consoleTitle = (std::string)skCrypt("Loader - Built at:  ") + compilation_date + " " + compilation_time;
	SetConsoleTitleA(consoleTitle.c_str());
	std::cout << skCrypt("\n\n Connecting..");
	KeyAuthApp.init();
	if (!KeyAuthApp.data.success)
	{
		std::cout << skCrypt("\n Status: ") << KeyAuthApp.data.message;
		Sleep(1500);
		exit(0);
	}

	int ttab = 0;
	std::cout << skCrypt("\n\n [1] Login\n [2] Register\n [3] Upgrade\n [4] License key only\n\n Choose option: ");
	int option;

	std::string username;
	std::string password;
	std::string key;

	std::cin >> option;
	switch (option)
	{
	case 1:
		std::cout << skCrypt("\n\n Enter username: ");
		std::cin >> username;
		std::cout << skCrypt("\n Enter password: ");
		std::cin >> password;
		KeyAuthApp.login(username, password);
		break;
	case 2:
		std::cout << skCrypt("\n\n Enter username: ");
		std::cin >> username;
		std::cout << skCrypt("\n Enter password: ");
		std::cin >> password;
		std::cout << skCrypt("\n Enter license: ");
		std::cin >> key;
		KeyAuthApp.regstr(username, password, key);
		break;
	case 3:
		std::cout << skCrypt("\n\n Enter username: ");
		std::cin >> username;
		std::cout << skCrypt("\n Enter license: ");
		std::cin >> key;
		KeyAuthApp.upgrade(username, key);
		break;
	case 4:
		std::cout << skCrypt("\n Enter license: ");
		std::cin >> key;
		KeyAuthApp.license(key);
		break;
	default:
		std::cout << skCrypt("\n\n Status: Failure: Invalid Selection");
		Sleep(3000);
		exit(0);
	}

	if (!KeyAuthApp.data.success)
	{
		std::cout << skCrypt("\n Status: ") << KeyAuthApp.data.message;
		Sleep(1500);
		exit(0);
	}
	if (KeyAuthApp.data.success)
	{
		while (true)
		{
			system("cls");

			std::cout << R"(
                                            
                                                            
                 *//                                          
             .*/****/.       ,***************                 
        *****************************************             
      ******(***************************************          
   .********%#***************************************         
   **************************************************.        
        ////**********************//******************        
                ////*************////*****************        
                   ////*******///////****************         
                       //*****///////*********************    
                          ***.          *********     ******* 
                        *****        ********             ****
                                                          ****
                                                      ,*****  
                             .*************************       

			)" << '\n';

			g_network = std::make_unique<network>();
			g_trace = std::make_unique<trace>();

			while (true)
			{
				g_trace->m_fivem_path = g_trace->set_folder("Select FiveM Folder which contains FiveM.exe");

				system("cls");

				if (!g_trace->m_fivem_path.empty())
				{
					std::cout << "  [Selected Folder]  " << g_trace->m_fivem_path << "\n" << std::endl;

					std::cout << "  [1]  :  " << "clean traces" << std::endl;
					std::cout << "  [2]  :  " << "enable network bypass" << std::endl;
					std::cout << "  [3]  :  " << "disable network bypass" << std::endl;
					std::cout << "  [4]  :  " << "reset fivem path" << std::endl;
					std::cout << "  [5]  :  " << "edit launch options" << std::endl;
					std::cin >> choice;

					switch (choice)
					{
					case 1:
					{
						g_trace->setup();
					}
					break;
					case 2:
					{
						g_network->setup();
					}
					break;
					case 3:
					{
						g_network->destroy();
					}
					break;
					case 4:
					{
						g_trace->set_launch_build();
					}
					break;
					case 5:
					{
						g_trace->destroy();
					}
					break;
					}
				}
				else
				{
					std::cout << "  [Error]  :  " << "select valid folder for FiveM" << "\n" << std::endl;
				}

				system("Pause");
			}

			system("Pause");
		}
	}





	

}
