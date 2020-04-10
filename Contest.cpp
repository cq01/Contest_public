//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<tuple>
#include<memory>
#include<initializer_list>
template<typename T>
class T_Counter
{
	T val;
public:
	T_Counter() = default;
	T_Counter(const T& _val) :val(_val) {}
	T_Counter(const T_Counter&) = default;
	T_Counter& operator=(const T& _val)
	{
		val = _val;
		return *this;
	}
	T_Counter operator-()const
	{
		return -val;
	}
	operator T()const { return val; }
	T_Counter& operator+=(const T_Counter& other) { return *this = *this + other; }
	T_Counter& operator-=(const T_Counter& other) { return *this = *this - other; }
	T_Counter& operator*=(const T_Counter& other) { return *this = *this * other; }
	template<typename T1>friend T_Counter<T1> operator+(const T_Counter<T1>& a, const T_Counter<T1>& b);
	template<typename T1>friend T_Counter<T1> operator-(const T_Counter<T1>& a, const T_Counter<T1>& b);
	template<typename T1>friend T_Counter<T1> operator*(const T_Counter<T1>& a, const T_Counter<T1>& b);
	template<typename T1>friend std::istream& operator>>(std::istream& input, const T_Counter<T1>& b);
	template<typename T1>friend std::ostream& operator<<(std::ostream& output, const T_Counter<T1>& b);
};
template<typename T> T_Counter<T> operator+(const T_Counter<T>& a, const T_Counter<T>& b)
{
	return T_Counter<T>(a.val + b.val);
}
template<typename T> T_Counter<T> operator-(const T_Counter<T>& a, const T_Counter<T>& b)
{
	return T_Counter<T>(a.val - b.val);
}
template<typename T> T_Counter<T> operator*(const T_Counter<T>& a, const T_Counter<T>& b)
{
	return T_Counter<T>(a.val * b.val);
}
template<typename T> std::istream& operator>>(std::istream& input, const T_Counter<T>& b)
{
	input >> b.val;
	return input;
}
template<typename T> std::ostream& operator<<(std::ostream& output, const T_Counter<T>& b)
{
	output << b.val;
	return output;
}
template<typename T>
class T_Vector
{
	using ValueType = T_Counter<T>;
	size_t cnt;
	ValueType* vec;
public:
	size_t size()const { return cnt; }
	T_Vector() = default;
	T_Vector& reset(size_t n, ValueType val = 0)
	{
		cnt = n;
		delete[] vec;
		vec = new ValueType[cnt];
		std::fill_n(vec, cnt, val);
		return *this;
	}
	T_Vector(size_t n, ValueType val = 0) :cnt(), vec() { reset(n, val); }
	T_Vector& operator=(T_Vector&& other)noexcept
	{
		if (&vec == &other.vec)return *this;
		cnt = other.cnt;
		vec = other.vec;
		other.vec = nullptr;
		other.cnt = 0;
		return *this;
	}
	T_Vector(T_Vector&& other)noexcept :cnt(), vec() { *this = std::move(other); }
	T_Vector& operator=(const T_Vector& other)
	{
		if (&vec == &other.vec)return *this;
		reset(other.cnt);
		std::copy_n(other.vec, cnt, vec);
		return *this;
	}
	T_Vector& operator=(const std::initializer_list<ValueType>& lst)
	{
		reset(lst.size());
		std::copy(lst.begin(), lst.end(), vec);
		return *this;
	}
	T_Vector(const std::initializer_list<ValueType>& lst) :cnt(), vec() { *this = lst; }

	T_Vector(const T_Vector& other) :cnt(), vec() { *this = other; }
	ValueType& operator[](size_t n)
	{
		if (n >= cnt)throw std::out_of_range("Index out of range!\n");
		return vec[n];
	}
	const ValueType& operator[](size_t n)const
	{
		if (n >= cnt)throw std::out_of_range("Index out of range!\n");
		return vec[n];
	}

	T_Vector operator-()const
	{
		T_Vector ret(cnt);
		for (size_t i = 0; i < cnt; ++i)ret.vec[i] = -vec[i];
		return ret;
	}
	T_Vector& operator+=(const T_Vector& other) { return *this = *this + other; }
	T_Vector& operator-=(const T_Vector& other) { return *this = *this - other; }
	~T_Vector()
	{
		cnt = 0;
		delete[] vec;
		vec = nullptr;
	}
};
template<typename T>T_Vector<T> operator+(const T_Vector<T>& a, const T_Vector<T>& b)
{
	size_t n = a.size();
	if (n != b.size()) throw std::invalid_argument("Size not equal!\n");
	T_Vector<T> ret(n);
	for (size_t i = 0; i < n; ++i)ret[i] = a[i] + b[i];
	return ret;
}
template<typename T>T_Vector<T> operator-(const T_Vector<T>& a, const T_Vector<T>& b)
{
	size_t n = a.size();
	if (n != b.size()) throw std::invalid_argument("Size not equal!\n");
	T_Vector<T> ret(n);
	for (size_t i = 0; i < n; ++i)ret[i] = a[i] - b[i];
	return ret;
}
template<typename T>T_Counter<T> operator*(const T_Vector<T>& a, const T_Vector<T>& b)
{
	size_t n = a.size();
	if (n != b.size()) throw std::invalid_argument("Size not equal!\n");
	T_Counter<T> sum = 0;
	for (size_t i = 0; i < n; ++i)sum += a[i] * b[i];
	return sum;
}

