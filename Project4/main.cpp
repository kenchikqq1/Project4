#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <iomanip>

#if defined(max)
#undef max
#endif

/*
	���� ��������
	�������� �������
	������
	�����
	��������/�������
	���������� ������
	������������ �����
	���
	������� ����
*/

// ������� ������
bool isAdmin = false;
int userCount = 2;
std::string* loginArr = new std::string[userCount]{ "admin", "user" };
std::string* passwordArr = new std::string[userCount]{ "admin", "user" };
//-----------------------------------------------------------------------



// �����
int size = 10;
int* idArr = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
double* priceArr = new double[size];


//�������
void Start();
bool Login();

void ShopAdminMenu();
void ShopUserMenu();

void CreateStaticStorage();

void ShowStorage();
void RefilStorage();
void WriteOfFromStorage();
void ChangePrice();
void ChangeSraff();
void AddEmployer();
void EmployeeEdit();
void DeleteEmployee();
void ChangeStorage();


bool IsNumber(std::string string);

template<typename ArrType>
void SetArr(ArrType staticArr, ArrType dynamicArr, int size);

template<typename ArrType>
void PrintArr(ArrType dynamicArr, int size);


//===================
int main()
{
	Start();
	delete[]loginArr;
	delete[]passwordArr;

	delete[]idArr;
	delete[]nameArr;
	delete[]countArr;
	delete[]priceArr;

	return 0;
}
//===================


void Start()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "\n\n\t\t\t��������\n\n\n";
	if (Login() == true)
	{
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max());
		if (isAdmin == true)
		{
			std::string choose;
			do
			{
				std::cout
					<< "������������ ������� ��� ������� �����?\n"
					<< "1. ������� ����\n"
					<< "2. ������� �����\n\n ?> ";

				std::getline(std::cin, choose, '\n');

				system("cls");
			} while (choose.size() > 1 || choose[0] < 49 || choose[0] > 50);

			if (choose == "1")
			{
				CreateStaticStorage();
			}
			else
			{
				// �������� ������������� ������
			}

			ShopAdminMenu();
		}
		else
		{
			CreateStaticStorage();
			ShopUserMenu();
		}
	}
}

bool Login()
{
	while (true)
	{
		std::string login, pass;
		std::cout << "������� �����: ";
		std::getline(std::cin, login, '\n');
		std::cout << "������� ������: ";
		std::getline(std::cin, pass, '\n');

		isAdmin = false;
		for (int i = 0; i < userCount; i++)// ��� ������) �����)))
		{
			if (login == loginArr[i] && pass == passwordArr[i]) {

				system("cls");
				std::cout << "����� ���������� " << loginArr[i] << '\n';

				if (i == 0)
				{
					isAdmin = true;
				}

				return true;
			}

		}
		system("cls");
		std::cout << "������� ����� ����� ��� ������.\n";

	}


}


