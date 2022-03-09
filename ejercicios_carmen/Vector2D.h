#ifndef VECTOR2D_H
#define VECTOR2D_H

template <class T>
class Vector2D {

public:
	T x;
	T y;

	Vector2D(T _componentX, T _componentY) :
		x(_componentX), y(_componentY) {}

	Vector2D() {}

#pragma region OPERATORS
	friend Vector2D<T> operator*(float scalar, Vector2D<T> vector) {
		Vector2D<T> result;

		result.x = vector.x * scalar;
		result.y = vector.y * scalar;

		return result;
	}

	friend Vector2D<T> operator+(Vector2D<T> vector1, Vector2D<T> vector2) {

		Vector2D<T> result;

		result.x = vector1.x + vector2.x;
		result.y = vector1.y + vector2.y;

		return result;
	}

	friend Vector2D<T> operator-(Vector2D<T> vector1, Vector2D<T> vector2) {

		Vector2D<T> result;

		result.x = vector1.x - vector2.x;
		result.y = vector1.y - vector2.y;

		return result;
	}

	friend bool operator==(Vector2D<T> vector_1, Vector2D<T> vector_2) {

		bool _compareX = vector_1.x == vector_2.x;
		bool _compareY = vector_1.y == vector_2.y;
		if (_compareX && _compareY) {
			return true;
		}
		else {
			return false;
		}
	}

	friend bool operator!=(Vector2D<T> vector_1, Vector2D<T> vector_2) {

		bool _compare = vector_1 == vector_2;
		if (_compare) {
			return false;
		}
		else {
			return true;
		}
	}

	friend float operator*(Vector2D<T> p_vector_1, Vector2D<T> p_vector_2) {

		return p_vector_1.x * p_vector_2.x + p_vector_1.y * p_vector_2.y;

	}

#pragma endregion

	float Module() {

		return sqrt(pow(x, 2) + pow(y, 2));

	}

	Vector2D<T> UnitaryVector() {

		Vector2D<T> unitaryVector;
		unitaryVector.x = x;
		unitaryVector.y = y;
		float module = unitaryVector.Module();
		unitaryVector.x = unitaryVector.x / module;
		unitaryVector.y = unitaryVector.y / module;

		return unitaryVector;

	}


	static Vector2D<T> GetUnitaryVector(Vector2D<T> p_vector) {

		return p_vector.UnitaryVector();

	}

	static float GetModule(Vector2D<T> p_vector) {
		return p_vector.Module();
	}

};

#endif // !VECTOR2D_H
