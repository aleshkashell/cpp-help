#include <iostream>
//Заменить последовательность символов в тексте
void find_and_replace(std::string& source, std::string const& find, std::string const& replace)
{
   for(std::string::size_type i = 0; (i = source.find(find, i)) != std::string::npos;)
   {
       source.replace(i, find.length(), replace);
       i += replace.length();
   }
}
int main(){
	std::string text = "Я ем яблоки и апельсины";
	std::cout << text << std::endl;
	find_and_replace(text, "яблоки", "лимоны");
	std::cout << text << std::endl;
	return 0;
}
