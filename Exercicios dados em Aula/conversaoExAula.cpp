#include <iostream>
#include <iomanip>

int main(){
    double val_dolar{}, cotacao{};
    std::cout << "Informe qtd dolar:";

    if(!(std::cin >> val_dolar) || val_dolar < 0){
        std::cerr << "Valor invalido" << std::endl;
        return 1;
    }
    std::cout << "Informe cotacao: ";
    if(!(std::cin >> cotacao) || cotacao < 0){
        std::cerr << "Valor invalido" << std::endl;
        return 1;
    }

    double val_reais = val_dolar * cotacao;
    std::cout << std::fixed << std::setprecision(2) << "Valor em reais: " << val_reais << "\n";

    return 0;
}