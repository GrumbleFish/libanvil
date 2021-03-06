/*
 * int_tag.hpp
 * Copyright (C) 2012 David Jolly
 * ----------------------
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef INT_TAG_HPP_
#define INT_TAG_HPP_

#include <string>
#include <vector>
#include "generic_tag.hpp"

class int_tag : public generic_tag {
private:

	/*
	 * Integer tag value
	 */
	int value;

public:

	/*
	 * Integer tag constructor
	 */
	int_tag(void) : generic_tag(INT) { value = 0; }

	/*
	 * Integer tag constructor
	 */
	int_tag(const int_tag &other) : generic_tag(other.name, INT) { value = other.value; };

	/*
	 * Integer tag constructor
	 */
	int_tag(const std::string &name) : generic_tag(name, INT) { value = 0; }

	/*
	 * Integer tag constructor
	 */
	int_tag(int value) : generic_tag(INT) { this->value = value; }

	/*
	 * Integer tag constructor
	 */
	int_tag(const std::string &name, int value) : generic_tag(name, INT) { this->value = value; }

	/*
	 * Integer tag destructor
	 */
	virtual ~int_tag(void) { return; }

	/*
	 * Integer tag assignment operator
	 */
	int_tag &operator=(const int_tag &other);

	/*
	 * Integer tag equals operator
	 */
	bool operator==(const generic_tag &other);

	/*
	 * Integer tag not-equals operator
	 */
	bool operator!=(const generic_tag &other) { return !(*this == other); }

	/*
	 * Get a int tag's data
	 */
	std::vector<char> get_data(bool list_ele);

	/*
	 * Save a int tag's data to a stream
	 */
	void get_data(bool list_ele, byte_stream& stream);

	/*
	 * Return the size of a int tag's data. Equivaluent to get_data().size(), but faster;
	 */
	unsigned int get_data_size(bool list_ele);

	/*
	 * Return a integer tag's value
	 */
	int get_value(void) { return value; }

	/*
	 * Set a integer tag's value
	 */
	void set_value(int value) { this->value = value; }

	/*
	 * Return a string representation of a integer tag
	 */
	std::string to_string(unsigned int tab);
};

#endif
