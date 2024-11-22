#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include "FuncionToBankProject.h"
#include<iomanip>
#include"ShowFunion.h"

using namespace std;
using namespace Screen;
using namespace BankFuncion;

namespace Login
{
	const string UserFileName = "User.txt";
	void _LoginPage();
	string ReadUserName()
	{
		string UserName;
		cout << "Enter Username ?";
		getline(cin, UserName);
		return UserName;
	}
	int ReadPassword()
	{
		int Password;
		cout << "\nEnter Password ?";
		
		cin >> Password;
		return Password;
	}
	bool IS_UserAndPass(string Username, int Password, string FileName)
	{
		vector<stUser>vUsers = LoadUsersDataFromFile_stUser(FileName);
		for (stUser& user : vUsers)
		{
			if (user.Username == Username && user.Password == Password)
				return true;
		}
		return false;
	}
	void _ReTry()
	{
		_LoginPage();
	}

	void _LoginPage()
	{
		string UserName = ReadUserName();
		int Password = ReadPassword();

		if (IS_UserAndPass(UserName, Password, UserFileName))
		{
			system("color 0f");
			system("cls");
			ElsePage();
			
		}
		else {
			system("color 04");
			cout << "\nWRong!\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			_ReTry();
		}
	}
};