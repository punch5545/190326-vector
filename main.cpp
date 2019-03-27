#include <iostream>
#include <conio.h>

struct Pos {
	//연산자 재정의
	const bool operator==(const Pos& rhs) const {
		bool bCheck = true;
		bCheck &= x == rhs.x;
		bCheck &= y == rhs.y;
		return bCheck;
	}
	const Pos operator+(const Pos& rhs) const {
		int xTemp = x + rhs.x;
		int yTemp = y + rhs.y;
		return { xTemp, yTemp };
	}
	const Pos operator-(const Pos& rhs) const {
		int xTemp, yTemp;
		xTemp = x - rhs.x;
		yTemp = y - rhs.y;
		return { xTemp, yTemp };
	}
	const Pos operator*(const int scalar) const {
		int xTemp, yTemp;
		xTemp = x * scalar;
		yTemp = y * scalar;
		return { xTemp, yTemp };
	}
	const Pos operator/(const int scalar) const {
	    int xTemp, yTemp;
		xTemp = x / scalar;
		yTemp = y / scalar;
		return { xTemp, yTemp };
	}
	const bool operator!=(const Pos& rhs) const {
		bool bCheck = true;
		bCheck &= rhs.x != x;
		bCheck &= rhs.y != y;
		return bCheck;
	}

	int x;
	int y;
};

void func()
{
	Pos pos;
	Pos pos2;
	Pos pos3;
	char input;
	std::cout << "벡터의 x 입력 : ";
	std::cin >> pos.x;
	std::cout << "벡터의 y 입력 : ";
	std::cin >> pos.y;
	std::cout << "어떤 연산?" << std::endl << "a. 벡터와 벡터 연산" << std::endl << "b. 벡터 스칼라 연산" << std::endl << "c. 두 벡터는 같은가?" << std::endl;
	std::cin >> input;

	switch (input) {
	case 'a':
		std::cout << "벡터의 x 입력 : ";
		std::cin >> pos2.x;
		std::cout << "벡터의 y 입력 : ";
		std::cin >> pos2.y;
		pos3 = pos + pos2;
		std::cout << std::endl << "두 벡터의 합 : x : " << pos3.x << ", y : " << pos3.y << std::endl;
		pos3 = pos - pos2;
		std::cout << "두 벡터의 차 : x : " << pos3.x << ", y : " << pos3.y << std::endl;

		break;
	case 'b':
		int scalar;
		std::cout << "스칼라 a 입력 : ";
		std::cin >> scalar;
		pos3 = pos * scalar;
		std::cout << std::endl << "벡터와 스칼라 " << scalar << "의 곱" << std::endl << "x : " << pos3.x << ", y : " << pos3.y << std::endl;
		pos3 = pos / scalar;
		std::cout << "벡터를 스칼라 " << scalar << "로 나눈 값 " << std::endl << "x : " << pos3.x << ", y : " << pos3.y << std::endl;
		break;
	case 'c':
		std::cout << "벡터의 x 입력 : ";
		std::cin >> pos2.x;
		std::cout << "벡터의 y 입력 : ";
		std::cin >> pos2.y;
		bool tof = pos == pos2;
		std::cout << std::endl << "두 벡터는 같은가? :" << tof << std::endl;
		bool tof2 = pos != pos2;
		std::cout << "두 벡터는 다른가? :" << tof2 << std::endl;
		break;
	}
}

int main()
{
	while (true) {
		func();
		std::cout << std::endl << std::endl;
	}

	return 0;
}