template<typename T>
class T_Matrix
{
	using ValueType = T_Vector<T>;
	size_t row, column;
	ValueType* mat;
public:
	std::pair<size_t, size_t> size()const { return std::make_pair(row, column); }
	T_Matrix() = default;
	T_Matrix& reset(size_t n, size_t m, T_Counter<T> val = 0)
	{
		row = n, column = m;
		delete[] mat;
		mat = new ValueType[row]();
		for (int i = 0; i < row; ++i)mat[i].reset(m, val);
		return *this;
	}
	T_Matrix(size_t n, size_t m, T_Counter<T> val = 0) :row(), column(), mat() { reset(n, m, val); }
	T_Matrix(std::pair<size_t, size_t> _size, T val = 0) :row(), column(), mat()
	{
		reset(_size.first, _size.second, val);
	}
	T_Matrix& operator=(T_Matrix&& other)noexcept
	{
		if (&mat == &other.mat)return *this;
		mat = other.mat;
		row = other.row;
		column = other.column;
		other.mat = nullptr;
		other.column = 0;
		other.row = 0;
		return *this;
	}
	T_Matrix(T_Matrix&& other)noexcept :row(), column(), mat() { *this = std::move(other); }
	T_Matrix& operator=(const T_Matrix& other)
	{
		if (&mat == &other.mat)return *this;
		delete[] mat;
		T_Matrix(other.row, other.column);
		std::copy(other.mat, row, mat);
		return *this;
	}
	T_Matrix(const T_Matrix& other) :row(), column(), mat() { *this = other; }
	T_Matrix& operator=(const std::initializer_list<ValueType>& lst)
	{
		reset(lst.size(), lst.begin()->size());
		for (auto& val : lst)if (column != val.size())
		{
			this->~T_Matrix();
			throw std::invalid_argument("column error!\n");
		}
		std::copy(lst.begin(), lst.end(), mat);
		return *this;
	}
	T_Matrix(const std::initializer_list<ValueType>& lst) :row(), column(), mat() { *this = lst; }
	T_Matrix& operator=(std::initializer_list<ValueType>&& lst)
	{
		reset(lst.size(), lst.begin()->size());
		for (auto& val : lst)if (column != val.size())
		{
			this->~T_Matrix();
			throw std::invalid_argument("column error!\n");
		}
		std::move(lst.begin(), lst.end(), mat);
		return *this;
	}
	T_Matrix(std::initializer_list<ValueType>&& lst) :row(), column(), mat() { *this = std::move(lst); }
	ValueType& operator[](size_t n)
	{
		if (n >= row)throw std::out_of_range("Index too big!\n");
		return mat[n];
	}
	const ValueType& operator[](size_t n)const
	{
		if (n >= row)throw std::out_of_range("Index too big!\n");
		return mat[n];
	}
	T_Matrix operator-()const
	{
		T_Matrix ret(size());
		for (size_t i = 0; i < row; ++i)ret.mat[i] = -mat[i];
	}
	T_Matrix& operator+=(const T_Matrix& other) { return *this = *this + other; }
	T_Matrix& operator-=(const T_Matrix& other) { return *this = *this - other; }
	T_Matrix& operator*=(const T_Matrix& other) { return *this = *this * other; }
	~T_Matrix()
	{
		if (row)delete[] mat;
		row = column = 0;
		mat = nullptr;
	}
};
template<typename T> T_Matrix<T> operator+(const T_Matrix<T>& a, const T_Matrix<T>& b)
{
	auto siz = a.size();
	if (siz != b.size())throw std::invalid_argument("Not same type!\n");
	T_Matrix<T> ret(siz);
	for (size_t i = 0; i < siz.first; ++i)ret[i] = a[i] + b[i];
	return ret;
}
template<typename T> T_Matrix<T> operator-(const T_Matrix<T>& a, const T_Matrix<T>& b)
{
	auto siz = a.size();
	if (siz != b.size())throw std::invalid_argument("Not same type!\n");
	T_Matrix<T> ret(siz);
	for (size_t i = 0; i < siz.first; ++i)ret[i] = a[i] - b[i];
	return ret;
}
template<typename T> T_Matrix<T> operator*(const T_Matrix<T>& a, const T_Matrix<T>& b)
{
	if (a.size().second != b.size().first)throw std::invalid_argument("Not same type!\n");
	size_t n = a.size().first, m = b.size().second, K = a.size().second;
	T_Matrix<T> ret(n, m);
	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < m; ++j)
		{
			for (size_t k = 0; k < K; ++k)
			{
				ret[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return ret;
}
int main()
{
	using namespace std;
	//#define DEBUG
#ifdef DEBUG
	fstream in, out;
	in.open("C:\\Users\\qi010\\Desktop\\cin.txt", ios::in);
	out.open("C:\\Users\\qi010\\Desktop\\cout.txt", ios::app);
	streambuf* stream_buffer_cout = cout.rdbuf();
	streambuf* stream_buffer_cin = cin.rdbuf();
	streambuf* stream_buffer_in = in.rdbuf();
	streambuf* stream_buffer_out = out.rdbuf();
	cin.rdbuf(stream_buffer_in);
	cout.rdbuf(stream_buffer_out);
#endif // DEBUG

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	//TODO:test
	/*T_Counter<int> a, b;
	a = 20, b = 34;
	auto c = a - b;
	cout << c << endl;*/
	/*T_Vector<int> a = { 1,2,3}, b = { 4,5,6 };
	auto c = a + b;
	for (int i = 0; i < c.size(); ++i)cout << c[i] << endl;*/
	T_Matrix<int> a = { {1,2},{2,3},{3,4} }, b = { {1,3,5},{2,4,5} }, c = { {1,-34},{2,334},{3,43} };
	auto d = a - c;
	d -= a;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 2; ++j)
			cout << d[i][j] << ' ';
		cout << endl;
	}
}