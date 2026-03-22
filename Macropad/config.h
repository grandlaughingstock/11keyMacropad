#define MATRIX_ROWS 3
#define MATRIX_COLS 3

#define MATRIX_ROW_PINS { GP5, GP4, GP3 }
#define MATRIX_COL_PINS { GP2, GP1, GP0 }

#define DIODE_DIRECTION COL2ROW

#define ENCODERS_PAD_A { GP9 }
#define ENCODERS_PAD_B { GP8 }

#define DIRECT_PINS { \
    { GP7, GP6, GP10 } \
}

#define DEBOUNCE 5