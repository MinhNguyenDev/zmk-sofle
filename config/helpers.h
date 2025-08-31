#define TAPPING_TERM 250
#define QUICK_TAP_TERM 175
    /*  TAP HOLDS  */

    #define TAPHOLD_TP(NAME, TAP, HOLD) \
         NAME: NAME { \
            compatible = "zmk,behavior-hold-tap"; \
            flavor = "hold-preferred"; \
            #binding-cells = <2>; \
            tapping-term-ms = <TAPPING_TERM>; \
            quick-tap-ms = <QUICK_TAP_TERM>; \            
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


