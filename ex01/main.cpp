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
	Span span(10);
	std::srand(unsigned(time(NULL)));


	span.addNumber(6);
	span.generate_on_all(&random_number);
	span.display_content();
	try
	{
		std::cout << span << std::endl;
		// span.addNumber(6);
		/* code */
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return 0;

}