void ShopAdminMenu()
{
	std::string choose{};

	while (true)
	{
		do
		{
			system("pause");
			system("cls");

			std::cout
				<< "1. ������ �������\n"
				<< "2. �������� �����\n"
				<< "3. ��������� �����\n"
				<< "4. ������� �� ������\n"
				<< "5. �������� ����\n"
				<< "6. �������� �����\n"
				<< "7. �������� ��������\n"
				<< "8. ����� � �������\n\n"
				<< "0. ������� �����\n\n\n ?> ";

			std::getline(std::cin, choose, '\n');

			system("cls");
		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56);

		if (choose == "1")
		{

		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{
			RefilStorage();
		}
		else if (choose == "4")
		{
			WriteOfFromStorage();
		}
		else if (choose == "5")
		{
			ChangePrice();
		}
		else if (choose == "6")
		{
			ChangeStorage();
		}
		else if (choose == "7")
		{
			ChangeSraff();
		}
		else if (choose == "8")
		{

		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			system("cls");
			std::cout << "\n\n\n\t\t\tAdminMenuError\n\n\n";
		}

	}
}

void ShopUserMenu()
{
	std::string choose{};

	while (true)
	{
		do
		{
			system("pause");
			system("cls");

			std::cout
				<< "1. ������ �������\n"
				<< "2. ������� �����\n"
				<< "3. ��������� �����\n"
				<< "4. �������� �����\n"
				<< "5. ����� � �������\n\n"
				<< "0. ������� �����\n\n\n ?> ";

			std::getline(std::cin, choose, '\n');

			system("cls");
		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 53);

		if (choose == "1")
		{

		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{
			RefilStorage();
		}
		else if (choose == "4")
		{

		}
		else if (choose == "5")
		{

		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			system("cls");
			std::cout << "\n\n\n\t\t\tUserMenuError\n\n\n";
		}

	}
}


void CreateStaticStorage()
{
	const int staticSize = 10;
	int idStaticArr[staticSize]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	std::string nameStaticArr[staticSize]{
		"��������� ����","��������� ����","�������� ����","��������� ����","���������� ����",
		"����������� ����","�������� ����","��������� ����","������� ����","��������� ����"
	};

	int countStaticArr[staticSize]{ 20, 10, 50, 40, 35, 40, 25, 10, 15, 25 };

	double priceStaticArr[staticSize]{ 3649.0, 6689.0, 3565.0, 1137.0, 3995.0, 9990.0, 1990.0, 990.0, 888.0, 2174.0 };

	SetArr(idStaticArr, idArr, staticSize);
	SetArr(nameStaticArr, nameArr, staticSize);
	SetArr(countStaticArr, countArr, staticSize);
	SetArr(priceStaticArr, priceArr, staticSize);
}


void ShowStorage()
{
	std::cout << "ID\t��������\t\t����\t���-��\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << idArr[i] << '\t' << std::left << std::setw(30) << nameArr[i] << '\t' << priceArr[i] << '\t' << countArr[i] << '\n';
	}
	std::cout << "\n\n\n\n";
}

void RefilStorage()
{
	std::string idStr, addStr;
	int id{}, add{};


	while (true)
	{
		std::cout << "������� ID ������\n0) �����\n\n ?> ";
		std::getline(std::cin, idStr, '\n');
		if (idStr == "0")
		{
			break;
		}
		else if (IsNumber(idStr))
		{
			id = std::stoi(idStr);
			std::cout << id << "\t" << std::left << std::setw(30) << nameArr[id - 1] << '\t' << countArr[id - 1] << '\n';

			while (true)
			{
				std::cout << "������� ���������� ������ �� ����������: ";
				std::getline(std::cin, addStr, '\n');
				if (IsNumber(addStr))
				{
					add = std::stoi(addStr);
					if (add >= 0 && add < 1000)
					{
						countArr[id - 1] += add;
						std::cout << "\n\n����� ������� ��������\n\n";
						break;
					}
					else
					{
						std::cout << "\n\n������� ������ �����\n\n";
					}
				}
				else
				{
					std::cout << "\n\n������ �����\n\n";
				}
			}
			break;
		}
		else
		{
			std::cout << "\n\n������ �����\n\n";
		}
	}
}

void WriteOfFromStorage()
{
	std::string idStr, delStr;
	int id{}, del{};


	while (true)
	{
		std::cout << "������� ID ������\n0) �����\n\n ?> ";
		std::getline(std::cin, idStr, '\n');
		if (idStr == "0")
		{
			break;
		}
		else if (IsNumber(idStr))
		{
			id = std::stoi(idStr);
			std::cout << id << "\t" << std::left << std::setw(30) << nameArr[id - 1] << '\t' << countArr[id - 1] << '\n';

			while (true)
			{
				std::cout << "������� ���������� ������ ��������: ";
				std::getline(std::cin, delStr, '\n');
				if (IsNumber(delStr))
				{
					del = std::stoi(delStr);
					if (del >= 0 && del <= countArr[id - 1])
					{
						countArr[id - 1] -= del;
						std::cout << "\n\n����� ������� ������\n\n";
						break;
					}
					else
					{
						std::cout << "\n\n������� ������ �����\n\n";
					}
				}
				else
				{
					std::cout << "\n\n������ �����\n\n";
				}
			}
			break;
		}
		else
		{
			std::cout << "\n\n������ �����\n\n";
		}
	}
}

void ChangePrice()
{
	std::string idStr, newPriceStr;
	int id{}, newPrice{};


	while (true)
	{
		std::cout << "������� ID ������\n0) �����\n\n ?> ";
		std::getline(std::cin, idStr, '\n');
		if (idStr == "0")
		{
			break;
		}
		else if (IsNumber(idStr))
		{
			id = std::stoi(idStr);
			std::cout << id << "\t" << std::left << std::setw(30) << nameArr[id - 1] << '\t' << priceArr[id - 1] << '\n';

			while (true)
			{
				std::cout << "������� ����� ����: ";
				std::getline(std::cin, newPriceStr, '\n');
				if (IsNumber(newPriceStr))
				{
					newPrice = std::stoi(newPriceStr);
					if (newPrice >= 0 && newPrice <= 10000000)
					{
						priceArr[id - 1] = newPrice;
						std::cout << "\n\n����� ���� �������\n\n";
						break;
					}
					else
					{
						std::cout << "\n\n������� ������ �����\n\n";
					}
				}
				else
				{
					std::cout << "\n\n������ �����\n\n";
				}
			}
			break;
		}
		else
		{
			std::cout << "\n\n������ �����\n\n";
		}
	}
}

void ChangeSraff()
{
	std::string choose;
	std::cout << "��������� ��������� ��������\n";
	for (int i = 0; i < userCount; i++)
	{
		std::cout << i + 1 << "\t" << std::left << std::setw(10) << loginArr[i] << "\t" << passwordArr[i] << '\n';
	}

	do
	{
		std::cout << '\n'
			<< "1) �������� ������ ����������\n"
			<< "2) �������� ����� ��� ������\n"
			<< "3) ������� �������� ����������\n\n"
			<< "0) �����\n\n\n ?> ";
		std::getline(std::cin, choose, '\n');
		system("cls");
	} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 51);
	if (choose == "1")
	{
		AddEmployer();
	}
	else if (choose == "2")
	{
		EmployeeEdit();
	}
	else if (choose == "3")
	{
		DeleteEmployee();
	}
	else if (choose == "0")
	{

	}
	else
	{
		std::cout << "ChangeStaffError";
	}
}

