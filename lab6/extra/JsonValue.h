#pragma once
#include <ostream>
#include <string>
class JsonValue
{
public:
    virtual ~JsonValue() = 0;

    virtual void print(std::ostream& out) = 0;
    virtual operator unsigned() = 0;
};

class NullValue : public JsonValue {
public:
    operator unsigned() override;
    void print(std::ostream& out) override;
};

class NumberValue : public JsonValue {
    double number;
public:
    operator unsigned() override;
    NumberValue(double n);
    void print(std::ostream& out) override;
};

class BoolValue : public JsonValue {
    bool value;
public:
    operator unsigned() override;
    BoolValue(bool n);
    void print(std::ostream& out) override;
};

class StringValue : public JsonValue {
    std::string str;
public:
    operator unsigned() override;
    StringValue(std::string s);
    void print(std::ostream& out) override;
};

class ArrayValue : public JsonValue {
    JsonValue* array[16];
    int size;
public:
    operator unsigned() override;
    ArrayValue();
    void add(JsonValue* n);
    void print(std::ostream& out) override;
};

class ObjectValue : public JsonValue {
    struct pair {
        std::string name;
        JsonValue* obj;
    };
    pair p[16];
    int size;
public:
    operator unsigned() override;
    ObjectValue();
    void add(std::string s,JsonValue* n);
    void print(std::ostream& out) override;
};


