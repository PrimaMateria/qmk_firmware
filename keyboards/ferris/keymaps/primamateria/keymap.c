#include QMK_KEYBOARD_H

enum ferris_layers {
    _QWERTY,
    _UNIL,
    _UNIR,
    _NAV,
    _SYMBOLR,
    _SYMBOLL,
    _FKEYS,
    _NUM,
    _ESCAPE,
    _WM,
    _TMUX,
    _NVIM
};

enum custom_keycodes {
    SS_TMUX_1 = SAFE_RANGE,
    SS_TMUX_2,
    SS_TMUX_3,
    SS_TMUX_4,
    SS_TMUX_5,
    SS_TMUX_6,
    SS_TMUX_7,
    SS_TMUX_8,
    SS_TMUX_9,
    SS_TMUX_O,
    SS_TMUX_PERC,
    SS_TESC,
    SS_NVIM_TREE,
    SS_NVIM_WU,
    SS_NVIM_GIT,
    SS_NVIM_WC,
    SS_NVIM_SAVE,
    SS_NVIM_WL,
    SS_NVIM_WD,
    SS_NVIM_WR,
    SS_NVIM_WS,
    SS_NVIM_WV,
    SS_WINBAR,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SS_TMUX_1:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "1");
            }
            break;
        case SS_TMUX_2:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "2");
            }
            break;
        case SS_TMUX_3:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "3");
            }
            break;
        case SS_TMUX_4:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "4");
            }
            break;
        case SS_TMUX_5:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "5");
            }
            break;
        case SS_TMUX_6:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "6");
            }
            break;
        case SS_TMUX_7:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "7");
            }
            break;
        case SS_TMUX_8:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "8");
            }
            break;
        case SS_TMUX_9:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "9");
            }
            break;
        case SS_TMUX_O:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "o");
            }
            break;
        case SS_TMUX_PERC:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "%");
            }
            break;
        case SS_TESC:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("\\n"));
            }
            break;

        case SS_NVIM_WU:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("w") "k");
            }
            break;
        case SS_NVIM_WD:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("w") "j");
            }
            break;
        case SS_NVIM_WL:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("w") "h");
            }
            break;
        case SS_NVIM_WR:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("w") "l");
            }
            break;
        case SS_NVIM_WC:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("w") "q");
            }
            break;
        case SS_NVIM_WS:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("w") "s");
            }
            break;
        case SS_NVIM_WV:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("w") "v");
            }
            break;
        case SS_NVIM_GIT:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("g"));
            }
            break;
        case SS_NVIM_TREE:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("n"));
            }
            break;
        case SS_NVIM_SAVE:
            if (record->event.pressed) {
                SEND_STRING("\\\\");
            }
            break;
    }

    return true;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

enum unicode_names {
    EURO,
    A_ACUTE_SMALL,
    A_ACUTE_BIG,
    C_CARON_SMALL,
    C_CARON_BIG,
    D_CARON_SMALL,
    D_CARON_BIG,
    E_ACUTE_SMALL,
    E_ACUTE_BIG,
    I_ACUTE_SMALL,
    I_ACUTE_BIG,
    L_CARON_SMALL,
    L_CARON_BIG,
    N_CARON_SMALL,
    N_CARON_BIG,
    O_ACUTE_SMALL,
    O_ACUTE_BIG,
    S_CARON_SMALL,
    S_CARON_BIG,
    T_CARON_SMALL,
    T_CARON_BIG,
    U_ACUTE_SMALL,
    U_ACUTE_BIG,
    Y_ACUTE_BIG,
    Y_ACUTE_SMALL,
    Z_CARON_SMALL,
    Z_CARON_BIG,

    A_DIAERESIS_SMALL,
    A_DIAERESIS_BIG,
    U_DIAERESIS_SMALL,
    U_DIAERESIS_BIG,
    O_DIAERESIS_SMALL,
    O_DIAERESIS_BIG,
    O_CIRCUMFLEX_SMALL,
    O_CIRCUMFLEX_BIG,
    S_SHARP_SMALL,
    S_SHARP_BIG,
    SOFT_HYPHEN,
    NO_BREAK,
    N_DASH,
};

