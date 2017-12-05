/*
 * parser.h
 *
 *  Created on: Nov 24, 2017
 *      Author: zkauker
 */

#ifndef UTIL_H_
#define UTIL_H_

#include <string>
#include <vector>

/**
 * This is a collection of utility functions for our. Utility functions usually does not have
 * state (stored variables which the function's response depends on) we usually organize this
 * to a spearate file. In C++ we have a chance to put it on a namespace (see below), so we put
 * it there.
 */
namespace util {

	/**
	 * Contains the number of the days for each months
	 */
	const int _MONTH_DAYS[] = {
			/* JANUARY= */31, /* FEBURARY= */28, /* MARCH= */31, /* APRIL= */30,
			/* MAY= */31, /* JUNE= */30, /* JULY= */31, /* AUGUST= */31,
			/* SEPTEMBER= */30, /* OCTOBER= */31, /* NOVEMBER= */30, /* DECEMBER= */31
	};

	/**
	 * A structure to store the temperature and the timestamp. Plus an initializer, which
	 * helps the construction.
	 */
	struct temperature_record {
		int temperature;
		time_t timestamp;

		temperature_record(int temperature, time_t timestamp):
			temperature(temperature),
			timestamp(timestamp) {};
	};

	/**
	 * This is our custom exception for any parsing error. The code helps us to identify
	 * the location of the exception in the source code, the message can be displayed to
	 * the user.
	 */
	class ParserException: public std::exception {
		public:
			ParserException(int code, std::string message);
			~ParserException() _NOEXCEPT;
			const char* what() const _NOEXCEPT;
			int getCode();
			std::string getMessage();
		private:
			int _code;
			std::string _message;
	};

	/**
	 * Currently we have only this function, which is able to parse a line and return a
	 * temperature_record struct.
	 */
	temperature_record parseLine(std::string line);
};



#endif /* UTIL_H_ */
