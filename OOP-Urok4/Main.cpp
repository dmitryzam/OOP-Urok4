#include<iostream>

// Урок 4. Конструкторы копирования и операторы класса

class Integer {
public:
	Integer():data_(0){}
	Integer(int num):data_(num){}

	// Перегрузка операторов:
	// 1. :
	friend Integer operator + (Integer A, Integer B) {
		Integer result;
		result.data_ = A.data_ + B.data_;
		return result;
		//return Integer(this->data_ + obj.data_); - можно также вызвать конструктор, как предыдущие две строки
	}

	friend std::ostream& operator<<(std::ostream& out, const Integer& obj);	// дружественная ф-ия для возможности работы с приватным полем

	int GetNum() {	// - метод для доступа к data_
		return data_;
	}
	// Оператор перегружен как дружественная функция:
	Integer& operator=(const Integer& other) {	// - метод класса
		this->data_ = other.data_;
		return *this;
	}

private:
	int data_;
	//========
	//bool sign_;
	//unsigned long long units_;
	// такая реализация полей лучше подойдет для
	// математически достоверных целых чисел
};

std::ostream& operator<<(std::ostream& out, const Integer& obj) {	// - работаем с <<
	//obj.data_;
	return out << obj.data_;
}
// перегрузка оператора как независимой функции:
Integer operator - (Integer a, Integer b) {	// - оператор вне класса
	return a.GetNum() - b.GetNum();
}
// перегрузка оператора как независимой функции:
Integer operator * (Integer a, Integer b) {	// - оператор вне класса
	return a.GetNum() * b.GetNum();
}

//int operator+(int a, float b); // - ошибка, потомучто в аргументах должен быть хотя бы один оператор

int main() {
	setlocale(LC_ALL, "RU");
	Integer a{ 5 };
	Integer b{ 5 };
	
	//std::cout << 'q' << 3 << "qwerty" << 5 + 9;
	std::cout << a + b << '\n';
	std::cout << "---------\n";
	std::cout << operator+(a, b) << '\n'; // - можно также как предыдущая строка
	std::cout << a - b << '\n';
	std::cout << a * b << '\n';
	//=========================
	std::cout << a + 5 << '\n';
	std::cout << a - 5 << '\n';
	std::cout << a * 3 << '\n';
	//=========================
	std::cout << 4 + b << '\n';
	std::cout << 7 - b << '\n';
	std::cout << 1 * b << '\n';

	Integer c;
	c = a + b;
	std::cout << c << '\n';

	return 0;
}

/*
	Операторы можно перегружать только для классов.
	Для встроенных типов данных операторов не перегружают.

	Оператор не может менять своего поведения в ходе перегрузки.

	Ряд операторов запрещено перегружать:
	 - точку ".";
	 - тернарный оператор "? :";
	 - унарный амперсанд "&";
	 - операторы new и delete;
	 - четвероточие "::";
	 - стрелку "->".
	 extream Programing*


*/