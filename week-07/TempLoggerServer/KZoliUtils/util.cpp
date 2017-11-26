#include <iostream>
#include <sstream>
#include "util.h"

/**
 * implementation of our utility collection
 */
namespace util {

	/**
	 * Internal function declaration, not declared in the util.h, so these functions won't
	 * be availabe for our implementation. The declaration is up here to be able to use these
	 * win parseLine() function even if the implementation of these will come later.
	 */
	tm _packDateTime(int year, int month, int day, int hour, int minute, int second);
	void _checkRange(int number, int min, int max);

	/**
	 * Here comes the implementation of our custom exception. Nothing special: constructor,
	 * the required destructor with empty implementation, getters for the code and message
	 * fields, the required what() implementation and it's done.
	 */
	ParserException::ParserException(int code, std::string message): _code(code), _message(message) {};
	ParserException::~ParserException() _NOEXCEPT {};
	int ParserException::getCode() { return _code; };
	std::string ParserException::getMessage() { return _message; };
	const char* ParserException::what() const _NOEXCEPT {
		std::ostringstream res;
		res << "ParserException(code=" << _code << ",message=" << _message << ")";
		return res.str().c_str();
	};

	/**
	 * This is our function, which does the logic. The beginning should be familiar!
	 */
	temperature_record parseLine(std::string line) {
		// let's declare our variables in which we read the fields
		int year, month, day, hour, minute, second, temperature;

		// let's do this with streams!
		std::istringstream line_stream(line);

		// this is the tricky separator "sinker". As you can see below, we push the separator
		// characters (like dots between the part of the date numbers, the : between the
		// components of the time) to be able to read the next integer. Simple one-liner, which
		// fills up our numbers.
		char sep;
		line_stream >> year >> sep >> month >> sep >> day >> hour >> sep >> minute >> sep >> second >> temperature;
		if (line_stream.fail()) {
			throw new ParserException(1, "Unsupported string format!");
		}

		// we've successfully read the numbers, let's check the temperature
		if (temperature < -273 || temperature > 1000) {
			throw new ParserException(2, "Temperature is out of range!");
		}

		// temperature is OK, so let's do something with the date-time
		tm t = _packDateTime(year, month, day, hour, minute, second);

		// let's try to calculate the timestamp
		time_t timestamp = mktime(&t);
		if (timestamp < 0) {
			throw new ParserException(4, "Could not create timestamp based on the given data!");
		}

		// now the date and time is OK as well, so let's return the data
		return temperature_record(temperature,  timestamp);
	};

	/**
	 * Validates the date and creates a tm structure
	 */
	tm _packDateTime(int year, int month, int day, int hour, int minute, int second) {
		// validating date - checking the month
		_checkRange(month, 1, 12);

		// let's check what is the day limit in that month
		int monthDayMax = _MONTH_DAYS[month-1];

		// the evil feb. 29: https://en.wikipedia.org/wiki/February_29
		if (month == 2) {
			if (!year%4) {
				if (year%100 || !year%400) {
					monthDayMax = 29;
				}
			}
		}
		_checkRange(day, 1, monthDayMax);

		// Date is OK, checking time
		_checkRange(hour, 0, 23);
		_checkRange(minute, 0, 59);
		_checkRange(second, 0, 59);

		// Time is OK, packing tm structure manually. Ref: http://www.cplusplus.com/reference/ctime/tm/
		tm t;
		t.tm_sec = second;
		t.tm_min = minute;
		t.tm_hour = hour;
		t.tm_mday = day;
		t.tm_mon = month-1;
		t.tm_year = year-1900;

		return t;
	};

	/**
	 * A helper function, which throws our exception if the 1st argument is out of the specified
	 * range of 2nd and 3rd (min and max) arguments.
	 */
	void _checkRange(int number, int min, int max) {
		if (number < min || number > max) {
			throw new ParserException(3, "Checked number is out of range!");
		}
	}
};
