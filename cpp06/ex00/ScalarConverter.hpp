#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <iomanip>
# include <limits>
# include <cmath>


class ScalarConverter {
	private:
		ScalarConverter() = delete;
		ScalarConverter(ScalarConverter &) = delete;
		ScalarConverter &operator=(ScalarConverter &) = delete;
		~ScalarConverter() = delete;

		template<typename From, typename To>
		static bool _isAccurateConversion(From src)  {
			To result = static_cast<To>(src);
			return (static_cast<From>(result) - src == 0);
		}

		static bool _isValidDouble(const std::string &);
		static bool _isValidFloat(const std::string &);
		static bool _isValidChar(const std::string &);

		static std::string _resolve(double num);
		static std::string _resolve(float num);
		static std::string _resolve(int num);
		static std::string _resolve(char num);

		template<typename T>
		static void _resolveOutput(T num, bool valid)
		{
			std::string imp		= "impossible";

			bool possibleChar	= valid && _isAccurateConversion<T, char>(num);
			bool possibleInt	= valid && _isAccurateConversion<T, int>(num);
			bool possibleFloat	= valid && (_isAccurateConversion<T, float>(num) || std::isnan(num) || std::isinf(num));
			bool possibleDouble	= valid && (_isAccurateConversion<T, double>(num) || std::isnan(num) || std::isinf(num));

			std::cout << "char: "	<< (possibleChar	? _resolve(static_cast<char>(num))	: imp) << std::endl;
			std::cout << "int: "	<< (possibleInt		? _resolve(static_cast<int>(num))	: imp) << std::endl;
			std::cout << "float: "	<< (possibleFloat	? _resolve(static_cast<float>(num))	: imp) << std::endl;
			std::cout << "double: " << (possibleDouble	? _resolve(static_cast<double>(num))	: imp) << std::endl;
		}

		
	public:
		static void convert(const std::string &);
};

#endif
