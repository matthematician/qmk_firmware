#include "tada68.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1 // Default TADA Fn layer
#define _TL 2 // TeX layer
#define _GL 3 // Greek layer
#define _UGL 4 // Upper Greek layer = Grk + Shift
#define _CL 5 // Calligraphic layer = Grk + TeX
#define _KL 6 // Fraktur layer = Grk + TeX + Shift

/* Ideas for more functionality: 
 * Tap dances on shifts for common \begin and \end environments
 */

#define _______ KC_TRNS

/* Macrodefs for TeX Layer */
#define BBQ 0
#define CAP 1
#define CUP 2
#define BBR 3
#define IN 4
#define SUB 5
#define SEQ 6
#define INF 7
#define FAL 8
#define EXI 9
#define LAN 10
#define RAN 11
#define SQR 12
#define INT 13
#define SUM 14
#define DEL 15
#define NAB 16
#define LAR 17
#define IFF 18
#define RAR 19
#define TOO 20
#define ELL 21
#define BBZ 22
#define TMS 23
#define BBC 24
#define CDT 25
#define BOX 26
#define BBN 27
#define ANG 28
#define LEQ 29
#define GEQ 30
#define NEQ 150
#define PM 151
#define FRAC 160
#define ENUM 161
#define ITEM 162
#define TABU 163
#define ARAY 164

/* Macrodefs for Greek layer, based on MS Symbol font */

#define THETA 31
#define OMEGA 32
#define EPSILON 33
#define RHO 34
#define TAU 35
#define PSI 36
#define UPSILON 37
#define IOTA 38
#define OMICRON 39
#define PI 40
#define ALPHA 41
#define SIGMA 42
#define DELTA 43
#define PHI 44
#define GAMMA 45
#define ETA 46
#define VARPHI 47
#define KAPPA 48
#define LAMBDA 49
#define ZETA 50
#define XI 51
#define CHI 152
#define VAROMEGA 52
#define BETA 53
#define NU 54
#define MOO 55
#define BANNER 171

/* Uppercase Greek Layer */

#define THETX 56
#define OMEGX 57
#define EPSILOX 58
#define RHX 59
#define TAX 60
#define PSX 61
#define UPSILOX 62
#define IOTX 63
#define OMICROX 64
#define PX 65
#define ALPHX 66
#define SIGMX 67
#define DELTX 68
#define PHX 69
#define GAMMX 70
#define ETX 71
#define VARPHX 72
#define KAPPX 73
#define LAMBDX 74
#define ZETX 75
#define XX 76
#define CHX 153
#define VAROMEGX 77
#define BETX 78
#define NX 79
#define MX 80

/* Calligraphic layer (all uppercase) */

#define CALQ 81
#define CALW 82
#define CALE 83
#define CALR 84
#define CALT 85
#define CALY 86
#define CALU 87
#define CALI 88
#define CALO 89
#define CALP 90
#define CALA 91
#define CALS 92
#define CALD 93
#define CALF 94
#define CALG 95
#define CALH 96
#define CALJ 97
#define CALK 98
#define CALL 99
#define CALZ 100
#define CALX 101
#define CALC 102
#define CALV 103
#define CALB 104
#define CALN 105
#define CALM 106

/* Fraktur layer (all lowercase) */


