#include <iostream>
#include <windows.h>						   //���������� windows.h ��������� ����������������� � �� � �������� ������������ ��������� �������
#include <exception>

int function(std::string str, int forbidden_length) {
	int len = str.length();

	if (len == forbidden_length)
		throw std::runtime_error("bad_length");
	return len;
}

int main() {
	SetConsoleCP(1251);							//������������� ��������� ����� �� ������� � �� ��������� ����
	SetConsoleOutputCP(1251);					//������������� ��������� ������ �� �������
	int forbidden_len;
	std::string str;
	std::cout << "������� ��������� �����: ";
	std::cin >> forbidden_len;

	try
	{
		do {
			std::cout << "������� �����: ";
			std::cin >> str;
			std::cout << "����� ����� " << "''" << str << "''" << " ����� " << function(str, forbidden_len) << std::endl;
		} while (str.length() != forbidden_len);		
	}

	catch (const std::exception& err)
	{
		std::cout << "�� ����� ����� ��������� �����! �� ��������" << "\n" << err.what() << std::endl;
	}
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