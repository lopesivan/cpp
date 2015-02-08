/*
Caros, estou lendo o livro Metaprogramação e tenho dúvidas sobre termos e como
descrever códogos, para tanto, qual correta de explicar o código abaixo:

1* - o segundo template é uma expecialização do primeiro
2  - a função f é criada em tempo de compilação

um abraço e obrigado
Ivan
*/

#include <iostream>
//using namespace std;

template<typename Iterator>
struct iterator_traits {
	typedef typename Iterator::value_type value_type;
};

template<typename T>
struct iterator_traits<T*> {
	typedef T value_type;
};

template <class ForwardIterator1, class ForwardIterator2>
void iter_swap(ForwardIterator1 i1, ForwardIterator2 i2)
{
	typename
	iterator_traits<ForwardIterator1>::value_type tmp = *i1;
	*i1 = *i2;
	*i2 = tmp;
};

void f(int* p1, int* p2)
{
	iter_swap(p1, p2);
}

//
// main
//
int main()
{
	int a = 5;
	int b = 7;

	f(&a, &b);

	std::cout << "a" << a << std::endl;
	std::cout << "b" << b << std::endl;

	return 0; // success return
}
