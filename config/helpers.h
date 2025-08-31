
    /*  TAP HOLDS  */

    #define TAPHOLD_TP(NAME, TAP, HOLD) \
         NAME: NAME { \
            compatible = "zmk,behavior-hold-tap"; \
            flavor = "hold-preferred"; \
            #binding-cells = <2>; \
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


