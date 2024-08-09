#include <iostream>
#include <list>
#include <map>
#include <vector>
#include "Span.hpp"

int	random_number()
{
	return (std::rand() % 1000);
}
int	main(void)
{
	std::vector<int> generate(15);
	std::srand(unsigned(time(NULL)));
	std::generate(generate.begin(), generate.end(), &random_number);
	Span span(10);


	span.addNumber(6);
	span.display_content();
	span.generate_on_all(&random_number);
	span.display_content();
	try
	{
		std::cout << span << std::endl;
		span = generate;
		std::cout << span << std::endl;
		// span.addNumber(6);
		/* code */
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::sort(generate.begin(), generate.end());
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "index["<< i << "];" << generate[i] << " ";
	}
	std::cout << std::endl;
	span.display_content();

	return 0;

}