void AddEmployer()
{
	std::string* tempLogin = new std::string[userCount];
	std::string* tempPass = new std::string[userCount];
	for (int i = 0; i < userCount; i++)
	{
		tempLogin[i] = loginArr[i];
		tempPass[i] = passwordArr[i];
	}

	//std::swap(loginArr, tempLogin);

	delete[]loginArr;
	delete[]passwordArr;
	userCount++;
	loginArr = new std::string[userCount];
	passwordArr = new std::string[userCount];
	for (int i = 0; i < userCount - 1; i++)
	{
		loginArr[i] = tempLogin[i];
		passwordArr[i] = tempPass[i];
	}

	std::string newLogin, newPass;
	std::cout << "������� ����� ������ ����������: ";
	std::getline(std::cin, newLogin, '\n');
	std::cout << "������� ������ ������ ����������: ";
	std::getline(std::cin, newPass, '\n');

	loginArr[userCount - 1] = newLogin;
	passwordArr[userCount - 1] = newPass;
	delete[]tempLogin;
	delete[]tempPass;

	//test
	for (int i = 0; i < userCount; i++)
	{
		std::cout << i + 1 << "\t" << std::left << std::setw(10) << loginArr[i] << "\t" << passwordArr[i] << '\n';
	}

}

void EmployeeEdit()
{
	std::string chooseId, newLogin, newPass;
	int empId{};

	while (true)
	{
		for (int i = 0; i < userCount; i++)
		{
			std::cout << i + 1 << "\t" << std::left << std::setw(10) << loginArr[i] << "\t" << passwordArr[i] << '\n';
		}
		std::cout << "\n�������� ID ������������ ��� ���������\n\n0) �����\n\n\n ?> ";
		std::getline(std::cin, chooseId, '\n');
		if (chooseId == "0")
		{
			break;
		}
		else if (IsNumber(chooseId))
		{
			empId = std::stoi(chooseId);
			for (int i = 0; i < userCount; i++)
			{
				if (i == empId - 1)
				{
					std::cout << "������ ����� �����: ";
					std::getline(std::cin, newLogin, '\n');
					std::cout << "������ ����� ������: ";
					std::getline(std::cin, newPass, '\n');

					loginArr[i] = newLogin;
					passwordArr[i] = newPass;
					system("cls");
					break;
				}
			}
		}
		else
		{
			std::cout << "\n\n������ �����\n\n";
		}
	}
}

void DeleteEmployee()
{
	std::string chooseId;
	int empId{};
	while (true)
	{

		for (int i = 0; i < userCount; i++)
		{
			std::cout << i + 1 << "\t" << std::left << std::setw(10) << loginArr[i] << "\t" << passwordArr[i] << '\n';
		}

		std::cout << "\n�������� �������� ID ������������ ��� ��������\n\n0) �����\n\n\n ?> ";
		std::getline(std::cin, chooseId, '\n');
		if (chooseId == "0")
		{
			break;
		}
		else if (IsNumber(chooseId))
		{

			empId = std::stoi(chooseId);
			std::string* tempLogin = new std::string[userCount];
			std::string* tempPass = new std::string[userCount];
			for (int i = 0; i < userCount; i++)
			{
				tempLogin[i] = loginArr[i];
				tempPass[i] = passwordArr[i];
			}
			delete[]loginArr;
			delete[]passwordArr;
			userCount--;
			loginArr = new std::string[userCount];
			passwordArr = new std::string[userCount];

			for (int i = 0, j = 0; i < userCount, j < userCount; i++, j++)
			{
				if (i == empId - 1)
				{
					i++;
					loginArr[j] = tempLogin[i];
					passwordArr[j] = tempPass[i];
				}
				else
				{
					loginArr[j] = tempLogin[i];
					passwordArr[j] = tempPass[i];
				}
			}
			break;
		}
		else
		{
			std::cout << "\n\n������ �����\n\n";
		}
	}
}

void ChangeStorage()
{

}


bool IsNumber(std::string string)//�������� �� ����� �� � ������
{
	for (int i = 0; i < string.size(); i++)
	{
		if (!std::isdigit(string[i]))
		{
			return false;
		}
	}
	return true;
}

template<typename ArrType>
void SetArr(ArrType staticArr, ArrType dynamicArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}

template<typename ArrType>
void PrintArr(ArrType dynamicArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << dynamicArr[i] << " ";
	}
	std::cout << "\n";
}
