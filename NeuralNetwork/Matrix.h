#pragma once
#include <vector>
#include <cmath>
#include <cassert>

class Matrix
{
public:
	uint32_t _cols;
	uint32_t _rows;
	std::vector<float> _vals;

public:
	Matrix(uint32_t cols, uint32_t rows)
		:_cols(cols),
		_rows(rows),
		_vals({})
	{
		_vals.resize(_cols * _rows, 0.0f);
	}

	float &at(uint32_t col, uint32_t row){
		return _vals[col + row * _cols];
	}

	Matrix multiply(Matrix& target)
	{
		assert(_cols == target._rows);
		Matrix output(target._cols, _rows);
		for (uint32_t y = 0; y < output._rows; y++)
			for (uint32_t x = 0; x < output._cols; x++)
			{
				float result = 0.0f;
				for (uint32_t k = 0; k < _cols; k++)
					result += at(k, y) * target.at(x, k);
				output.at(x, y) = result;
	
			}
		return output;
	}

	Matrix multiplyScaler(float s)
	{

		Matrix output(_cols, _rows);
		for (uint32_t y = 0; y < output._rows; y++)
			for (uint32_t x = 0; x < output._cols; x++)
			{

				output.at(x, y) = at(x,y) * s;

			}
		return output;
	}

	Matrix add(Matrix& target)
	{
		assert(_rows == target._rows && _cols == target._cols);
		Matrix output(_rows, _cols);
		for (uint32_t y = 0; y < output._rows; y++)
			for (uint32_t x = 0; x < output._cols; x++)
			{
				output.at(x, y) = at(x, y) + target.at(x, y);
			}
		return output;
	}

	Matrix addScaler(float s)
	{

		Matrix output(_cols, _rows);
		for (uint32_t y = 0; y < output._rows; y++)
			for (uint32_t x = 0; x < output._cols; x++)
			{

				output.at(x, y) = at(x, y) + s;

			}
		return output;
	}

	Matrix negative()
	{
		Matrix output(_cols, _rows);
		for (uint32_t y = 0; y < output._rows; y++)
			for (uint32_t x = 0; x < output._cols; x++)
			{
				output.at(x, y) = -at(x, y);
			}
		return output;
	}

	Matrix transpose()
	{
		Matrix output(_rows, _cols);
		for (uint32_t y = 0; y < output._rows; y++)
			for (uint32_t x = 0; x < output._cols; x++)
			{
				output.at(x, y) = at(y, x);
			}
		return output;
	}

};