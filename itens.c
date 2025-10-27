#include "itens.h"
#include <string.h>

Item criar_arma(ID_Arma id){
    Item novo_item = {0};
    novo_item.tipo = TIPO_ITEM_ARMA;

    switch (id){
        case ESPADA_LONGA:
            strcpy(novo_item.nome, "Espada Longa");
            strcpy(novo_item.descricao, "Uma espada longa e poderesa");
            novo_item.bonusAtaqueFisico = 2;
            break;
        case CAJADO_FOGO:
            strcpy(novo_item.nome, "Cajado de Fogo");
            strcpy(novo_item.descricao, "Um cajado banhado no poder de dragões vermelhos");
            novo_item.bonusAtaqueMagico = 2;
            break;
        case MARTELO_DE_GUERRA:
            strcpy(novo_item.nome, "Martelo de Guerra");
            strcpy(novo_item.descricao, "Um martelo poderoso, porém lento");
            novo_item.bonusAtaqueFisico = 4;
            novo_item.bonusDefesaFisica = -5;
            break;
        case CAJADO_VAZIO:
            strcpy(novo_item.nome, "Cajado do Vazio");
            strcpy(novo_item.descricao, "Um cajado com os poderes do espaço");
            novo_item.bonusAtaqueMagico = 4;
            break;
        case CAJADO_GELO:
            strcpy(novo_item.nome, "Cajado de Gelo");
            strcpy(novo_item.descricao, "Um cajado encontrado em geleiras, com um tremendo poder de gelo");
            novo_item.bonusAtaqueMagico = 4;
            break;
        case ARCO_PODEROSO:
            strcpy(novo_item.nome, "Arco Podereso");
            strcpy(novo_item.descricao, "Um Arco grande e podereso, porém lento");
            novo_item.bonusAtaqueFisico = 4;
            novo_item.bonusDefesaFisica = -5;
            break;
        case ESPADA_MAGICA:
            strcpy(novo_item.nome, "Espada Magica");
            strcpy(novo_item.descricao, "Uma espada encantada pelos magos");
            novo_item.bonusAtaqueFisico = 1;
            novo_item.bonusAtaqueMagico = 2;
            break;
        case ARCO_MAGICO:
            strcpy(novo_item.nome, "Arco Magico");
            strcpy(novo_item.descricao, "Um arco encantado pelos magos");
            novo_item.bonusAtaqueFisico = 1;
            novo_item.bonusAtaqueMagico = 2;
            break;
    }
    return novo_item;
}

Item criar_armadura(ID_Armadura id) {
    Item novo_item = {0};
    novo_item.tipo = TIPO_ITEM_ARMADURA;

    switch (id) {
        case ELMO_GUERREIRO:
            strcpy(novo_item.nome, "Elmo de Guerreiro");
            strcpy(novo_item.descricao, "Um elmo de ferro que oferece otima protecao.");
            novo_item.bonusDefesaFisica = 20;
            novo_item.bonusVida = 10;
            break;
        case ARMADURA_FERRO:
            strcpy(novo_item.nome, "Armadura de Ferro");
            strcpy(novo_item.descricao, "Pesada, mas extremamente resistente a dano fisico.");
            novo_item.bonusDefesaFisica = 40;
            novo_item.bonusDefesaMagica = -5;
            break;
        case CHAPEU_MAGICO:
            strcpy(novo_item.nome, "Chapeu de Mago");
            strcpy(novo_item.descricao, "Um chapeu pontudo que amplia a concentracao magica.");
            novo_item.bonusDefesaMagica = 20;
            novo_item.bonusAtaqueMagico = 5;
            break;
        case MANTO_MAGICO:
            strcpy(novo_item.nome, "Manto Magico");
            strcpy(novo_item.descricao, "Tecido com fios de mana para repelir feiticos.");
            novo_item.bonusDefesaMagica = 35;
            break;
        case MANTO_ROBUSTO:
            strcpy(novo_item.nome, "Manto Robusto");
            strcpy(novo_item.descricao, "Um manto de couro grosso, oferece protecao equilibrada.");
            novo_item.bonusDefesaFisica = 15;
            novo_item.bonusDefesaMagica = 15;
            break;
        case ARMADURA_LEVE:
            strcpy(novo_item.nome, "Armadura Leve");
            strcpy(novo_item.descricao, "Feita de couro batido, nao restringe os movimentos.");
            novo_item.bonusDefesaFisica = 25;
            break;
    }
    return novo_item;
}