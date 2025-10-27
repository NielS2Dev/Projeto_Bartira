#ifndef ITENS_H
#define ITENS_H

typedef enum {
    ESPADA_LONGA,
    MARTELO_DE_GUERRA,
    CAJADO_VAZIO,
    CAJADO_FOGO,
    CAJADO_GELO,
    ARCO_PODEROSO,
    ARCO_RAPIDO,
    ESPADA_MAGICA,
    ARCO_MAGICO
} ID_Arma;

typedef enum {
    ELMO_GUERREIRO,
    ARMADURA_FERRO,
    CHAPEU_MAGICO,
    MANTO_MAGICO,
    MANTO_ROBUSTO,
    ARMADURA_LEVE
} ID_Armadura;

typedef enum {
    TIPO_ITEM_ARMA,
    TIPO_ITEM_ARMADURA,
    TIPO_ITEM_POCAO
} TipoItem;

typedef struct {
    char nome[50];
    char descricao[100];
    TipoItem tipo;

    int bonusAtaqueFisico;
    int bonusAtaqueMagico;
    int bonusDefesaFisica;
    int bonusDefesaMagica;
    int bonusVida;
} Item;


/**
 * @brief Cria um item de arma baseado em seu ID.
 * @param id O ID da arma a ser criada (ex: ESPADA_LONGA).
 * @return Uma struct Item preenchida com os atributos da arma.
 */
Item criar_arma(ID_Arma id);

/**
 * @brief Cria um item de armadura baseado em seu ID.
 * @param id O ID da armadura a ser criada (ex: ELMO_GUERREIRO).
 * @return Uma struct Item preenchida com os atributos da armadura.
 */
Item criar_armadura(ID_Armadura id);


#endif // ITENS_H