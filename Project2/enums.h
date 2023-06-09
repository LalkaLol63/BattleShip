#pragma once

enum CellStatus { //стан клітинки поля
	empty, //пуста
	deck, //палуба
	kill, //undef
	undef, //невідома клітинка, використовується для "матриці маски"
	occupied //так звані "" навколо корабля, на які не можна розмістити палубу
};

enum Orientation {
	NORTH,
	SOUTH,
	EAST,
	WEST,
	TOTAL
};