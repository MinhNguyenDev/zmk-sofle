    /* LAYER TAPS */    

    #define LAYERTAP_TP(NAME, BINDINGS) \
         NAME: NAME { \
            compatible = "zmk,behavior-hold-tap"; \
            flavor = "tap-preferred"; \
            #binding-cells = <2>; \
            tapping-term-ms = <TAPPING_TERM>; \
            quick-tap-ms = <QUICK_TAP_TERM>; \
            bindings = <&mo>, <BINDINGS>; \
        };
    
    #define LAYERTAP_HP(NAME, BINDINGS) \
         NAME: NAME { \
            compatible = "zmk,behavior-hold-tap"; \
            flavor = "hold-preferred"; \
            #binding-cells = <2>; \
            tapping-term-ms = <TAPPING_TERM>; \
            quick-tap-ms = <QUICK_TAP_TERM>; \
            bindings = <&mo>, <BINDINGS>; \
        };


    /*  MOD TAPS  */

    #define MODTAP_TP(NAME, BINDINGS) \
         NAME: NAME { \
            compatible = "zmk,behavior-hold-tap"; \
            flavor = "tap-preferred"; \
            #binding-cells = <2>; \
            tapping-term-ms = <TAPPING_TERM>; \
            quick-tap-ms = <QUICK_TAP_TERM>; \
            require-prior-idle-ms = <QUICK_TAP_TERM>; \
            bindings = <&kp>, <BINDINGS>; \
        };

    /*  TAP HOLDS  */

    #define TAPHOLD_TP(NAME, TAP, HOLD) \
         NAME: NAME { \
            compatible = "zmk,behavior-hold-tap"; \
            flavor = "tap-preferred"; \
            #binding-cells = <2>; \
            tapping-term-ms = <TAPPING_TERM>; \
            quick-tap-ms = <QUICK_TAP_TERM>; \
            require-prior-idle-ms = <QUICK_TAP_TERM>; \
            bindings = <HOLD>, <TAP>; \
        };

    /*  MACROS  */
    
    #define MACRO(NAME, BINDINGS) \
        NAME: NAME { \
			compatible = "zmk,behavior-macro"; \
            #binding-cells = <0>; \
            wait-ms = <5>; \
            tap-ms = <5>; \
            bindings = <BINDINGS>; \
        };

    /*  MOD MORPHS  */

    #define MOD_MORPH(NAME, MODS, MODDED, UNMODDED) \
        NAME: NAME { \
            compatible = "zmk,behavior-mod-morph"; \
            #binding-cells = <0>; \
            bindings = <UNMODDED>, <MODDED>; \
            mods = <(MODS)>; \
        };

    #define MOD_MORPH_KM(NAME, MODS, MODDED, UNMODDED) \
        NAME: NAME { \
            compatible = "zmk,behavior-mod-morph"; \
            #binding-cells = <0>; \
            bindings = <UNMODDED>, <MODDED>; \
            mods = <(MODS)>; \
            keep-mods = <(MODS)>; \
        };

    /*  SHIFT_MORPH  */

    #define SHIFT_MORPH(NAME, UNSHIFTED, SHIFTED) \
        NAME: NAME { \
            compatible = "zmk,behavior-mod-morph"; \
            #binding-cells = <0>; \
            bindings = <UNSHIFTED>, <SHIFTED>; \
            mods = <(MOD_LSFT|MOD_RSFT)>; \
        };

    /*  ACCENTS  */
    
    #define ACCENT(NAME, KEY, DEAD_KEY) \
        NAME: NAME { \
            wait-ms = <0>; \
            tap-ms = <0>; \
            compatible = "zmk,behavior-macro"; \
            #binding-cells = <0>; \
            bindings \
                = <&macro_tap &kp DEAD_KEY> \
                , <&macro_tap &kp KEY> \
                , <&macro_tap &sl ALTREP2> \
                ; \
        }; \
        NAME##_c: NAME##_c { \
            wait-ms = <0>; \
            tap-ms = <0>; \
            compatible = "zmk,behavior-macro"; \
            #binding-cells = <0>; \
            bindings \
                = <&macro_release &kp LSHIFT &kp RSHFT> \
                , <&macro_tap &kp DEAD_KEY> \
                , <&macro_press &kp RSHFT> \
                , <&macro_tap &kp KEY> \
                , <&macro_release &kp RSHFT> \
                , <&macro_tap &sl ALTREP2> \
                ; \
        }; \
        NAME##_s: NAME##_s { \
            wait-ms = <0>; \
            tap-ms = <0>; \
            compatible = "zmk,behavior-macro"; \
            #binding-cells = <0>; \
            bindings \
                = <&macro_release &kp LSHFT &kp RSHFT> \
                , <&macro_tap &kp DEAD_KEY> \
                , <&macro_press &kp LSHFT> \
                , <&macro_tap &kp KEY> \
                , <&macro_release &kp LSHFT> \
                , <&macro_tap &sl ALTREP2> \
                ; \
        };

    /*  COMBOS  */
    
    #define COMBO(NAME, KEYS, BINDINGS, LAYERS) \
        NAME { \
            timeout-ms = <COMBO_TERM>; \
            layers = <LAYERS>; \
            key-positions = <KEYS>; \
            bindings = <BINDINGS>; \
        };    

    #define ADAPTIVE(NAME, BINDINGS, TRIGGERS) \
        magic_##NAME: magic_##NAME { \
            trigger-keys = <TRIGGERS>; \
            bindings = <BINDINGS>; \
            max-prior-idle-ms = <ADAPTIVE_KEY_TIMEOUT>; \
            strict-modifiers; \
        };

    /*  END  */

MACRO(mc_lalt, &macro_tap &kp LALT)
TAPHOLD_TP(th_leader_alt, &leader, &mc_lalt)    