const uint32_t PROGMEM unicode_map[] = {
    [EURO]  = 0x20AC,  // €
    [A_ACUTE_SMALL] = 0x00E1, // á
    [A_ACUTE_BIG]   = 0x00C1, // Á
    [C_CARON_SMALL] = 0x010D, // č
    [C_CARON_BIG]   = 0x010C, // Č
    [D_CARON_SMALL] = 0x010F, // ď
    [D_CARON_BIG]   = 0x010E, // Ď
    [E_ACUTE_SMALL] = 0x00E9, // é
    [E_ACUTE_BIG]   = 0x00C9, // É
    [I_ACUTE_SMALL] = 0x00ED, // í
    [I_ACUTE_BIG]   = 0x00CD, // Í
    [L_CARON_SMALL] = 0x013E, // ľ
    [L_CARON_BIG]   = 0x013D, // Ľ
    [N_CARON_SMALL] = 0x0148, // ň
    [N_CARON_BIG]   = 0x0147, // Ň
    [O_ACUTE_SMALL] = 0x00F3, // ó
    [O_ACUTE_BIG]   = 0x00D3, // Ó
    [S_CARON_SMALL] = 0x0161, // š
    [S_CARON_BIG]   = 0x0160, // Š
    [T_CARON_SMALL] = 0x0165, // ť
    [T_CARON_BIG]   = 0x0164, // Ť
    [U_ACUTE_SMALL] = 0x00FA, // ú
    [U_ACUTE_BIG]   = 0x00DA, // Ú
    [Y_ACUTE_BIG]   = 0x00DD, // ý
    [Y_ACUTE_SMALL] = 0x00FD, // Ý
    [Z_CARON_SMALL] = 0x017E, // ž
    [Z_CARON_BIG]   = 0x017D, // Ž

    [A_DIAERESIS_SMALL]  = 0x00E4, // ä
    [A_DIAERESIS_BIG]    = 0x00C4, // Ä
    [U_DIAERESIS_SMALL]  = 0x00FC, // ü
    [U_DIAERESIS_BIG]    = 0x00DC, // Ü
    [O_DIAERESIS_SMALL]  = 0x00F6, // ö
    [O_DIAERESIS_BIG]    = 0x00D6, // Ö
    [O_CIRCUMFLEX_SMALL] = 0x00F3, // ó
    [O_CIRCUMFLEX_BIG]   = 0x00D4, // Ô
    [S_SHARP_SMALL]      = 0x00DF, // ß
    [S_SHARP_BIG]        = 0x1E9E, // ẞ
    [SOFT_HYPHEN]        = 0x00AD, // ­
    [NO_BREAK]           = 0x00A0, //  
    [N_DASH]             = 0x2013, // –
};

#define   KC_SYMBOLR_F    LT(_SYMBOLR,KC_F)
#define   KC_SYMBOLL_J    LT(_SYMBOLL,KC_J)
#define   KC_NAV_K        LT(_NAV,KC_K)
#define   KC_NUM_L        LT(_NUM,KC_L)
#define   KC_TMUX_NO      LT(_TMUX,KC_NO)
#define   KC_ESCAPE_SPC   LT(_ESCAPE,KC_SPC)
#define   KC_WM_NO        LT(_WM,KC_NO)
#define   KC_FKEYS_S      LT(_FKEYS,KC_S)
#define   KC_NVIM_D       LT(_NVIM,KC_D)
#define   KC_UNIR_V       LT(_UNIR,KC_V)
#define   KC_UNIL_M       LT(_UNIL,KC_M)

#define   KC_CTLR_X       LCTL_T(KC_X)
#define   KC_CTLR_DOT     LCTL_T(KC_DOT)

#define   KC_ALT_C        LALT_T(KC_C)
#define   KC_ALT_COMM     LALT_T(KC_COMM)

#define   KC_SHIFT_A      LSFT_T(KC_A)
#define   KC_SHIFT_SCLN   LSFT_T(KC_SCLN)

