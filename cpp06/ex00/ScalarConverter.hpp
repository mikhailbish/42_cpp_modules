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

		static bool _isValidDouble(const std::string &);
		static bool _isValidFloat(const std::string &);
		static bool _isValidInt(const std::string &);
		static bool _isValidChar(const std::string &);
		static bool _isValidLong(const std::string &);
		static std::string _resolve(double num, bool isValidInt);
		static std::string _resolve(float num, bool isValidInt);
		static std::string _resolve(int num);
		static std::string _resolve(char num);
	public:
		static void convert(const std::string &);
};

#endif
