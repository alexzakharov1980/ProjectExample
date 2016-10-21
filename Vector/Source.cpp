#include <vector>
#include <iostream>
//std::basic_string
//std::char_traits

template < class Symbol >
class TDefaultTraits
{
public:
	static Symbol GetTerminating()
	{
		return 0;
	}
};

template < typename Symbol , class SymbolTraits = TDefaultTraits < Symbol > >
class TString
{
public:
	TString( Symbol* ptr_symbols );

	void print();
private:
	std::vector < Symbol > SymbolVector;
};

template < typename Symbol, class SymbolTraits = TDefaultTraits < Symbol > >
TString< Symbol , SymbolTraits >::TString(Symbol* ptr_symbols)
{
	for (int i = 0; ptr_symbols[i] != SymbolTraits::GetTerminating() ; i++)
	{
		SymbolVector.push_back(ptr_symbols[i]);
	}
	SymbolVector.push_back( SymbolTraits::GetTerminating() );
}

template < typename Symbol, class SymbolTraits = TDefaultTraits < Symbol > >
void TString< Symbol , SymbolTraits >::print()
{
	for (int i = 0; SymbolVector[i] != SymbolTraits::GetTerminating(); i++)
	{
		std::cout << SymbolVector[i] ;
	}
	std::cout << std::endl;
}

class TCharTraitsExample
{
public:
	static char GetTerminating()
	{
		return ' ';
	}
};

void main()
{
	TString < char > string( "Hello world" );
	string.print();
	TString < char , TCharTraitsExample > string2("Hello world");
	string2.print();
}