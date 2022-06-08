#include <iostream>

/**
 * Converts the provided currencies into a total USD amount.
 * Conversion rates based on current Google data.
 *
 * @return int
 */
int main()
{
  double pesos;
  double reais;
  double soles;

  double dollars;

  std::cout << "Enter number of Colombian Pesos: ";
  std::cin >> pesos;

  std::cout << "Enter number of Brazilian Reais: ";
  std::cin >> reais;

  std::cout << "Enter number of Peruvian Soles: ";
  std::cin >> soles;

  /**
    Conversion rates:
    1 pesos --> USD = 0.05
    1 reais --> USD = 0.21
    1 soles --> USD = 0.27
  */
  double pesosToUsd = 0.5;
  double reaisToUsd = 0.21;
  double solesToUsd = 0.27;

  dollars = (pesos * pesosToUsd) + (reais * reaisToUsd) + (soles * solesToUsd);

  std::cout << "US Dollars = $" << dollars << std::endl;

  return 0;
}