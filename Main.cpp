#include <iostream>

#include <iostream>
#include <string>
#include <fstream>
#include <atlsecurity.h>

#include "websocketpp_websocket.h"

#include <curl/curl.h>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#include "md5.h"
#include "Misc.h"
#include <nlohmann\json.hpp>

int main()
{
	std::string Auth_key;

	CheckAdmin();
	SetConsoleTitle(_T("Nulled.to | C++ Loader | Developed by Corgi"));
	Cursor(false);
	Logo();

	std::cout << "\n  [";
	std::cout << "+";
	std::cout << "] ";
	std::cout << "Auth key: ";
	std::getline(std::cin, Auth_key);

	std::string Url = "https://www.nulled.to/misc.php?action=validateKey&authKey=" + md5(Auth_key);

	curlpp::Cleanup clean;
	curlpp::Easy request;
	request.setOpt(new curlpp::options::Url(Url));
	request.setOpt(new curlpp::options::CustomRequest{ "POST" });
	std::list<std::string> header;
	header.push_back("user-agent:Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.169 Safari/537.36");
	request.setOpt(new curlpp::options::HttpHeader(header));
	std::stringstream res;
	request.setOpt(new curlpp::options::WriteStream(&res));
	request.perform();

	nlohmann::json response = nlohmann::json::parse(res.str());

	if (response["status"] == "success")
	{
		SetConsoleTitle(_T("Nulled.to | C++ Loader | Developed by Corgi | Status: Authenticated"));
		ClearConsole();

		Logo();
		std::cout << "\n  Successfully Authenticated." << std::endl;
		Sleep(-1);
	}
	else
	{
		SetConsoleTitle(_T("Nulled.to | C++ Loader | Developed by Corgi | Status: Error"));
		ClearConsole();

		Logo();
		std::cout << "\n  Error." << std::endl;
		Sleep(-1);
	}
}