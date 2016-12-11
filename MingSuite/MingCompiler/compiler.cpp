#include "compiler.h"

#include "scanner.h"

#include <iostream>
using namespace std;

class compiler_impl
{
public:
    compiler_impl(const char* source_file);
    void compile();
private:
    const char* source_file;
};

compiler::compiler(const char* source_file)
{
    this->impl = new compiler_impl(source_file);
}

void compiler::compile()
{
    this->impl->compile();
}

compiler_impl::compiler_impl(const char* source_file)
{
    this->source_file = source_file;
}

void compiler_impl::compile()
{
    scanner s(this->source_file);
    s.scan();
    cout << s.get_token_type() << endl;
}