#define   KC_ALT_0   LALT(KC_0)
#define   KC_ALT_1   LALT(KC_1)
#define   KC_ALT_2   LALT(KC_2)
#define   KC_ALT_3   LALT(KC_3)
#define   KC_ALT_4   LALT(KC_4)
#define   KC_ALT_5   LALT(KC_5)
#define   KC_ALT_6   LALT(KC_6)
#define   KC_ALT_7   LALT(KC_7)
#define   KC_ALT_8   LALT(KC_8)
#define   KC_ALT_9   LALT(KC_9)

#define   KC_LOCK   LWIN(KC_L)
#define   DMENU     LALT(KC_BSPC)
#define   REGION    RCTL(KC_PRINT_SCREEN)
#define   CLR_PICK  LALT(KC_PRINT_SCREEN)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_Q          , KC_W       , KC_E          , KC_R         , KC_T , KC_Y , KC_U         , KC_I        , KC_O        , KC_P          ,
        KC_SHIFT_A    , KC_FKEYS_S , KC_NVIM_D     , KC_SYMBOLR_F , KC_G , KC_H , KC_SYMBOLL_J , KC_NAV_K    , KC_NUM_L    , KC_SHIFT_SCLN ,
        KC_Z          , KC_CTLR_X  , KC_ALT_C      , KC_UNIR_V    , KC_B , KC_N , KC_UNIL_M    , KC_ALT_COMM , KC_CTLR_DOT , KC_SLSH       ,
        KC_TMUX_NO    , KC_BSPC    , KC_ESCAPE_SPC , KC_WM_NO
    ),
    [_UNIL] = LAYOUT(
        // row 1
        _______,
        UP(L_CARON_SMALL, L_CARON_BIG),
        UP(S_CARON_SMALL, S_CARON_BIG),
        UP(C_CARON_SMALL, C_CARON_BIG),
        UP(U_ACUTE_SMALL, U_ACUTE_BIG),
        _______, _______, _______, _______, _______,

        // row 2
        UP(N_CARON_SMALL, N_CARON_BIG),
        UP(T_CARON_SMALL, T_CARON_BIG),
        UP(Z_CARON_SMALL, Z_CARON_BIG),
        UP(Y_ACUTE_SMALL, Y_ACUTE_BIG),
        UP(O_ACUTE_SMALL, O_ACUTE_BIG),
        _______, _______, _______, _______, _______,

        // row 3
        _______,
        UP(A_ACUTE_SMALL, A_ACUTE_BIG),
        UP(I_ACUTE_SMALL, I_ACUTE_BIG),
        UP(E_ACUTE_SMALL, E_ACUTE_BIG),
        UP(D_CARON_SMALL, D_CARON_BIG),
        _______, _______, _______, _______, _______,

        // row 4
        _______    , _______    , _______ , _______
    ),

    [_UNIR] = LAYOUT(
        // row 1
        _______, _______, _______, _______, _______,
        _______,
        UP(A_DIAERESIS_SMALL, A_DIAERESIS_BIG),
        UP(U_DIAERESIS_SMALL, U_DIAERESIS_BIG),
        UP(O_DIAERESIS_SMALL, O_DIAERESIS_BIG),
        _______,

        // row 2
        _______, _______, _______, _______, _______,
        _______,
        UM(SOFT_HYPHEN),
        UM(NO_BREAK),
        UM(N_DASH),
        _______,

        // row 3
        _______, _______, _______, _______, _______,
        _______,
        UP(O_CIRCUMFLEX_SMALL, O_CIRCUMFLEX_BIG),
        UP(S_SHARP_SMALL, S_SHARP_BIG),
        _______,
        _______,

        // row 4
        _______    , _______    , _______ , _______
    ),
    [_NAV] = LAYOUT(
        _______ , KC_HOME , KC_UP   , KC_END  , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , KC_LEFT , KC_DOWN , KC_RGHT , _______ , _______ , KC_LGUI , XXXXXXX , _______ , _______ ,
        _______ , KC_PGDN , _______ , KC_PGUP , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______
    ),
    [_NVIM] = LAYOUT(
        _______ , _______ , _______ , _______ , _______ , _______      , SS_NVIM_TREE , SS_NVIM_WU , SS_NVIM_GIT , SS_NVIM_WC ,
        _______ , _______ , XXXXXXX , _______ , _______ , SS_NVIM_SAVE , SS_NVIM_WL   , SS_NVIM_WD , SS_NVIM_WR  , _______    ,
        _______ , _______ , _______ , _______ , _______ , _______      , SS_NVIM_WS   , _______    , SS_NVIM_WV  , _______    ,
        _______ , _______ , _______ , _______
    ),
    [_SYMBOLR] = LAYOUT(
        _______ , _______ , _______ , _______ , _______ , _______ , KC_UNDS , KC_PIPE , KC_QUOT , UM(EURO),
        KC_CIRC , KC_ASTR , KC_AMPR , XXXXXXX , _______ , KC_HASH , KC_TILD , KC_SLSH , KC_DQUO , KC_DLR  ,
        _______ , _______ , _______ , _______ , _______ , _______ , KC_MINS , KC_BSLS , KC_GRV  , _______ ,
        _______ , _______ , _______ , _______
    ),
    [_SYMBOLL] = LAYOUT(
        _______ , KC_COLN , KC_LT   , KC_GT   , KC_SCLN , _______ , _______ , _______ , _______ , _______ ,
        KC_LCBR , KC_RCBR , KC_LPRN , KC_RPRN , KC_AT   , _______ , XXXXXXX , KC_EQL  , KC_PLUS , KC_PERC ,
        _______ , KC_EXLM , KC_LBRC , KC_RBRC , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______
    ),
    [_FKEYS] = LAYOUT(
        _______ , _______ , _______ , _______ , _______ , _______ , KC_F7 , KC_F8 , KC_F9 , KC_F10 ,
        _______ , XXXXXXX , _______ , _______ , _______ , _______ , KC_F4 , KC_F5 , KC_F6 , KC_F11 ,
        _______ , _______ , _______ , _______ , _______ , _______ , KC_F1 , KC_F2 , KC_F3 , KC_F12 ,
        _______ , _______ , _______ , _______
    ),
    [_NUM] = LAYOUT(
        KC_PSLS , KC_7    , KC_8    , KC_9    , KC_PPLS , _______ , _______ , _______ , _______ , _______ ,
        KC_PAST , KC_4    , KC_5    , KC_6    , KC_PMNS , _______ , _______ , _______ , XXXXXXX , _______ ,
        KC_0    , KC_1    , KC_2    , KC_3    , KC_PEQL , _______ , _______ , _______ , _______ , _______ ,
        KC_0    , _______ , _______ , _______
    ),
    [_ESCAPE] = LAYOUT(
        KC_CAPS , _______ , SS_TESC , KC_ESC  , _______ , REGION  , _______ , _______ , _______ , QK_BOOT ,
        CW_TOGG , _______ , KC_DEL  , KC_ENT  , DMENU   , CLR_PICK, _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , KC_TAB  , XXXXXXX , KC_LOCK
    ),
    [_WM] = LAYOUT(
        _______  , KC_ALT_7 , KC_ALT_8 , KC_ALT_9 , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______  , KC_ALT_4 , KC_ALT_5 , KC_ALT_6 , _______ , _______ , _______ , _______ , _______ , _______ ,
        KC_ALT_0 , KC_ALT_1 , KC_ALT_2 , KC_ALT_3 , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______  , _______  , _______  , XXXXXXX
    ),
    [_TMUX] = LAYOUT(
        _______ , _______ , _______ , _______ , _______ , _______   , SS_TMUX_7 , SS_TMUX_8 , SS_TMUX_9 , _______      ,
        _______ , _______ , _______ , _______ , _______ , SS_TMUX_O , SS_TMUX_4 , SS_TMUX_5 , SS_TMUX_6 , SS_TMUX_PERC ,
        _______ , _______ , _______ , _______ , _______ , _______   , SS_TMUX_1 , SS_TMUX_2 , SS_TMUX_3 , _______      ,
        XXXXXXX , _______ , _______ , _______
    ),
};
