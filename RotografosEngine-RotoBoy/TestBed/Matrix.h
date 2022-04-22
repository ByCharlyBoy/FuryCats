#pragma once
#include <vector>
#include <iostream>

namespace RotografosEngine /*MTChurritos*/ {
	template <int X, int Y>
	class Matrix
	{
	public:
		Matrix();
		Matrix(std::vector<float> vector);
		~Matrix();
		void Sum(Matrix rhs);
		void Mult(float scalar);
		void Mult(Matrix rhs);
		void SetComponent(int indX, int indY, float component);
		float GetComponent(int indX, int indY);
		int GetSize();
		int GetSizeX();
		int GetSizeY();
		void PrintMatrix();
	protected:
		int _IndexHelper(int x, int y);
		std::vector<float> _vectorContent;
		int _vectorContentSizeX = X, _vectorContentSizeY = Y;
	};


	template<int X, int Y>
	Matrix<X, Y>::Matrix()
	{
		_vectorContent.resize(_vectorContentSizeX * _vectorContentSizeY);
		for (int i = 0; i < (_vectorContentSizeX * _vectorContentSizeY); ++i)
			_vectorContent[i] = 0;
	}

	template<int X, int Y>
	Matrix<X, Y>::Matrix(std::vector<float> vector)
	{
		_vectorContent.resize(_vectorContentSizeX * _vectorContentSizeY);
		for (int i = 0; i < (_vectorContentSizeX * _vectorContentSizeY); ++i) {
			_vectorContent[i] = vector[i];
		}
	}

	template<int X, int Y>
	Matrix<X, Y>::~Matrix()
	{

	}

	template<int X, int Y>
	void Matrix<X, Y>::Sum(Matrix rhs)
	{
		if (rhs.GetSizeX() != this->GetSizeX() ||
			rhs.GetSizeY() != this->GetSizeY())
			return;
		for (int i = 0; i < this->GetSize(); ++i) {
			this->_vectorContent[i] += rhs._vectorContent[i];
		}
	}

	template<int X, int Y>
	void Matrix<X, Y>::Mult(float scalar)
	{
		for (int i = 0; i < this->GetSize(); ++i) {
			this->_vectorContent[i] *= scalar;
		}
	}

	template<int X, int Y>
	void Matrix<X, Y>::Mult(Matrix rhs)
	{
		if (rhs.GetSizeX() == this->GetSizeY()) {
			for (int i = 0; i < rhs.GetSizeX(); ++i) {
				for (int j = 0; j < this->GetSizeY(); ++j) {
					this->_vectorContent[_IndexHelper(i, j)] *= rhs._vectorContent[_IndexHelper(i, j)];
				}
			}
		}
	}

	template<int X, int Y>
	void Matrix<X, Y>::SetComponent(int indX, int indY, float component)
	{
		if (indX < _vectorContentSizeX && indY < _vectorContentSizeY)
			_vectorContent[_IndexHelper(indX, indY)] = component;
	}

	template<int X, int Y>
	float Matrix<X, Y>::GetComponent(int indX, int indY)
	{
		return _vectorContent[_IndexHelper(indX, indY)];
	}

	template<int X, int Y>
	int Matrix<X, Y>::GetSize()
	{
		return _vectorContent.size();
	}

	template<int X, int Y>
	int Matrix<X, Y>::GetSizeX()
	{
		return _vectorContentSizeX;
	}

	template<int X, int Y>
	int Matrix<X, Y>::GetSizeY()
	{
		return _vectorContentSizeY;
	}

	template<int X, int Y>
	void Matrix<X, Y>::PrintMatrix()
	{
		for (int i = 0; i < _vectorContentSizeX; ++i) {
			std::cout << "| ";
			for (int j = 0; j < _vectorContentSizeY; ++j) {
				std::cout << _vectorContent[_IndexHelper(i, j)] << ", ";
			}
			std::cout << "| " << std::endl;
		}
	}

	template<int X, int Y>
	int Matrix<X, Y>::_IndexHelper(int x, int y)
	{
		return x + (y * _vectorContentSizeX);
	}
}