#include "JsonValue.h"

JsonValue::~JsonValue() {}


ArrayValue::operator unsigned()
{
	int sum = 0;
	for (int i = 0; i < this->size; i++)
	{
		sum += (unsigned)(*array[i]);
	}
	return ++sum;
}

ArrayValue::ArrayValue()
{
	this->size = 0;
	for (int i = 0; i < 16; i++)
	{
		array[i] = 0;
	}
}

void ArrayValue::add(JsonValue* n)
{
	array[size++] = n;
}


ObjectValue::operator unsigned()
{
	int sum=0;

	for (int i = 0; i < this->size; i++)
	{
		sum += (unsigned)(*p[i].obj);
	}

	return ++sum;
}

ObjectValue::ObjectValue()
{
	size = 0;
	for (int i = 0; i < 16; i++)
	{
		p[i].obj = nullptr;
		p[i].name = "";
	}
}

void ObjectValue::add(std::string s, JsonValue* n)
{
	p[size].name = s;
	p[size].obj = n;
	size++;
}

void ObjectValue::print(std::ostream& out)
{
	out << "{";
	for (int i = 0; i < size; i++)
	{
		if ((i + 1) == size)
		{
			out << "\"" << p[i].name << "\"" << ": "; p[i].obj->print(out);
		}
		else {
			out << "\"" << p[i].name << "\"" << ": "; p[i].obj->print(out); out << ", ";
		}

	}
	out << "}";
}

NumberValue::operator unsigned()
{
	return 1;
}

NumberValue::NumberValue(double n)
{
	this->number = n;
}

void NumberValue::print(std::ostream& out)
{
	out << number;
}

BoolValue::operator unsigned()
{
	return 1;
}

BoolValue::BoolValue(bool n)
{
	this->value = n;
}

void BoolValue::print(std::ostream& out)
{
	if (value)
	{
		out << "true";
	}
	else {
		out << "false";
	}
}

StringValue::operator unsigned()
{
	return 1;
}

StringValue::StringValue(std::string s)
{
	this->str = s;
}

void StringValue::print(std::ostream& out)
{
	out << "\"" << str << "\"";
}

void ArrayValue::print(std::ostream& out)
{
	out << "[";
	for (int i = 0; i < size; i++)
	{
		if (i + 1 == size)
		{
			array[i]->print(out);
		}
		else {

			array[i]->print(out);
			out << ", ";

		}
	}
	out << "]";
}

NullValue::operator unsigned()
{
	return 1;
}

void NullValue::print(std::ostream& out)
{
	out << "null";
}