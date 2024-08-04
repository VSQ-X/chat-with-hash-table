#include "chat.h"
auto main() -> int {
	std::cout << "Welcome in chat!\n";
	Chat chat;
	chat.reg("abc","123");
	chat.reg("aaa", "123");
	chat.reg("aaa", "128");
	chat.reg("aaa", "1282");
	chat.reg("aaa", "1283");
	chat.reg("aaa", "1284");
	chat.reg("aaa", "1285");
	chat.reg("aaa", "1286");
	chat.reg("bot", "111");
	std::string log;
	std::string pass;
	std::cout << "Input login\n";
	std::cin >> log;
	std::cout << "Input password\n";
	std::cin >> pass;
	chat.login(log, pass);
	return 0;
}