enum class CardType {
    CHARACTER,
    ACTION,
    PERMANENT,
    WEAPON
};

enum class CardName {
    // Action
    CEREMONIE_DU_THE,
    CRI_DE_GUERRE,
    DAIMYO,
    DIVERSION,
    GEISHA,
    MEDITATION,
    JU_JITSU,

    // Permanent
    ATTAQUE_RAPIDE,
    CONCENTRATION,
    CODE_DU_BUSHIDO,
};

struct Card {
    CardName name;
    CardType type;
};