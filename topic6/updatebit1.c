#include <stdio.h>
#include <stdlib.h>

void change_bits_h (
    unsigned char out_bit,
    unsigned char *out_var,
    unsigned char input_mask,
    unsigned char input_var
) {
    unsigned char output_mask = (1 << out_bit);

    if ( (input_var & input_mask) == input_mask ) {
        (*out_var) |= output_mask;
    } else {
        (*out_var) &= ~output_mask;
    }
}

unsigned char input_var_01, out_var_01;
unsigned char input_var_02, out_var_02;
unsigned char input_var_03, out_var_03;
unsigned char input_var_04, out_var_04;
unsigned char input_var_05, out_var_05;
unsigned char input_var_06, out_var_06;
unsigned char input_var_07, out_var_07;
unsigned char input_var_08, out_var_08;
unsigned char input_var_09, out_var_09;
unsigned char input_var_10, out_var_10;

void change_bits () {
    change_bits_h( 3, &out_var_01, (1 << 0), input_var_01 );
    change_bits_h( 1, &out_var_02, (1 << 1),  input_var_02 );
    change_bits_h( 6, &out_var_03, (1 << 0) | (1 << 7), input_var_03 );
    change_bits_h( 4, &out_var_04, (1 << 2) | (1 << 4), input_var_04 );
    change_bits_h( 3, &out_var_05, (1 << 0) | (1 << 1) | (1 << 7), input_var_05 );
    change_bits_h( 3, &out_var_06, (1 << 3) | (1 << 6) | (1 << 7), input_var_06 );
    change_bits_h( 7, &out_var_07, (1 << 0) | (1 << 1) | (1 << 2) | (1 << 7), input_var_07 );
    change_bits_h( 3, &out_var_08, (1 << 1) | (1 << 3) | (1 << 4) | (1 << 5), input_var_08 );
    change_bits_h( 4, &out_var_09, (1 << 0) | (1 << 1) | (1 << 4) | (1 << 5) | (1 << 6), input_var_09 );
    change_bits_h( 4, &out_var_10, (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 6), input_var_10 );
}


void print_bits( const char * label, unsigned char val){
    printf("%s bits = {", label);
    
    int deja = 0;

    for (int i = 0; i <= 7; i++) {
        if ( (val & (1 << i)) ) {
            printf("%s%d", (deja ? ", " : ""), i);
            deja = 1;
        }
    }

    printf("}\n");
}

int main(int argc, char * argv[]) {
    unsigned char init_val = 0;
    unsigned char out_init = 0;
    
    if (argc > 1) init_val = atoi(argv[1]) & 255;
    if (argc > 2) out_init = atoi(argv[2]) & 255;

    input_var_01 = init_val;
    out_var_01 = out_init;

    input_var_02 = init_val;
    out_var_02 = out_init;

    input_var_03 = init_val;
    out_var_03 = out_init;

    input_var_04 = init_val;
    out_var_04 = out_init;

    input_var_05 = init_val;
    out_var_05 = out_init;

    input_var_06 = init_val;
    out_var_06 = out_init;

    input_var_07 = init_val;
    out_var_07 = out_init;

    input_var_08 = init_val;
    out_var_08 = out_init;

    input_var_09 = init_val;
    out_var_09 = out_init;

    input_var_10 = init_val;
    out_var_10 = out_init;

    change_bits();

    print_bits("Input Value         ", init_val);
    print_bits("Initial output Value", out_init);

    printf("\nSearch for bit 0.\n");
    printf("Set or clear bit 3:\n");
    print_bits("out_var_01", out_var_01);

    printf("\nSearch for bit 1.\n");
    printf("Set or clear bit 1:\n");
    print_bits("out_var_02", out_var_02);

    printf("\nSearch for bits 0, 7.\n");
    printf("Set or clear bit 6:\n");
    print_bits("out_var_03", out_var_03);

    printf("\nSearch for bits 2, 4.\n");
    printf("Set or clear bit 4:\n");
    print_bits("out_var_04", out_var_04);

    printf("\nSearch for bits 0, 1, 7.\n");
    printf("Set or clear bit 3:\n");
    print_bits("out_var_05", out_var_05);

    printf("\nSearch for bits 3, 6, 7.\n");
    printf("Set or clear bit 3:\n");
    print_bits("out_var_06", out_var_06);

    printf("\nSearch for bits 0, 1, 2, 7.\n");
    printf("Set or clear bit 7:\n");
    print_bits("out_var_07", out_var_07);

    printf("\nSearch for bits 1, 3, 4, 5.\n");
    printf("Set or clear bit 3:\n");
    print_bits("out_var_08", out_var_08);

    printf("\nSearch for bits 0, 1, 4, 5, 6.\n");
    printf("Set or clear bit 4:\n");
    print_bits("out_var_09", out_var_09);

    printf("\nSearch for bits 1, 2, 3, 4, 6.\n");
    printf("Set or clear bit 4:\n");
    print_bits("out_var_10", out_var_10);

    return 0;
}
