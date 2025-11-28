#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>
# include <iostream>
//# include <cstdlib>
# include <sstream>
# include <iomanip>


class ScalarConverter {
	private:
		ScalarConverter() = delete;
		ScalarConverter(ScalarConverter &) = delete;
		ScalarConverter &operator=(ScalarConverter &) = delete;
		~ScalarConverter() = delete;
/*
		static bool _isValidDouble(const std::string &);
		static bool _isValidFloat(const std::string &);
		static bool _isValidInt(const std::string &);
		static bool _isValidChar(const std::string &);
*/
		static std::string _resolvedDouble(const std::string &text);
		static std::string _resolvedInteger(const std::string &text);
		static std::string _resolvedFloat(const std::string &text);
		static std::string _resolvedChar(const std::string &text);
	public:
		static void convert(const std::string &);
};

#endif
