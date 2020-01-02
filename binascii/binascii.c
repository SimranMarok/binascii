

#include "binascii.h"

uint16_t size_calc(const char *input) {
  uint16_t str_size = 0;
  while (input[str_size] != '\0') {
    str_size += 1;
  }
  return str_size;
}

void b2a_hex( const char* input, char* dest)
{
  uint16_t str_size = size_calc(input);

  const static char* HexCodes = "0123456789ABCDEF";

  for (uint16_t i = 0; i < str_size; i += 1)
  {
    unsigned char BinValue = input[i];
    // High half
    dest[i * 2] = HexCodes[( BinValue >> 4 ) & 0x0F];
    dest[i * 2 + 1] = HexCodes[BinValue & 0x0F];
  }
}

void a2b_hex( const char* input , char* dest)
{
  uint16_t str_size = size_calc(input);
  
  const static char* HexCodes = "0123456789ABCDEF";
  const char* BinString;
  
  for ( uint16_t i = 0; i < str_size - 1; i += 2 )
  {
    dest[i] = ( input[i] >= 'A' ? input[i] - 'A' + 10 : input[i] - '0' ) * 16 
            + ( input[i + 1] >= 'A' ? input[i + 1] - 'A' + 10 : input[i + 1] - '0' );
  }
}

/*
std::string Input = "\01ABC\xFF";
std::cout << binascii::b2a_hex( Input ) << std::endl;
Input = "01414243FF";
std::cout << binascii::a2b_hex( Input ) << std::endl;
// Check for error, hex string is missing a char. It should ignore last
half char.
Input = "4142434";
std::cout << binascii::a2b_hex( Input ) << std::endl;

std::string wait;
std::getline(std::cin, wait );
*/