#define FRKQ 107
#define FRKW 108
#define FRKE 109
#define FRKR 110
#define FRKT 111
#define FRKY 112
#define FRKU 113
#define FRKI 114
#define FRKO 115
#define FRKP 116
#define FRKA 117
#define FRKS 118
#define FRKD 119
#define FRKF 120
#define FRKG 121
#define FRKH 122
#define FRKJ 123
#define FRKK 124
#define FRKL 125
#define FRKZ 126
#define FRKX 127
#define FRKC 128
#define FRKV 129
#define FRKB 130
#define FRKN 131
#define FRKM 132
#define FRKNO 133
#define FRKNU 134
#define EQN 135

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Math Cadet Layer
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * | CAPS  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |TeX |Opt |Cmd |        Space          |Grk|Ctrl|Fn |Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_BL] = KEYMAP_ANSI(
  KC_ESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC,KC_GRV, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS,KC_DEL, \
  KC_CAPS, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,KC_PGUP,  \
  KC_LSPO,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSPC,KC_UP,KC_PGDN, \
  MO(_TL), KC_LALT,KC_LGUI,                KC_SPC,                        MO(_GL),KC_RCTL,MO(_FL), KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap _FL: Function Layer. This is same as TADA68 default.
   * ,----------------------------------------------------------------.
   * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins |
   * |----------------------------------------------------------------|
   * |     |   |Up |   |   |   |   |   |   |   |   |   |   |     |Hme |
   * |----------------------------------------------------------------|
   * |      |<- |Dn | ->|   |   |   |   |   |   |   |   |        |End |
   * |----------------------------------------------------------------|
   * |        |   |   |Bl-|BL |BL+|   |VU-|VU+|MUT|   |  MUT |VU+|PLY |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |REW|VU-|FFW |
   * `----------------------------------------------------------------'
   */
[_FL] = KEYMAP_ANSI(
  _______, KC_F1 ,KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_INS ,  \
  _______,_______, KC_UP,_______,_______, _______,_______,_______,_______,_______,_______,_______,_______, _______,KC_HOME, \
  _______,KC_LEFT,KC_DOWN,KC_RIGHT,_______,_______,_______,_______,_______,_______,_______,_______,        _______,KC_END, \
  _______,_______,_______,BL_DEC, BL_TOGG,BL_INC, _______,KC_VOLD,KC_VOLU,KC_MUTE,_______,KC_MUTE, KC_VOLU, KC_MPLY, \
  _______,_______,_______,                 _______,               _______,_______,_______,KC_MRWD,KC_VOLD, KC_MFFD),

  /* Keymap _TL: TeX Layer. This provides functionality printed on alpha keys.
   * ,----------------------------------------------------------------.
   * |   |enm|ary|   |   |   |   |   |   |   |itm|neq|pm |       |    |
   * |----------------------------------------------------------------|
   * | tabu|bbQ|cap|cup|bbR|in |sub|seq|inf|fal|exi|lan|ran|sqrt |    |
   * |----------------------------------------------------------------|
   * |      |int|sum|del|nab|Lar|LRa|Rar|to |ell|   |   |        |    |
   * |----------------------------------------------------------------|
   * |        |bbZ|tms|bbC|cdt|box|bbN|ang|leq|geq|frc|      |   |    |
   * |----------------------------------------------------------------|
   * |    |    |    |       \[ \]           |   |   |    |   |   |    |
   * `----------------------------------------------------------------'
   */

[_TL] = KEYMAP_ANSI(
  _______,    M(ENUM),   M(ARAY),   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   M(ITEM),   M(NEQ), M(PM), KC_NO,KC_NO, \
  M(TABU),  M(BBQ),   M(CAP),   M(CUP),   M(BBR),   M(IN),   M(SUB),   M(SEQ),   M(INF),   M(FAL),   M(EXI),   M(LAN), M(RAN), M(SQR),KC_NO, \
  KC_NO, M(INT),   M(SUM),   M(DEL),   M(NAB),   M(LAR),   M(IFF),   M(RAR),   M(TOO),   M(ELL),   KC_NO,KC_NO,         KC_NO,KC_NO,  \
  KC_NO,         M(BBZ),   M(TMS),   M(BBC),   M(CDT),   M(BOX),   M(BBN),   M(ANG),   M(LEQ),M(GEQ), M(FRAC),   KC_NO,KC_NO,KC_NO, \
  _______, KC_NO,KC_NO,                M(EQN) ,                    MO(_CL),_______,_______, KC_NO,KC_NO,KC_NO),

  /* Keymap _GL: (Greek Layer)
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|BID|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Opt |Cmd |        Space          |TeX|Grk| Fn |Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_GL] = KEYMAP_ANSI(
  _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, _______, _______,_______, \
  _______,  M(THETA),   M(OMEGA),   M(EPSILON),   M(RHO),   M(TAU),   M(PSI),   M(UPSILON),   M(IOTA),   M(OMICRON),   M(PI), _______, _______,_______,_______, \
  _______, M(ALPHA),   M(SIGMA),   M(DELTA),   M(PHI),   M(GAMMA),   M(ETA),  M(VARPHI),   M(KAPPA),   M(LAMBDA), _______ , _______,  _______ ,_______,  \
  MO(_UGL),         M(ZETA),   M(XI),   M(CHI),   M(VAROMEGA),   M(BETA),   M(NU),   M(MOO),   _______,_______, M(BANNER),   MO(_UGL),_______,_______, \
  _______, _______,_______,                _______,                      _______, _______,KC_NO, _______,_______,_______),

  /* Keymap _UGL: (Upper Greek Layer)
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Opt |Cmd |        Space          |TeX|Grk| Fn |Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */

[_UGL] = KEYMAP_ANSI(
  _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, _______, _______,_______, \
  _______,  M(THETX),   M(OMEGX),   M(EPSILOX),   M(RHX),   M(TAX),   M(PSX),   M(UPSILOX),   M(IOTX),   M(OMICROX),   M(PX), _______, _______,_______,_______, \
 _______, M(ALPHX),   M(SIGMX),   M(DELTX),   M(PHX),   M(GAMMX),   M(ETX),  M(VARPHX),   M(KAPPX),   M(LAMBDX), _______ , _______,  _______ ,_______,  \
  _______ ,         M(ZETX),   M(XX),   M(CHX),   M(VAROMEGX),   M(BETX),   M(NX),   M(MX),   _______,_______, _______, _______ ,_______,_______, \
  MO(_KL), _______,_______,                _______,                    _______ ,_______,KC_NO, _______,_______,_______),

  /* Keymap _CL: (Calligraphic Layer)
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Opt |Cmd |        Space          |TeX|Grk| Fn |Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */


[_CL] = KEYMAP_ANSI(
  _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, _______, _______,_______, \
  _______,  M(CALQ),   M(CALW),   M(CALE),   M(CALR),   M(CALT),   M(CALY),   M(CALU),   M(CALI),   M(CALO),   M(CALP),   _______, _______,_______,_______, \
  _______, M(CALA),   M(CALS),   M(CALD),   M(CALF),   M(CALG),   M(CALH),   M(CALJ),   M(CALK),   M(CALL), _______ , _______,    _______, _______,  \
 MO(_KL),   M(CALZ),   M(CALX),   M(CALC),   M(CALV),   M(CALB),   M(CALN),   M(CALM), _______, _______, _______, MO(_KL), _______,_______, \
  _______, _______,_______,   _______,                    _______ , _______,_______, _______, _______, _______),

  /* Keymap _KL: (Fraktur Layer)
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Opt |Cmd |        Space          |TeX|Grk| Fn |Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_KL] = KEYMAP_ANSI(
  _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, _______, _______,_______, \
  _______,  M(FRKQ),   M(FRKW),   M(FRKE),   M(FRKR),   M(FRKT),   M(FRKY),   M(FRKU),   M(FRKI),   M(FRKO),   M(FRKP),   _______, _______,_______,_______, \
  _______, M(FRKA),   M(FRKS),   M(FRKD),   M(FRKF),   M(FRKG),   M(FRKH),   M(FRKJ),   M(FRKK),   M(FRKL), _______ , _______,    _______, _______,  \
 _______,   M(FRKZ),   M(FRKX),   M(FRKC),   M(FRKV),   M(FRKB),   M(FRKN),   M(FRKM), _______, _______, _______, _______, _______,_______, \
  _______, _______,_______,   _______,                    _______ , _______,_______, _______, _______, _______),
};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (record->event.pressed) {
        switch(id) {
	    case BANNER:
		SEND_STRING("00276541\t714285");
		return MACRO(T(ENTER),END);		
	    case EQN:
		return MACRO(T(BSLS), T(LBRC), T(SPC), T(BSLS), T(RBRC), T(LEFT), T(LEFT), T(LEFT), END);
            case FRAC:
		SEND_STRING("\\frac{}{}");
		return MACRO(T(LEFT), T(LEFT), T(LEFT),END);
	    case ENUM:
		SEND_STRING("\\begin{enumerate}\n  \\item\n\\end{enumerate}");
		return MACRO(T(UP),END);
	    case ITEM:
		SEND_STRING("\\begin{itemize}\n  \\item\n\\end{itemize}");
		return MACRO(T(UP),END);
	    case ARAY:
		SEND_STRING("\\begin{array}{}\n\\end{array}");
		return MACRO(T(UP), D(LGUI), T(RIGHT), U(LGUI), T(LEFT), END);
	    case TABU:
		SEND_STRING("\\begin{tabular}{}\n\\end{tabular}");
		return MACRO(T(UP), D(LGUI), T(RIGHT), U(LGUI), T(LEFT), END);
	    case BBQ:
                SEND_STRING("\\mathbb{Q}");
                return false;
            case CAP:
                SEND_STRING("\\cap");
                return false;
            case CUP:
                SEND_STRING("\\cup");
                return false;
            case BBR:
                SEND_STRING("\\mathbb{R}");
                return false;
            case IN:
                SEND_STRING("\\in");
                return false;
            case SUB:
                SEND_STRING("\\subset");
                return false;
            case SEQ:
                SEND_STRING("\\subseteq");
                return false;
            case INF:
                SEND_STRING("\\infty");
                return false;
            case FAL:
                SEND_STRING("\\forall");
                return false;
            case EXI:
                SEND_STRING("\\exists");
                return false;
            case LAN:
                SEND_STRING("\\langle");
                return false;
            case RAN:
                SEND_STRING("\\rangle");
                return false;
            case SQR:
                SEND_STRING("\\sqrt{");
                return false;
            case INT:
                SEND_STRING("\\int");
                return false;
            case SUM:
                SEND_STRING("\\sum");
                return false;
            case DEL:
                SEND_STRING("\\partial");
                return false;
            case NAB:
                SEND_STRING("\\nabla");
                return false;
            case LAR:
                SEND_STRING("\\Leftarrow");
                return false;
            case IFF:
                SEND_STRING("\\Leftrightarrow");
                return false;
            case RAR:
                SEND_STRING("\\Rightarrow");
                return false;
            case TOO:
                SEND_STRING("\\to");
                return false;
            case ELL:
                SEND_STRING("\\ell");
                return false;
            case BBZ:
                SEND_STRING("\\mathbb{Z}");
                return false;
            case TMS:
                SEND_STRING("\\times");
                return false;
            case BBC:
                SEND_STRING("\\mathbb{C}");
                return false;
            case CDT:
                SEND_STRING("\\cdot");
                return false;
            case BOX:
                SEND_STRING("\\square");
                return false;
            case BBN:
                SEND_STRING("\\mathbb{N}");
                return false;
            case ANG:
                SEND_STRING("\\angle");
                return false;
            case LEQ:
                SEND_STRING("\\leq");
                return false;
            case GEQ:
                SEND_STRING("\\geq");
                return false;
            case NEQ:
                SEND_STRING("\\neq");
                return false;
            case PM:
                SEND_STRING("\\pm");
                return false;
            case THETA:
                SEND_STRING("\\theta");
                return false;
            case OMEGA:
                SEND_STRING("\\omega");
                return false;
            case EPSILON:
                SEND_STRING("\\epsilon");
                return false;
            case RHO:
                SEND_STRING("\\rho");
                return false;
            case TAU:
                SEND_STRING("\\tau");
                return false;
            case PSI:
                SEND_STRING("\\psi");
                return false;
            case UPSILON:
                SEND_STRING("\\upsilon");
                return false;
            case IOTA:
                SEND_STRING("\\iota");
                return false;
            case OMICRON:
                SEND_STRING("\\omicron");
                return false;
            case PI:
                SEND_STRING("\\pi");
                return false;
            case ALPHA:
                SEND_STRING("\\alpha");
                return false;
            case SIGMA:
                SEND_STRING("\\sigma");
                return false;
            case DELTA:
                SEND_STRING("\\delta");
                return false;
            case PHI:
                SEND_STRING("\\phi");
                return false;
            case GAMMA:
                SEND_STRING("\\gamma");
                return false;
            case ETA:
                SEND_STRING("\\eta");
                return false;
            case VARPHI:
                SEND_STRING("\\varphi");
                return false;
            case KAPPA:
                SEND_STRING("\\kappa");
                return false;
            case LAMBDA:
                SEND_STRING("\\lambda");
                return false;
            case ZETA:
                SEND_STRING("\\zeta");
                return false;
            case XI:
                SEND_STRING("\\xi");
                return false;
            case CHI:
                SEND_STRING("\\chi");
                return false;
            case VAROMEGA:
                SEND_STRING("\\varpi");
                return false;
            case BETA:
                SEND_STRING("\\beta");
                return false;
            case NU:
                SEND_STRING("\\nu");
                return false;
            case MOO:
                SEND_STRING("\\mu");
                return false;
            case THETX:
                SEND_STRING("\\Theta");
                return false;
            case OMEGX:
                SEND_STRING("\\Omega");
                return false;
            case EPSILOX:
                SEND_STRING("E");
                return false;
            case RHX:
                SEND_STRING("R");
                return false;
            case TAX:
                SEND_STRING("T");
                return false;
            case PSX:
                SEND_STRING("\\Psi");
                return false;
            case UPSILOX:
                SEND_STRING("\\Upsilon");
                return false;
            case IOTX:
                SEND_STRING("I");
                return false;
            case OMICROX:
                SEND_STRING("O");
                return false;
            case PX:
                SEND_STRING("\\Pi");
                return false;
            case ALPHX:
                SEND_STRING("A");
                return false;
            case SIGMX:
                SEND_STRING("\\Sigma");
                return false;
            case DELTX:
                SEND_STRING("\\Delta");
                return false;
            case PHX:
                SEND_STRING("\\Phi");
                return false;
            case GAMMX:
                SEND_STRING("\\Gamma");
                return false;
            case ETX:
                SEND_STRING("H");
                return false;
            case VARPHX:
                SEND_STRING("\\Phi");
                return false;
            case KAPPX:
                SEND_STRING("K");
                return false;
            case LAMBDX:
                SEND_STRING("\\Lambda");
                return false;
            case ZETX:
                SEND_STRING("Z");
                return false;
            case XX:
                SEND_STRING("\\Xi");
                return false;
            case CHX:
                SEND_STRING("X");
                return false;
            case VAROMEGX:
                SEND_STRING("\\Pi");
                return false;
            case BETX:
                SEND_STRING("B");
                return false;
            case NX:
                SEND_STRING("N");
                return false;
            case MX:
                SEND_STRING("M");
                return false;
            case CALQ:
                SEND_STRING("\\mathcal{Q}");
                return false;
            case CALW:
                SEND_STRING("\\mathcal{W}");
                return false;
            case CALE:
                SEND_STRING("\\mathcal{E}");
                return false;
            case CALR:
                SEND_STRING("\\mathcal{R}");
                return false;
            case CALT:
                SEND_STRING("\\mathcal{T}");
                return false;
            case CALY:
                SEND_STRING("\\mathcal{Y}");
                return false;
            case CALU:
                SEND_STRING("\\mathcal{U}");
                return false;
            case CALI:
                SEND_STRING("\\mathcal{I}");
                return false;
            case CALO:
                SEND_STRING("\\mathcal{O}");
                return false;
            case CALP:
                SEND_STRING("\\mathcal{P}");
                return false;
            case CALA:
                SEND_STRING("\\mathcal{A}");
                return false;
            case CALS:
                SEND_STRING("\\mathcal{S}");
                return false;
            case CALD:
                SEND_STRING("\\mathcal{D}");
                return false;
            case CALF:
                SEND_STRING("\\mathcal{F}");
                return false;
            case CALG:
                SEND_STRING("\\mathcal{G}");
                return false;
            case CALH:
                SEND_STRING("\\mathcal{H}");
                return false;
            case CALJ:
                SEND_STRING("\\mathcal{J}");
                return false;
            case CALK:
                SEND_STRING("\\mathcal{K}");
                return false;
            case CALL:
                SEND_STRING("\\mathcal{L}");
                return false;
            case CALZ:
                SEND_STRING("\\mathcal{Z}");
                return false;
            case CALX:
                SEND_STRING("\\mathcal{X}");
                return false;
            case CALC:
                SEND_STRING("\\mathcal{C}");
                return false;
            case CALV:
                SEND_STRING("\\mathcal{V}");
                return false;
            case CALB:
                SEND_STRING("\\mathcal{B}");
                return false;
            case CALN:
                SEND_STRING("\\mathcal{N}");
                return false;
            case CALM:
                SEND_STRING("\\mathcal{M}");
                return false;
            case FRKQ:
                SEND_STRING("\\mathfrak{q}");
                return false;
            case FRKW:
                SEND_STRING("\\mathfrak{w}");
                return false;
            case FRKE:
                SEND_STRING("\\mathfrak{e}");
                return false;
            case FRKR:
                SEND_STRING("\\mathfrak{r}");
                return false;
            case FRKT:
                SEND_STRING("\\mathfrak{t}");
                return false;
            case FRKY:
                SEND_STRING("\\mathfrak{y}");
                return false;
            case FRKU:
                SEND_STRING("\\mathfrak{u}");
                return false;
            case FRKI:
                SEND_STRING("\\mathfrak{i}");
                return false;
            case FRKO:
                SEND_STRING("\\mathfrak{o}");
                return false;
            case FRKP:
                SEND_STRING("\\mathfrak{p}");
                return false;
            case FRKA:
                SEND_STRING("\\mathfrak{a}");
                return false;
            case FRKS:
                SEND_STRING("\\mathfrak{s}");
                return false;
            case FRKD:
                SEND_STRING("\\mathfrak{d}");
                return false;
            case FRKF:
                SEND_STRING("\\mathfrak{f}");
                return false;
            case FRKG:
                SEND_STRING("\\mathfrak{g}");
                return false;
            case FRKH:
                SEND_STRING("\\mathfrak{h}");
                return false;
            case FRKJ:
                SEND_STRING("\\mathfrak{j}");
                return false;
            case FRKK:
                SEND_STRING("\\mathfrak{k}");
                return false;
            case FRKL:
                SEND_STRING("\\mathfrak{l}");
                return false;
            case FRKZ:
                SEND_STRING("\\mathfrak{z}");
                return false;
            case FRKX:
                SEND_STRING("\\mathfrak{x}");
                return false;
            case FRKC:
                SEND_STRING("\\mathfrak{c}");
                return false;
            case FRKV:
                SEND_STRING("\\mathfrak{v}");
                return false;
            case FRKB:
                SEND_STRING("\\mathfrak{b}");
                return false;
            case FRKN:
                SEND_STRING("\\mathfrak{n}");
                return false;
            case FRKM:
                SEND_STRING("\\mathfrak{m}");
                return false;

        }
    }
    return MACRO_NONE;
};
