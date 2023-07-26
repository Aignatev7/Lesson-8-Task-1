#include <iostream>
#include <windows.h>						   //���������� windows.h ��������� ����������������� � �� � �������� ������������ ��������� �������
#include <exception>

class exception : public std::domain_error { public: using domain_error::domain_error; };

class runtime_error : public exception {
public:
	
	explicit runtime_error(const char* message);
};

int function(std::string str, int forbidden_length) {
	int len = str.length();

	if (len == forbidden_length)
		throw std::exception();
	return len;
}

int main() {
	SetConsoleCP(1251);							//������������� ��������� ����� �� ������� � �� ��������� ����
	SetConsoleOutputCP(1251);					//������������� ��������� ������ �� �������
	int forbidden_len;
	std::string str;
	std::cout << "������� ��������� �����: ";
	std::cin >> forbidden_len;

	do {
		std::cout << "������� �����: ";
		std::cin >> str;

		try
		{
			std::cout << "����� ����� " << "''" << str << "''" << " ����� " << function(str, forbidden_len) << std::endl;
		}

		catch (const std::exception& err)
		{
			std::cout << "�� ����� ����� ��������� �����! �� ��������" << err.what() << std::endl;
		}

	} while (function(str, forbidden_len) != forbidden_len);
}




/*
������ 1. ������� ����������
� ���� ������� �� ���������� ��������� � ���������� ����������.

�������� ������� int function(std::string str, int forbidden_length).��� ������� ������ ���������� ����� ���������� ������, ���� ��� ����� �� ����� �������� ����������� ��������� forbidden_length.� ��������� ������ ��� ������ ����������� ���������� bad_length.

��� �������� ������� ����������� ������ � �������������.� ������ ������� ��������� �����, � ����� ���������� ���������������� ������ � �������� �� ����� �� ��� ���, ���� ������������ �� ����� ������ ��������� �����.����� ����� �������� ���, ��� �� ��� ������ ��������� �����, � ��������� ���������.

������ ������ ���������
�������
������� ��������� ����� : 5
������� ����� : ������
����� ����� "������" ����� 6
������� ����� : ���
����� ����� "���" ����� 3
������� ����� : �����
�� ����� ����� ��������� �����!�� ��������
���������
�� ������� ���� ������ �����.����������� ������� ������ ������ �������������� : )

��� ������������ ��� �������.
��� ���������� ����� ������ ����������� ����� ������ std::string � length.

��� �������� ���������� ����������� �������� ����� throw.

��� �������� ���������� ����������� �������� ����� try.

��� ��������� ���������� ����������� �������� ����� catch.
*/