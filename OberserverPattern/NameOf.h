#pragma once

#ifndef SYNTAX_NAME_OF_20190325092225

#include <string>
#include <regex>
#include <stdexcept>
#include "Property.h"

#define SYNTAX_NAME_OF_20190325092225
#define nameof($name) syntax::__nameof<0>(#$name, sizeof($name))

namespace syntax {
	template<int t>
    std::string __nameof(const std::string &name, std::size_t)
	{
		std::smatch match;
		std::regex regex("^&?([_a-zA-Z]\\w*(->|\\.|::))*([_a-zA-Z]\\w*)$");
		if (std::regex_match(name, match, regex)) {
			if (match.size() == 4) {
				return  match[3];
			}
		}
		throw std::logic_error("regex error: $name in nameof($name) | The expression is \"" + name + "\".");
	}
}

#endif 