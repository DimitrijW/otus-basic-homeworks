// OTUS C++ Basic course homework skeleton.
// Lexer using example

#include <iostream>

#include "astnode.hpp"
#include "lexer.hpp"
#include "parser.hpp"

int main() {
    // TODO
    // Implement the next classes:
    class Add
    {
        private:
        int addition(int a, int b)
        {
            int result = a + b;
            return(result);
        }
    };
    // class Sub
    // {
    //     private:
    //     int subtrach(int a, int b)
    //     {
    //         int result = a - b;
    //         return(result);
    //     }
    // };
    // class Mul
    // {
    //     private:
    //     int multi(int a, int b)
    //     {
    //         int result = a * b;
    //         return(result);
    //     }
    // };
    // class Div
    // {
    //     private:
    //     int divesion(int a, int b)
    //     {
    //         int result = a / b;
    //         return(result);
    //     }
    // };
    // class Variable
    // {
    //     public:
    //     double var1;
    //     double var2;
    //     private:

    // };
    
    // Add
    // Sub
    // Mul
    // Div
    // Variable

    // Without implementation that classes this application works only with numbers

    Lexer lexer(std::cin);
    Parser parser(lexer);

    ASTNode *ast = parser.parse();
    if (ast) {
         ast->print(std::cout);
    }

    return 0;
}
