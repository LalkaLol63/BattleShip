#pragma once

enum CellStatus { //���� ������� ����
	empty, //�����
	deck, //������
	kill, //undef
	undef, //������� �������, ��������������� ��� "������� �����"
	occupied //��� ���� "" ������� �������, �� �� �� ����� ��������� ������
};

enum Orientation {
	NORTH,
	SOUTH,
	EAST,
	WEST,
	TOTAL
};